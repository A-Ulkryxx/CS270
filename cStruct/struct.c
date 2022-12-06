/* CS270 
 *
 * Author: Your name here
 * Date:   2/12/2020
 */

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

/********** FUNCTION DEFINITIONS **********************************************/

void readStudentAndEnroll(Student **slot)
{
        //Step 5.1
    Student *newStudent = ( Student* )malloc( sizeof(Student) );
        //Step 5.2
    scanf("%s", newStudent->firstName);
        //Step 5.3
    scanf("%f", &newStudent->qualityPoints);
        //Step 5.4
    scanf("%d", &newStudent->numCredits);
        //Step 5.5
    *slot = newStudent;
}

void displayStudent(Student s)
{
        //Step 7.1
    float gpa = s.qualityPoints / s.numCredits;
        //Step 7.2
    printf("%s, %.2f\n", s.firstName, gpa);
    
}