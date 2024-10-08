# Robby Simulation

## Overview

This project implements a simulation of a robot named Robby, allowing users to control its movements and orientation in a 2D space. The simulation includes various commands to reset the robot, move it forward or backward, and rotate it clockwise or counterclockwise.

## Files

1. **`lastname_mp3_main.c`**: Contains the main function for testing the robot control functions.
2. **`lastname_mp3_robot.c`**: Contains the implementation of the robot's control functions.
3. **`mp2_math.c`**: Contains implementations for mathematical operations like sine, cosine, and power functions.
4. **`mp2_math.h`**: Header file declaring mathematical functions used in the simulation.
5. **`mp3_robot.h`**: Header file that defines constants and function prototypes for robot control.

## Command Codes

The following command codes are available for controlling Robby:

- **1**: Reset
- **2**: Translate Backward
- **3**: Rotate Clockwise
- **4**: Quit
- **8**: Translate Forward
- **9**: Rotate CounterClockwise
- **0**: Display Status

## How to Use

1. **Compile the Program**: Ensure you compile the main file alongside the object files for the robot and math functions.
2. **Run the Program**: Execute the compiled program.
3. **Input Commands**: Follow the on-screen prompts to input command codes. After entering a command, Robby will execute the action and display the new state or position.
4. **Exit**: Enter the command code `4` to quit the simulation.

## Functions Overview

### Initialization and Reset
- `void InitializeReset(float *pfRobotX, float *pfRobotY, double *pdRobotAngle)`: Resets the robot's position to (0, 0) and orientation to 0 degrees.

### Display Status
- `void DisplayStatus(float fRobotX, float fRobotY, double dRobotAngle)`: Displays the robot's current position and orientation.

### Translation Commands
- `void TranslateForward(float fDistance, float *pfRobotX, float *pfRobotY, double dRobotAngle)`: Moves the robot forward by the specified distance.
- `void TranslateBackward(float fDistance, float *pfRobotX, float *pfRobotY, double dRobotAngle)`: Moves the robot backward by the specified distance.

### Rotation Commands
- `void RotateClockwise(double dTheta, double *pdRobotAngle)`: Rotates the robot clockwise by the specified angle.
- `void RotateCounterClockwise(double dTheta, double *pdRobotAngle)`: Rotates the robot counterclockwise by the specified angle.

### Quit Command
- `void Quit(void)`: Ends the simulation and displays a closing message.

## Mathematical Functions
The project also includes mathematical functions for calculating sine, cosine, and power operations using Taylor series expansions.

### Math Functions
- `double RaiseTo(double x, int n)`: Computes \(x^n\).
- `double factorial(int n)`: Computes the factorial of \(n\).
- `double cosine(double x)`: Computes the cosine of angle \(x\) in radians.
- `double sine(double x)`: Computes the sine of angle \(x\) in radians.

## Conclusion
This simulation provides an interactive way to control a robot and demonstrates fundamental programming concepts, including functions, loops, and input validation. Enjoy exploring the capabilities of Robby!
