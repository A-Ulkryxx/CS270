/* CS270 
 *
 * Author: Your name here
 * Date:   2/12/2020
 */
 
/********** STRUCTURE DEFINITION **********************************************/

// Structure that represents a student
typedef struct
{
    // TODO: Add required members
    //Step 1
  char firstName[80];
  float qualityPoints;
  int numCredits;
} Student;

  // Structure that represents a class roster
  //Step 2
typedef struct 
{
  int numStudents;
  Student **students;
}ClassRoster;

// TODO: Declare this structure

/********** FUNCTION PROTOTYPES ***********************************************/

void readStudentAndEnroll(Student **slot);

void displayStudent(Student s);