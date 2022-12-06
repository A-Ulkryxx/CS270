#include <stdio.h>

int main() {

        //PART1
    int i;  	// an integer value
    int *pi;	// a pointer to an integer value
    
    i = -1;
    pi = &i ;	// set pi to the address of i
    
    printf("i: %d, pi: %p > *pi: %d\n", i, pi, *pi);
    
    // place additional code here


        //PART2
    int **ppi;
    ppi = &pi ; // set ppi to the address of pi
    
    printf("i: %d, pi: %p > *pi: %d, ppi: %p > **ppi: %d \n", i, pi, *pi, ppi, **ppi);
    


        //PART3
    int memory[] = {1,2,3,4,5,6,7,8,9};
    int *pm;

    pm = memory;  // &memory[0] is an alternative.
    for (int i=0; i<9; i++) {
        printf("pm: %p > *pm: %d\n", pm, *pm);
        pm++;
    }


        //PART4
    int *nm;
    pm = memory;
    nm = (int *) *pm;
    printf ("pm: %p, nm: %p\n", pm, nm);   

        //PART5 
    char *cp;
    cp = (char *) pm;
    
    for (int i=0; i<36; i++) {
      printf ("cp: %p > *cp: 0x%02X\n", cp, *cp);
      cp++;
      }   


        //PART6
      return 0;
} 