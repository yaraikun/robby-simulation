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

    // Clear console screen on program startup.
    printf("\033[H\033[J");

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

            // Check if input was succesful.
            if (scanf("%d", &nCommandCode) != 1) {
                printf("Invalid input. Please enter a valid command code.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }

            // Clear input buffer to remove any remaining characters.
            while (getchar() != '\n');

            // Valid input; exit loop.
            if (nCommandCode >= 0 && nCommandCode <= 9) {
                break;             
            }

            // Invalid input; continue.
            else {
                printf("Invalid command code. Please try again.\n");
            }
        }

        // Switch case statement for different command codes.
        switch(nCommandCode) {

            // Display Robby's current position.
            case DISPLAY_STATUS: 
                DisplayStatus(fRobotX, fRobotY, dRobotAngle);
                printf("Press Enter to continue..."); // Pause before clearing.
                while (getchar() != '\n');            // Wait for Enter.
                break;

            // Reset Robby's position to (0, 0), Angle 0.
            case RESET: 
                InitializeReset(&fRobotX, &fRobotY, &dRobotAngle);
                printf("Robot has been reset to initial position and angle.\n");
                printf("Press Enter to continue..."); // Pause before clearing.
                while (getchar() != '\n');            // Wait for Enter.
                break;

            // Move Robby backwards.
            case TRANSLATE_BACKWARD:

                // User inputs translation distance.
                printf("Enter translation distance: ");

                // If valid value, print new position.
                if (scanf("%f", &fDistance) == 1 && fDistance >= 0) {
                    TranslateBackward(fDistance, &fRobotX, &fRobotY,
                                      dRobotAngle);
                    printf("Robby moved to position (%.4f, %.4f).\n",
                            fRobotX, fRobotY);
                    while (getchar() != '\n');        // Clear input buffer.
                }

                // If invalid value, print error.
                else {
                    printf("Invalid distance. Please enter a non-negative "
                           "number.\n");
                    while (getchar() != '\n');        // Clear input buffer.
                }

                // Pause function
                printf("Press Enter to continue..."); // Pause before clearing.
                while (getchar() != '\n');            // Wait for Enter.
                break;

            // Rotate Robby clockwise.
            case ROTATE_CLOCKWISE: 
                printf("Enter rotation angle: ");
                if (scanf("%lf", &dTheta) == 1 && dTheta >= 0) {
                    RotateClockwise(dTheta, &dRobotAngle);
                    printf("Robby rotated to angle %.4f degrees.\n",
                            dRobotAngle);
                    while (getchar() != '\n');        // Clear input buffer.
                } else {
                    printf("Invalid angle. Please enter a non-negative number."
                           "\n");
                    while (getchar() != '\n');        // Clear input buffer.
                }
                printf("Press Enter to continue..."); // Pause before clearing.
                while (getchar() != '\n');            // Wait for Enter.
                break;

            // Quit program.
            case QUIT: 
                Quit();
                return 0;

            // Move Robby forward.
            case TRANSLATE_FORWARD:
                printf("Enter translation distance: ");
                if (scanf("%f", &fDistance) == 1 && fDistance >= 0) {
                    TranslateForward(fDistance, &fRobotX, &fRobotY,
                                     dRobotAngle);
                    printf("Robby moved to position (%.4f, %.4f).\n", fRobotX,
                            fRobotY);
                    while (getchar() != '\n');        // Clear input buffer.
                } else {
                    printf("Invalid distance. Please enter a non-negative "
                           "number.\n");
                    while (getchar() != '\n');        // Clear input buffer.
                }
                printf("Press Enter to continue..."); // Pause before clearing.
                while (getchar() != '\n');            // Wait for Enter.
                break;

            // Rotate Robby counterclockwise.
            case ROTATE_COUNTERCLOCKWISE: 
                printf("Enter rotation angle: ");
                if (scanf("%lf", &dTheta) == 1 && dTheta >= 0) {
                    RotateCounterClockwise(dTheta, &dRobotAngle);
                    printf("Robby rotated to angle %.4f degrees.\n", 
                            dRobotAngle);
                    while (getchar() != '\n');        // Clear input buffer.
                } else {
                    printf("Invalid angle. Please enter a non-negative number."
                           "\n");
                    while (getchar() != '\n');        // Clear input buffer.
                }
                printf("Press Enter to continue..."); // Pause before clearing.
                while (getchar() != '\n');            // Wait for Enter.
                break;

            // Handle invalid or unexpected command codes.
            default:
                printf("Invalid command code. Please try again.\n");
                break;
        }

        // Clear screen after command to maybe make it more readable.
        printf("\033[H\033[J");
    }

    // Program completed succesfully.
    return 0;
}
