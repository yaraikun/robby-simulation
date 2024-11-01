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

int quit = 0; 

/**
 * pause - Pause screen and prompts user to press enter to continue.
 */
void pause()
{
        // Print Enter to continue prompt.
        printf("Press Enter to continue...");

        // Wait for user Enter.
        while (getchar() != '\n'); 
}

/**
 * displayCommands - Displays available command codes.
 */
void displayCommands() 
{
        printf("Command Codes:\n"
               "0: Display Status\n"
               "1: Reset\n"
               "2: Translate Backward\n"
               "3: Rotate Clockwise\n"
               "4: Quit\n"
               "8: Translate Forward\n"
               "9: Rotate CounterClockwise\n"
               "Your command, master?: ");
}

/**
 * processTranslation - Processes translate commands.
 * @direction: Translation direction (forwards or backwards).
 * @pfRobotX: Pointer to robot's current x-coordinate.
 * @pfRobotY: Pointer to robot's current y-coordinate.
 * @dRobotAngle: Robot's current orientation.
 *
 * Calls translate forward / translate backward functions.
 */
void processTranslation(int direction, float *pfRobotX, float *pfRobotY, 
                        double dRobotAngle)
{
        // fDistance variable declaration.
        float fDistance;

        // Enter distance prompt.
        printf("Enter translation distance: ");

        // If valid; else invalid.
        if (scanf("%f", &fDistance) == 1 && fDistance >= 0) {

                // If forward, else backward.
                if (direction == 1)
                        TranslateForward(fDistance, pfRobotX, pfRobotY,
                                         dRobotAngle);
                else
                        TranslateBackward(fDistance, pfRobotX, pfRobotY,
                                          dRobotAngle);

                // Output Robby change in position.
                printf("Robby moved to position (%.4f, %.4f).\n",
                        *pfRobotX, *pfRobotY); 
        } else {
                // Output error message.
                printf("Invalid distance. Please enter a non-negative number.\n");
        }

        // Pause after translation command.
        while (getchar() != '\n'); 
}

/**
 * processRotation - Processes rotate commands.
 * @direction: Translation direction (clockwise or counterclockwise).
 * @pdRobotAngle: Pointer to robot's current orientation.
 *
 * Calls translate forward / translate backward functions.
 */
void processRotation(int direction, double *pdRobotAngle)
{
        // Angle variable declaration.
        double dTheta;

        // Enter angle prompt.
        printf("Enter rotation angle: ");

        // If valid; else invalid.
        if (scanf("%lf", &dTheta) == 1 && dTheta >= 0) {
                // If clockwise; else counterclockwise.
                if (direction == 1) {
                        RotateClockwise(dTheta, pdRobotAngle);
                } else {
                        RotateCounterClockwise(dTheta, pdRobotAngle);
                }

                // Print Robby's new angle.
                printf("Robby rotated to angle %.4f degrees.\n",
                        *pdRobotAngle); 
        } else {
                // Print error message.
                printf("Invalid angle. Please enter a non-negative number.\n");
        }

        // Clear input buffer to make pause work.
        while (getchar() != '\n'); 
}

/**
 * getUserCommand - Validates user command code.
 */
int getUserCommand()
{
        // Declare command code. 
        int nCommandCode;

        // Input validation loop.
        while (1) {
                // Display commands.
                displayCommands();

                // If invalid; infinite loop.
                if (scanf("%d", &nCommandCode) != 1 || 
                                nCommandCode < 0 || 
                                nCommandCode > 9) {
                        printf("Invalid input. Please enter a valid command code.\n");

                        // FIRST, clear input buffer.
                        while (getchar() != '\n'); 

                        // THEN, pause.
                        pause();                  

                        // AND THEN, loop.
                        continue;                
                }

                // Clear input buffer before exiting again.
                while (getchar() != '\n');     

                // Only return valid command.
                return nCommandCode;          
        }
}

/**
 * handleCommand - Handles user command code.
 * @nCommandCode - User input command code.
 * @pfRobotX - Pointer to robot's current x-coordinate.
 * @pfRobotY - Pointer to robot's current y-coordinate.
 * @pdRobotAngle - Pointer to robot's current orientation.
 *
 * Calls corresponding "handle" command functions based on user input.
 */
void handleCommand(int nCommandCode, float *pfRobotX, float *pfRobotY, 
                   double *pdRobotAngle)
{
        switch (nCommandCode) {
                case DISPLAY_STATUS:
                        DisplayStatus(*pfRobotX, *pfRobotY, *pdRobotAngle); 
                        break;
                case RESET:
                        InitializeReset(pfRobotX, pfRobotY, pdRobotAngle); 
                        printf("Robot has been reset to initial position and angle.\n");
                        break;
                case TRANSLATE_BACKWARD:
                        processTranslation(0, pfRobotX, pfRobotY,
                                           *pdRobotAngle);
                        break;
                case TRANSLATE_FORWARD:
                        processTranslation(1, pfRobotX, pfRobotY,
                                           *pdRobotAngle);
                        break;
                case ROTATE_CLOCKWISE:
                        processRotation(1, pdRobotAngle);
                        break;
                case ROTATE_COUNTERCLOCKWISE:
                        processRotation(0, pdRobotAngle);
                        break;
                case QUIT:
                        Quit();
                        quit = 1;
                        break;
                default:
                        printf("Invalid command code. Please try again.\n");
                        break;
        }

        // Pause after every command.
        pause();
}

/**
 * main - Contains main simulation loop.
 */
int main(void)
{
        // Declare input variables.
        float fRobotX, fRobotY; // Robot's position
        double dRobotAngle;     // Robot's orientation

        // Initialize Robby.
        InitializeReset(&fRobotX, &fRobotY, &dRobotAngle);

        // Simulation loop.
        while (!quit) { 
                // Clear terminal at start of each iteration.
                printf("\033[H\033[J");

                // Get user command.
                int nCommandCode = getUserCommand(); 

                // Handle user command.
                handleCommand(nCommandCode, &fRobotX, &fRobotY, &dRobotAngle);
        }

        // Program ran succesfully.
        return 0; 
}
