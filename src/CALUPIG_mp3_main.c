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
#include "mp3_robot.h"


// Main function for Robby simulation.
int main(void) {

    // printf("\033[H\033[J");

    // Declared six variables.
    float fRobotX, fRobotY;         // Robby's position (x, y).
    double dRobotAngle;             // Robby's orientation (in degrees).
    float fDistance;                // Robby's translation distance.
    double dTheta;                  // Robby's rotation angle.
    int nCommandCode;               // User command code.

    // Call the function InitializeReset() to initialize the robot's position
    // and orientation.
    InitializeReset(&fRobotX, &fRobotY, &dRobotAngle);

    // Start of simulation loop.
    while (1) {

        // Ask user to input command code.
        printf("Command Codes:\n"
                "0: Display Status\n"
                "1: Reset\n"
                "2: Translate Backward\n"
                "3: Rotate Clockwise\n"
                "4: Quit\n"
                "8: Translate Forward\n"
                "9: Rotate CounterClockwise\n"
                "Your command, master?: ");

        // Command code input validation.
        while (1) {
            if (scanf("%d", &nCommandCode) != 1) {
                printf("Invalid input. Please enter a valid command code.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            // Clear input buffer to remove any remaining characters
            while (getchar() != '\n');
            if (nCommandCode >= 0 && nCommandCode <= 9) {
                break; // Valid input; exit the loop
            } else {
                printf("Invalid command code. Please try again.\n");
            }
        }

        // Switch case statement for command code.
        switch(nCommandCode) {
            case 0:
                DisplayStatus(fRobotX, fRobotY, dRobotAngle);
                break;
            case 1:
                InitializeReset(&fRobotX, &fRobotY, &dRobotAngle);
                break;
            case 2:
                printf("Enter translation distance: ");
                if (scanf("%f", &fDistance) == 1 && fDistance >= 0) {
                    TranslateBackward(fDistance, &fRobotX, &fRobotY,
                                      dRobotAngle);
                } else {
                    printf("Invalid distance. Please enter a non-negative " 
                            "number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                }
                break;
            case 3:
                printf("Enter rotation angle: ");
                if (scanf("%lf", &dTheta) == 1 && dTheta >= 0) {
                    RotateClockwise(dTheta, &dRobotAngle);
                } else {
                    printf("Invalid angle. Please enter a non-negative " 
                            "number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                }
                break;
            case 4:
                Quit();
                return 0;
            case 8:
                printf("Enter translation distance: ");
                if (scanf("%f", &fDistance) == 1 && fDistance >= 0) {
                    TranslateForward(fDistance, &fRobotX, &fRobotY,
                                     dRobotAngle);
                } else {
                    printf("Invalid distance. Please enter a non-negative " 
                            "number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                }
                break;
            case 9:
                printf("Enter rotation angle: ");
                if (scanf("%lf", &dTheta) == 1 && dTheta >= 0) {
                    RotateCounterClockwise(dTheta, &dRobotAngle);
                } else {
                    printf("Invalid angle. Please enter a non-negative " 
                            "number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                }
                break;
            default:
                printf("Invalid command code. Please try again.\n");
                break;
        }
    }

    // Program completed succesfully.
    return 0;
}
