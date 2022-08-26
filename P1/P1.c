// P1 Assignment
// Author: Austin Youngren
// Date:   1/15/2020
// Class:  CS270
// Email:  Austin.Youngren@colostate.edu

// Include files
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// example of a global array
int exampleGlobalArray[2];
double input[5]
double output[4]

// this function can be used as a guide for the funtions you will implement
void computeCircle(double radius, double *addressOfArea)
{
    // Compute area
    double result = 3.141593 * radius * radius;

    // Dereference pointer to return result
    *addressOfArea = result;
}

int main(int argc, char *argv[])
{
	print("Input 5 numbers (include spaces between each number):\n"); 
	printf("%f %f %f %f %f", &input[0], &input[1], &input[2], &input[3],&input[4]);
    // Check number of arguments
	if(
    if (argc != 2) {
        printf("usage: ./P1 <double>\n");
        return EXIT_FAILURE;
    }

    // Parse arguments
    double radius = atof(argv[1]);

    // Local variable
    double area;

    // Call function
    computeCircle(radius, &area);

    // Print area
    printf("The area of a circle with radius %.5f equals %.5f.\n", radius, area);

    // Return success
    return EXIT_SUCCESS;
}