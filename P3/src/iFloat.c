#include "Debug.h"
#include "iFloat.h"

/** @file iFloat.c
 *  @brief You will modify this file and implement nine functions
 *  @details Your implementation of the functions defined in iFloat.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 *  <p>
 *  @author <b>Your name</b> goes here
 */

/* declaration for useful function contained in testFloat.c */
const char* getBinary (iFloat_t value);

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetSign (iFloat_t x) 
{
  int mask = 0x8000;
  return ((x & mask) >> 15); /* implement this */
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetExp (iFloat_t x) 
{
  int mask = 0x7C00;
  return ((x & mask)>>10); /* implement this */
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetVal (iFloat_t x) 
{
  int manMask = 0x03FF;
  int implicit = 0x0400;
  iFloat_t mantis = ((x & manMask) | implicit);

  if(floatGetSign(x) == 1)
  {
    return ((~mantis) + 1);
  }
  
  return mantis;
}

/** @todo Implement based on documentation contained in iFloat.h */
void floatGetAll(iFloat_t x, iFloat_t* sign, iFloat_t*exp, iFloat_t* val) 
{
  *sign = floatGetSign(x);
  *exp = floatGetExp(x);
  *val = floatGetVal(x);
  return;
}


//PART B
/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatLeftMost1 (iFloat_t bits) 
{
  if (bits == 0)
    return -1;

  int lPosition;
  int mask = 1;

  for(int i = 0; i > 16; i++)
  {
    if((mask & bits) != 0)
    {
      lPosition = i;
    }
    mask += mask;
  }
  
  return lPosition;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAbs (iFloat_t x) 
{
  return (x & 0x7FFF);
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatNegate (iFloat_t x) 
{
  if( x == 0)
    return x;
  return (x ^ 0x8000);
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAdd (iFloat_t x, iFloat_t y) 
{
  iFloat_t xSign = 0;
  iFloat_t xExp = 0;
  iFloat_t xVal = 0;

  iFloat_t ySign = 0;
  iFloat_t yExp = 0;
  iFloat_t yVal = 0;

  floatGetAll(x, &xSign, &xExp, &xVal);
  floatGetAll(y, &ySign, &yExp, &yVal);

  iFloat_t eqExp;
  
  if( xExp > yExp )         //find exponent difference & shift smaller mantis by difference
  {
    eqExp = xExp - yExp;
    yVal = yVal >> eqExp;
    yExp = xExp;
  }
  if( yExp > xExp )
  {
    eqExp = yExp - xExp;
    xVal = xVal >> eqExp;
    xExp = yExp;
  }
  

  iFloat_t tExp = xExp;
  iFloat_t tVal = xVal + yVal;   //find total of the mantis
  iFloat_t tSign = floatGetSign(tVal);
          

  if(floatGetSign(tVal))              //if mantis is negative, 2's compelent to positive value
  {
      tVal = (~tVal) + 1;
  }

  if(floatLeftMost1(tVal) < 10)
  {
    int shifter = (10 - floatLeftMost1(tVal));
    tVal = tVal << shifter;
    tExp = tExp - shifter; 
  }

  if(floatLeftMost1(tVal) > 10)
  {
    int shifter = (floatLeftMost1(tVal) - 10);
    tVal = tVal >> shifter;
    tExp = tExp + shifter; 
  }

  tVal = tVal ^ 0x0400;

  debug("%s: bits of tSign (IEEE 754)", getBinary(tSign));
  debug("%s: bits of tExp (IEEE 754)", getBinary(tExp));
  debug("%s: bits of tVal (IEEE 754)", getBinary(tVal));

  return ((tSign << 15)|(tExp << 10)|(tVal));
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatSub (iFloat_t x, iFloat_t y) {
  return floatAdd(x,floatNegate(y));
}