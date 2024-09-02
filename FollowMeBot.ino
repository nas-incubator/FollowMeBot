// Define motor pins
int motorLeftBackward = 1;
int motorLeftForward = 2;

int motorRightBackward = 3;
int motorRightForward = 4;

// Define sensor pins
#define RIGHT_SENSOR 8
#define LEFT_SENSOR 9 


void setup() {
  // Set motor pins as output
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorRightBackward, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
//Speed Control
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  // Set sensor pins as input
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
}

void loop() {

  analogWrite(5,100); //left motor rpm
  analogWrite(6,100); //right motor rpm
  
  // Read sensor values
  int leftSensorValue = digitalRead(LEFT_SENSOR);
  int rightSensorValue = digitalRead(RIGHT_SENSOR);
  
  // Determine motor actions based on sensor values
  if (leftSensorValue == HIGH && rightSensorValue == HIGH) { //signal receiving on both sensor
    
    moveForward(); // Move forward
  } else if(leftSensorValue == LOW && rightSensorValue == HIGH){ //signal only receiving on right sensor
    
    turnRight(); // turns
  }else if(leftSensorValue == HIGH && rightSensorValue == LOW) //signal only on left sensor
  {
    turnLeft();
  }else
  {
    stop(); //both sensors are HIGH ie not receiving signals
  }
}

void moveForward() {
  
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  
}

void turnLeft()
{
  digitalWrite(motorLeftBackward, LOW);  //Turn left 
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorRightBackward, LOW);
  digitalWrite(motorRightForward, HIGH); 
  
}

void turnRight() {
 
  digitalWrite(motorLeftBackward, LOW);  //Turn Right 
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
  digitalWrite(motorRightForward, LOW); 
  

}

void stop()
{
  digitalWrite(motorLeftBackward, LOW);   
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorRightBackward, LOW);
  digitalWrite(motorRightForward, LOW); 
}






