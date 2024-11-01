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

int main(void) {
    float fRobotX, fRobotY; // Robot's position
    double dRobotAngle;     // Robot's orientation
    int quit = 0; 

    // Initialize Robby.
    InitializeReset(&fRobotX, &fRobotY, &dRobotAngle);

    // Simulation loop.
    while (!quit) { 
        printf("\033[H\033[J"); // Clear terminal
        int nCommandCode;

        // Input validation loop for user commands.
        while (1) {
            printf("Command Codes:\n"
                   "0: Display Status\n"
                   "1: Reset\n"
                   "2: Translate Backward\n"
                   "3: Rotate Clockwise\n"
                   "4: Quit\n"
                   "8: Translate Forward\n"
                   "9: Rotate CounterClockwise\n"
                   "Your command, master?: ");

            if (scanf("%d", &nCommandCode) != 1 || 
                nCommandCode < 0 || nCommandCode > 9) {
                printf("Invalid input. Please enter a valid command code.\n");
                while (getchar() != '\n'); // Clear input buffer
                printf("Press Enter to continue...");
                while (getchar() != '\n'); // Wait for Enter
                printf("\033[H\033[J"); // Clear terminal
                continue;
            }
            while (getchar() != '\n'); // Clear input buffer before proceeding
            break; // Break out of the input loop
        }

        switch (nCommandCode) {
            case DISPLAY_STATUS:
                DisplayStatus(fRobotX, fRobotY, dRobotAngle); 
                break;
            case RESET:
                InitializeReset(&fRobotX, &fRobotY, &dRobotAngle); 
                printf("Robot has been reset to initial position and angle.\n");
                break;
            case TRANSLATE_BACKWARD:
            case TRANSLATE_FORWARD: {
                float fDistance;
                printf("Enter translation distance: ");
                if (scanf("%f", &fDistance) == 1 && fDistance >= 0) {
                    if (nCommandCode == TRANSLATE_FORWARD) {
                        TranslateForward(fDistance, &fRobotX, &fRobotY, dRobotAngle);
                    } else {
                        TranslateBackward(fDistance, &fRobotX, &fRobotY, dRobotAngle);
                    }
                    printf("Robby moved to position (%.4f, %.4f).\n", fRobotX, fRobotY); 
                } else {
                    printf("Invalid distance. Please enter a non-negative number.\n");
                }
                while (getchar() != '\n'); // Clear input buffer
                break;
            }
            case ROTATE_CLOCKWISE:
            case ROTATE_COUNTERCLOCKWISE: {
                double dTheta;
                printf("Enter rotation angle: ");
                if (scanf("%lf", &dTheta) == 1 && dTheta >= 0) {
                    if (nCommandCode == ROTATE_CLOCKWISE) {
                        RotateClockwise(dTheta, &dRobotAngle);
                    } else {
                        RotateCounterClockwise(dTheta, &dRobotAngle);
                    }
                    printf("Robby rotated to angle %.4f degrees.\n", dRobotAngle); 
                } else {
                    printf("Invalid angle. Please enter a non-negative number.\n");
                }
                while (getchar() != '\n'); // Clear input buffer
                break;
            }
            case QUIT:
                Quit();
                quit = 1;
                break;
            default:
                printf("Invalid command code. Please try again.\n");
                break;
        }

        // Pause after every command.
        printf("Press Enter to continue...");
        while (getchar() != '\n'); // Wait for Enter
    }

    // Program ran successfully.
    return 0; 
}
