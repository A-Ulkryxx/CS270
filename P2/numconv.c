/**
 *  @author Austin Youngren
 */

#include <stdio.h>

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
char int_to_char (int value, int radix) {
  if( (radix < 2) || (radix > 36) || (value >= radix))
    return '?';
  if(value < 10)
    return (value + 48);
  return (value + 55);
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int char_to_int (char digit, int radix) {
  if((radix < 2) || (radix > 36))
    return -1;
  if((digit > 47) && (digit < 58)&&((digit - 48) < radix)) 
    return (digit - 48);
  if(( digit > 64) && (digit < 91)&&((digit - 55) < radix))
    return (digit - 55);
  if((digit > 96) && (digit < 123)&&((digit - 87) < radix))
    return (digit - 87);
  else
    return -1;  
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void div_rem (int numerator, int divisor, int* remainder, int* quotient) {
  *remainder = numerator % divisor;
  *quotient = numerator / divisor;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int ascii_to_int (int valueOfPrefix, int radix) {
  char digit = getchar();
  if(digit != '\n')
  {
    valueOfPrefix = (radix * valueOfPrefix) + char_to_int(digit, radix);
    return ascii_to_int(valueOfPrefix, radix);
  } 

  return valueOfPrefix;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void int_to_ascii (int value, int radix) {
  if(value != 0)
  {
    int remainder;
    int quotient;
    div_rem(value, radix, &remainder, &quotient);
    int_to_ascii(quotient, radix);
    putchar(int_to_char(remainder, radix));
  }
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
double frac_to_double (int radix) {
  return -1.0;
}
