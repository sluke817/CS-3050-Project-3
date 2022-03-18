/*
* Luke Schaefer
* 18186970
* LESDMG
*/

#include <stdlib.h>
#include <stdio.h>
#include "PA3.h"

int main (void) {
    /*
    * Read Input
    * Process Input
    * Send output
    */
   int * input = ReadInput();
   if(input) {
       Queue * path = ProcessInput(input);
       OutputPath(path);
   }
   
}