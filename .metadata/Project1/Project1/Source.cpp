
#include <stdio.h>
#include <iostream>
using namespace std;

/** @file field.c
 *  @brief You will modify this file and implement five functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful.
 * <p>
 * @author <b>Your name</b> goes here
 */

 /** @todo Implement in field.c based on documentation contained in field.h */
int getBit(int value, int position) {
    //int bit;
    value = unsigned(value) & (1 << position);

    return value;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setBit(int value, int position) {

    

    return value;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit(int value, int position) {
    value = value | (1 << position);

    return value;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField(int value, int hi, int lo, bool isSigned) {
    return 0;
}

int main()
{
    unsigned int value = 00100001110111001;
    int position;
    
    cout << "Enter Position" << endl;
    cin >> position;

    cout << "Get Bit is: " << getBit(value, position) << endl;
    cout << "Set Bit is: " << setBit(value, position) << endl;
    cout << "Clear Bit is: " << clearBit(value, position) << endl;
    cout << "Get Bit is: " << clearBit(value, position) << endl;
}