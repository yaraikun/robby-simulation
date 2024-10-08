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


int exitProgram = 0; // Global flag to indicate when to exit


// Pause function to allow user to acknowledge before clearing the screen.
void pause() {
    printf("Press Enter to continue...");
    while (getchar() != '\n'); // Wait for Enter
}


// Display available commands.
void displayCommands() {
    printf("\033[H\033[J"
           "Command Codes:\n"
           "0: Display Status\n"
           "1: Reset\n"
           "2: Translate Backward\n"
           "3: Rotate Clockwise\n"
           "4: Quit\n"
           "8: Translate Forward\n"
           "9: Rotate CounterClockwise\n"
           "Your command, master?: ");
}


// Process translation (forward or backward).
void processTranslation(char direction, float *pfRobotX, float *pfRobotY, 
                        double dRobotAngle) {
    float fDistance;
    printf("Enter translation distance: ");
    if (scanf("%f", &fDistance) == 1 && fDistance >= 0) {
        if (direction == 'F') {
            TranslateForward(fDistance, pfRobotX, pfRobotY, dRobotAngle);
        } else {
            TranslateBackward(fDistance, pfRobotX, pfRobotY, dRobotAngle);
        }
        printf("Robby moved to position (%.4f, %.4f).\n", *pfRobotX,
                *pfRobotY); 
    } else {
        printf("Invalid distance. Please enter a non-negative number.\n");
    }
    pause(); 
}


// Process rotation (clockwise or counterclockwise).
void processRotation(char direction, double *pdRobotAngle) {
    double dTheta;
    printf("Enter rotation angle: ");
    if (scanf("%lf", &dTheta) == 1 && dTheta >= 0) {
        if (direction == 'C') {
            RotateClockwise(dTheta, pdRobotAngle);
        } else {
            RotateCounterClockwise(dTheta, pdRobotAngle);
        }
        printf("Robby rotated to angle %.4f degrees.\n", 
                *pdRobotAngle); 
    } else {
        printf("Invalid angle. Please enter a non-negative number.\n");
    }
    pause();
}


// Get and validate user command input.
int getUserCommand() {
    int nCommandCode;
    while (1) {
        displayCommands();
        if (scanf("%d", &nCommandCode) != 1 || nCommandCode < 0 || nCommandCode > 9) {
            printf("Invalid input. Please enter a valid command code.\n");
            while (getchar() != '\n'); // Clear input buffer.
            pause();                   // Call pause function.
            continue;                  // Loop back.
        }
        while (getchar() != '\n');     // Clear input buffer.
        return nCommandCode;           // Valid command.
    }
}


// Handle the command logic based on user input
void handleCommand(int command, float *pfRobotX, float *pfRobotY, double *pdRobotAngle) {
    switch (command) {
        case DISPLAY_STATUS:
            DisplayStatus(*pfRobotX, *pfRobotY, *pdRobotAngle); 
            break;
        case RESET:
            InitializeReset(pfRobotX, pfRobotY, pdRobotAngle); 
            printf("Robot has been reset to initial position and angle.\n");
            break;
        case TRANSLATE_BACKWARD:
            processTranslation('0', pfRobotX, pfRobotY, *pdRobotAngle);
            break;
        case TRANSLATE_FORWARD:
            processTranslation('F', pfRobotX, pfRobotY, *pdRobotAngle);
            break;
        case ROTATE_CLOCKWISE:
            processRotation('C', pdRobotAngle);
            break;
        case ROTATE_COUNTERCLOCKWISE:
            processRotation('0', pdRobotAngle);
            break;
        case QUIT:
            Quit();
            exitProgram = 1;
            break;
        default:
            printf("Invalid command code. Please try again.\n");
            break;
    }

    // Pause after every command.
    pause();
}


// Main function
int main(void) {
    
    // Clear console on program start.
    printf("\033[H\033[J"); 

    // Declare input variables.
    float fRobotX, fRobotY; // Robot's position
    double dRobotAngle;     // Robot's orientation

    // Initialize Robby.
    InitializeReset(&fRobotX, &fRobotY, &dRobotAngle);

    // Simulation loop.
    while (!exitProgram) { 

        // Get user command.
        int nCommandCode = getUserCommand(); 

        // Handle user command.
        handleCommand(nCommandCode, &fRobotX, &fRobotY, &dRobotAngle);

        // Clear terminal after handling command.
        printf("\033[H\033[J");
    }

    // Program ran succesfully.
    return 0; 
}
