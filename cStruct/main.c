 /** @mainpage 
   *  \htmlinclude "STRUCTS.html"
   */
/* CS270 
 *
 * Author: Your name here
 * Date:   2/12/2020
 */
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int main( int argc, const char **argv )
{ 
    //Step 3.1
  int num;
  scanf( "%d", &num );

    //Step 3.2
  ClassRoster roster;
  roster.numStudents = num;
  roster.students = ( Student** )calloc( roster.numStudents, sizeof(Student*) );
    //Step 3.3
  for(int i = 0; i < roster.numStudents; ++i)
  {
    readStudentAndEnroll(&roster.students[i]);
  }

    //Step 3.4
  for(int i = 0; i < roster.numStudents; ++i)
  {
    displayStudent( *(roster.students[i]) );
    free(roster.students[i]);
  }
    // Step 3.5
  free(roster.students);
  return 0;
}