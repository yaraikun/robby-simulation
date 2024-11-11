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

int main(void)
{
    float fRobotX, fRobotY;  /* Robby coordinates */
    double dRobotAngle;      /* Robby orientation */

    float fDistance;         /* Translate distance */
    double dTheta;           /* Angle to add */

    int nCommandCode;        /* User command */

    /* Initialize Robby */
    InitializeReset(&fRobotX, &fRobotY, &dRobotAngle);

    /* Simulation loop */
    do { 
        /* Clear screen at start of every iteration */
        printf("\033[H\033[J");

        /* Display command codes */
        printf("Command Codes:\n"
               "0: Display Status\n"
               "1: Reset\n"
               "2: Translate Backward\n"
               "3: Rotate Clockwise\n"
               "4: Quit\n"
               "8: Translate Forward\n"
               "9: Rotate CounterClockwise\n"
               "Your command, master?: ");

        /* Input validation */
        scanf("%d", &nCommandCode);

        /* Clear input buffer before moving on */
        while (getchar() != '\n');

        /* Handle command code */
        switch (nCommandCode) {
            case DISPLAY_STATUS:
                DisplayStatus(fRobotX, fRobotY, dRobotAngle); 
                break;
            case RESET:
                InitializeReset(&fRobotX, &fRobotY, &dRobotAngle); 
                printf("Robot has been reset to initial position and angle.\n");
                break;
            case TRANSLATE_BACKWARD:
                printf("Enter translation distance: ");
                scanf("%f", &fDistance);
                if (fDistance >= 0) {
                    TranslateBackward(fDistance, &fRobotX, &fRobotY,
                                      dRobotAngle);
                    printf("Robby moved to position (%.4f, %.4f).\n",
                            fRobotX, fRobotY);
                } else {
                    printf("Invalid distance. Please enter a non-negative number.\n");
                }
                while (getchar() != '\n');
                break;
            case TRANSLATE_FORWARD: 
                printf("Enter translation distance: ");
                scanf("%f", &fDistance);
                if (fDistance >= 0) {
                    TranslateForward(fDistance, &fRobotX, &fRobotY,
                                     dRobotAngle);
                    printf("Robby moved to position (%.4f, %.4f).\n",
                            fRobotX, fRobotY);
                } else {
                    printf("Invalid distance. Please enter a non-negative number.\n");
                }
                while (getchar() != '\n');
                break;
            case ROTATE_CLOCKWISE:
                printf("Enter rotation angle: ");
                scanf("%lf", &dTheta);
                if (dTheta >= 0) {
                    RotateClockwise(dTheta, &dRobotAngle);
                    printf("Robby rotated to angle %.4f degrees.\n",
                            dRobotAngle);
                } else {
                    printf("Invalid angle. Please enter a non-negative number.\n");
                }
                while (getchar() != '\n');
                break;
            case ROTATE_COUNTERCLOCKWISE: 
                printf("Enter rotation angle: ");
                if (scanf("%lf", &dTheta) == 1 && dTheta >= 0) {
                    RotateCounterClockwise(dTheta, &dRobotAngle);
                    printf("Robby rotated to angle %.4f degrees.\n",
                            dRobotAngle);
                } else {
                    printf("Invalid angle. Please enter a non-negative number.\n");
                }
                while (getchar() != '\n');
                break;
            case QUIT:
                Quit();
                break;
            default:
                printf("Invalid input. Please enter a valid command code.\n");
                break;
        }

        /* Pause after every handling command */
        printf("Press Enter to continue...");
        while (getchar() != '\n');
    } while (nCommandCode != 4);

    return 0; 
}
