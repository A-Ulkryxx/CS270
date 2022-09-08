#include "field.h"
#include <stdio.h>

/** @file field.c
 *  @brief You will modify this file and implement five functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful. 
 * <p>
 * @author <b>Your name</b> goes here
 */

/** @todo Implement in field.c based on documentation contained in field.h */
int getBit (int value, int position) {
    return ((value >> position) & 1);
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setBit (int value, int position) {
    return ((1 << position) | value);
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit (int value, int position) {
    int mask = ~(1 << position);
    return (mask & value);
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField (int value, int hi, int lo, bool isSigned) {    
    int field = (value >> lo);

    for( int i = 31; i > (hi - lo); i-- )
    {
        field = clearBit(field, i);
    }

    if(isSigned == 1)
    {
        field = ~(field) + 1;
    }
    
    return field;
}