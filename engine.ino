#include <Stepper.h> 
//Declare variables and assign pin number
int in1Pin = 8;
int in2Pin = 9;
int in3Pin = 10;
int in4Pin = 11;
const int stepsPerRevolution = 2048;// Update the number of steps per revolution required for your motor
// Create a stepper object 
// Note: We are using 28BYJ-48 5VDC Stepper Motor, for this motor, we need to set wiring sequence to (1-3-2-4) instead of (1-2-3-4)
Stepper motor(stepsPerRevolution, in1Pin, in3Pin, in2Pin, in4Pin); 
 
void setup()
{ Serial.begin(9600);
  Serial.print("Set motor speed to (in RPM) : ");  // prompt message on serial monitor for user
  while(Serial.available()==0); { }     // wait here until user enter input data
  int user_speed= Serial.parseInt();   // Read entered integer value and store it in a variable
  Serial.println(user_speed);    // print user speed on serial monitor
  motor.setSpeed(user_speed);  // Set stepper motor speed to user defined speed
}
 
void loop()
{ 
  Serial.println("clockwise"); // print text on serial monitor
  motor.step(stepsPerRevolution); // rotate motor in clockwise direction for one revolution
  delay(500);
 
  // step one revolution in the other direction:
  Serial.println("counterclockwise"); // print text on serial monitor
  motor.step(-stepsPerRevolution); // rotate motor in anticlockwise direction for one revolution
  delay(500);
}
