// Define sensor pins and motor speeds
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enA 10
#define enB 5

int M1_Speed = 180; // Speed of motor 1
int M2_Speed = 180; // Speed of motor 2
int LeftRotationSpeed = 250;  // Left Rotation Speed
int RightRotationSpeed = 250; // Right Rotation Speed

void setup() {
  // Initialize motor control pins and sensor pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(A0, INPUT); // Left sensor
  pinMode(A1, INPUT); // Right sensor
  pinMode(A2, INPUT); // Front sensor (optional)
}

void loop() {
  // Read sensor values
  int LEFT_SENSOR = digitalRead(A0);
  int RIGHT_SENSOR = digitalRead(A1);
  int FRONT_SENSOR = digitalRead(A2); // Optional front sensor

  // Make decision based on sensor inputs
  makeDecision(LEFT_SENSOR, RIGHT_SENSOR, FRONT_SENSOR);

 
}

void makeDecision(int leftSensor, int rightSensor, int frontSensor) {
  if (leftSensor == LOW && rightSensor == LOW && frontSensor == LOW){
    // Handle intersections or obstacles
   
    slightLeft();
  }
  else if (leftSensor == LOW && rightSensor == LOW) {
    // Both sensors on the line
    forward();
  } else if (leftSensor == LOW && rightSensor == HIGH) {
    // Right sensor off the line
    slightLeft();
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    // Left sensor off the line
    slightRight();
  } 
   else if (leftSensor == HIGH && rightSensor == HIGH && frontSensor == HIGH){
    // Handle intersections or obstacles
  
    forward();
  }
  

}

void forward() {
  // Motor control to move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, M1_Speed);
  analogWrite(enB, M2_Speed);
}

void slightRight() {
  // Motor control for slight right turn
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, LeftRotationSpeed);
  analogWrite(enB, RightRotationSpeed);
}

void slightLeft() {
  // Motor control for slight left turn
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, LeftRotationSpeed);
  analogWrite(enB, RightRotationSpeed);
}

void stopMovement() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

