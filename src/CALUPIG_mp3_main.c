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

int quitFlag = 0;

void displayMenu(void);
void handleCommand(int commandCode, float *robotX, float *robotY, double *robotAngle);
void handleForward(float *robotX, float *robotY, double robotAngle);
void handleBackward(float *robotX, float *robotY, double robotAngle);
void handleCCW(double *robotAngle);
void handleCW(double *robotAngle);
void pause(void);
void clearScreen(void);

int main(void)
{
    float robotX, robotY;
    double robotAngle;
    int commandCode;

    // Initialize the robot's position and orientation
    InitializeReset(&robotX, &robotY, &robotAngle);

    while (!quitFlag) {
        clearScreen();  // Clear the screen at the start of each iteration

        // Display current status
        DisplayStatus(robotX, robotY, robotAngle);
        
        // Display command menu
        displayMenu();
        scanf("%d", &commandCode);

        // Handle the command based on the user input
        handleCommand(commandCode, &robotX, &robotY, &robotAngle);
    }

    return 0;
}

void displayMenu(void)
{
    printf("Enter command code (0: DISPLAY_STATUS, 1: RESET, 2: BACKWARD, "
           "3: CW, 4: QUIT, 8: FORWARD, 9: CCW): ");
}

void handleCommand(int commandCode, float *robotX, float *robotY, double *robotAngle)
{
    switch (commandCode) {
        case DISPLAY_STATUS:
            DisplayStatus(*robotX, *robotY, *robotAngle);
            pause();
            break;
        case RESET:
            InitializeReset(robotX, robotY, robotAngle);
            pause();
            break;
        case TRANSLATE_BACKWARD:
            handleBackward(robotX, robotY, *robotAngle);
            pause();
            break;
        case ROTATE_CLOCKWISE:
            handleCW(robotAngle);
            pause();
            break;
        case QUIT:
            Quit();
            pause();
            quitFlag = 1;
            break;
        case TRANSLATE_FORWARD:
            handleForward(robotX, robotY, *robotAngle);
            pause();
            break;
        case ROTATE_COUNTERCLOCKWISE:
            handleCCW(robotAngle);
            pause();
            break;
        default:
            printf("Invalid command. Please try again.\n");
            break;
    }
}

void handleForward(float *robotX, float *robotY, double robotAngle)
{
    float distance;
    printf("Enter distance: ");
    scanf("%f", &distance);
    TranslateForward(distance, robotX, robotY, robotAngle);
}

void handleBackward(float *robotX, float *robotY, double robotAngle)
{
    float distance;
    printf("Enter distance: ");
    scanf("%f", &distance);
    TranslateBackward(distance, robotX, robotY, robotAngle);
}

void handleCCW(double *robotAngle)
{
    double angle;
    printf("Enter angle: ");
    scanf("%lf", &angle);
    RotateCounterClockwise(angle, robotAngle);
}

void handleCW(double *robotAngle)
{
    double angle;
    printf("Enter angle: ");
    scanf("%lf", &angle);
    RotateClockwise(angle, robotAngle);
}

void pause(void)
{
    printf("Press enter to continue...");
    getchar();
    getchar();
}

void clearScreen(void)
{
    printf("\033[H\033[J");
}
