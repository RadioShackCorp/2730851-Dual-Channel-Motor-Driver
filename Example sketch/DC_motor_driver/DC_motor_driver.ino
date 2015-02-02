//********************************************************************************
// * File Name          : DC_motor_driver
// * Author             : RadioShack Corporation
// * Version            : V1.0
// * Date               : 2014/01/27
// * Description        : Control direction and speed of a motor 
// *                      using pulse width modulation (PWM)
// ********************************************************************************
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ********************************************************************************
int CH1A =5;     // CH1A, CH1B, CH2A, and CH2B 
int CH1B =6;     // must be one of 3, 5, 6, 9, 10, or 11 for PWM
int CH2A =10;    // Set digital ~5, ~6, ~10, and ~11 for default pins.
int CH2B =11;

// *********************************************************************************
// * Function:  Control MotorA
// * Input:     speed (PWM duty, range = 0-255)
// *********************************************************************************
void motorA_forward(int sp)
{
  analogWrite(CH1A,sp); 
  analogWrite(CH1B,0);
}
void motorA_backward(int sp)
{
  analogWrite(CH1A,0);
  analogWrite(CH1B,sp);
}

// *********************************************************************************
// * Function:  Control MotorB
// * Input:     speed (PWM duty, range = 0-255)
// *********************************************************************************
void motorB_forward(int sp)
{
  analogWrite(CH2A,sp);
  analogWrite(CH2B,0);
}
void motorB_backward(int sp)
{
  analogWrite(CH2A,0);
  analogWrite(CH2B,sp);
}

void setup()
{
  pinMode(CH1A, OUTPUT);   // Initialize pin for output
  pinMode(CH1B, OUTPUT);
  pinMode(CH2A, OUTPUT);
  pinMode(CH2B, OUTPUT);
}

void loop()
{
 motorA_forward(200); // motorA rotates forward with a defualt speed (PWM duty) of 200.
 motorB_forward(200); // motorB rotates forward with a defualt speed (PWM duty) of 200.
 delay(2000);         // delay 2000 milliseconds (2 seconds).
 motorA_backward(200);// motorA rotates backwards with a defualt speed (PWM duty) of 200.
 motorB_backward(200);// motorB rotates backwards with a defualt speed (PWM duty) of 200.
 delay(2000);         // delay 2000 milliseconds (2 seconds).
}

