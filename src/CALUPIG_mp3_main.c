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
                /* Displays command codes */
                printf("Command Codes:\n"
                       "0: Display Status, 1: Reset, 2: Translate Backward, 3: Rotate Clockwise, 4: Quit, 8: Translate Forward, 9: Rotate Counterclockwise\n"
                       "Your command, master?: ");

                /* Ask user for input */
                scanf("%d", &nCommandCode);

                /* Handles command code */
                switch (nCommandCode) {
                        case DISPLAY_STATUS:
                                DisplayStatus(fRobotX, fRobotY, dRobotAngle); 
                                break;
                        case RESET:
                                InitializeReset(&fRobotX, &fRobotY,
                                                &dRobotAngle); 
                                printf("Robot has been reset to initial position and angle.\n");
                                break;
                        case TRANSLATE_BACKWARD:
                                printf("Enter translation distance: ");
                                scanf("%f", &fDistance);
                                TranslateBackward(fDistance, &fRobotX,
                                                  &fRobotY, dRobotAngle);
                                printf("Robby moved to position (%.4f, %.4f).\n",
                                        fRobotX, fRobotY);
                                break;
                        case TRANSLATE_FORWARD: 
                                printf("Enter translation distance: ");
                                scanf("%f", &fDistance);
                                TranslateForward(fDistance, &fRobotX, &fRobotY,
                                                 dRobotAngle);
                                printf("Robby moved to position (%.4f, %.4f).\n",
                                        fRobotX, fRobotY);
                                break;
                        case ROTATE_CLOCKWISE:
                                printf("Enter rotation angle: ");
                                scanf("%lf", &dTheta);
                                RotateClockwise(dTheta, &dRobotAngle);
                                printf("Robby rotated to angle %.4f degrees.\n",
                                        dRobotAngle);
                                break;
                        case ROTATE_COUNTERCLOCKWISE: 
                                printf("Enter rotation angle: ");
                                RotateCounterClockwise(dTheta, &dRobotAngle);
                                printf("Robby rotated to angle %.4f degrees.\n",
                                        dRobotAngle);
                                break;
                        case QUIT:
                                Quit();
                                break;
                        default:
                                printf("Invalid input. Please enter a valid command code.\n");
                                break;
                }
        } while (nCommandCode != 4);

        return 0; 
}
