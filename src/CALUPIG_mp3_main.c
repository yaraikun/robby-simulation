/* CCPROG1 Machine Problem Part 3                                            */
/* CALUPIG, Evan Riley L.                                                    */
/* S24B                                                                      */
/*                                                                           */
/* This file contains the main() function for testing the robot control      */
/* functions in lastname_mp3_robot.c                                         */
/*                                                                           */
/* NOTES:                                                                    */
/* 1. Change the word "lastname" in the filename to your own last name.      */
/*    For example, if your last name is SANTOS, then this file should be     */
/*    named as SANTOS_mp3_main.c                                             */ 
/* 2. Your main task is to fill-up the body of main() function.              */
/* 3. You are NOT ALLOWED to add new codes other than the implementation     */
/*    of the body of the main() function.                                    */  
/* 4. You have to compile and link this with the object files corresponding  */
/*    to your lastname_mp3_robot.obj and lastname_mp2_math.obj in order to   */
/*    produce the executable file.                                           */      

#include <stdio.h>
#include <mp3_robot.h>


/* main function for Robby simulation */
int main(void) {

    printf("hello from main.c\n");

    float fRobotX, fRobotY;
    double dRobotAngle;
    float fDistance;
    double fRotationAngle;
    int nCommandCode;

    // Call the function InitializeReset() to initialize the robot's position
    // and orientation.
    InitializeReset(&fRobotX, &fRobotY, &dRobotAngle);

    while (1) {
        // Ask user to input command code.
        printf("Enter command code:\n"
                "0: Display Status\n"
                "1: Reset\n"
                "2: Translate Backward\n"
                "3: Rotate Clockwise\n"
                "4: Quit\n"
                "8: Translate Forward\n"
                "9: Rotate CounterClockwise\n");
        scanf("%d", &nCommandCode);

    }
  /* 
     NOTE #1:
     You are allowed to declare only SIX variables corresponding to:
     - robot's position, i.e., x and y coordinates  (2 variables)
     - robot's orientation (1 variable)
     - translation distance (1 variable)
     - rotation angle (1 variable)
     - command code (1 variable)
   
     NOTE #2:
     Write the C statements corresponding to the following steps:
     1. First and foremost, call the function InitializeReset() to initialize
        the robot's position and orientation.
     2. Ask the user to input the command code.  If the command requires
        additional data (for example: translate command requires a translation
        distance, while the rotate command requires a rotation angle), 
        ask the user to input the appropriate data value using scanf().
     3. Call the function that corresponds to the command code.
     4. If the command code is not yet for the Quit() function, repeat again
        from step 2.  If the command code is for quit, terminate the program
        execution.

    
     NOTE #3: 
     Make sure that you use the macro names which were defined in the 
     mp3_robot.h file.  They can be used with if-else statement or with
     switch-case statement.
  
   
     NOTE #4: (VERY IMPORTANT!)
     The main() function that you are implementing here is actually for your 
     use;
     i.e., so that you can check and verify the correctness of your solution.
     For the actual check, I will use my own main() function and link it with 
     your lastname_mp3_robot and lastname_mp2_math object files.  The resulting 
     executable file should also be 100% semantically correct for you to earn a 
     perfect grade.   
  */

  return 0;
}
