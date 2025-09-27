// Motor Driver Pins
#define ENA 9   // Left motor speed (PWM)
#define IN1 7   // Left motor direction
#define IN2 8   // Left motor direction
#define ENB 10  // Right motor speed (PWM)
#define IN3 5   // Right motor direction
#define IN4 4   // Right motor direction

// IR Sensor Pins
#define LEFT_IR 3    // Left IR sensor
#define RIGHT_IR 6   // Right IR sensor

// Motor Speed Settings
#define BASE_SPEED 50   // Base speed for motors (0-255)
#define TURN_SPEED 50    // Speed during turns
#define FAST_SPEED 50   // Speed for straight line

bool leftSensor = 0;
bool rightSensor = 0;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);
  
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  leftSensor = digitalRead(LEFT_IR);
  rightSensor = digitalRead(RIGHT_IR);
  
  if (!leftSensor && !rightSensor) {
    moveForward();
  }
  else if (!leftSensor && rightSensor) {
    turnRight();
  }
  else if (leftSensor && !rightSensor) {
    turnLeft();
  }
  else {
    moveForward();
  }
  
  delay(50);
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, FAST_SPEED);
  analogWrite(ENB, FAST_SPEED);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, TURN_SPEED);
  analogWrite(ENB, BASE_SPEED);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  analogWrite(ENA, BASE_SPEED);
  analogWrite(ENB, TURN_SPEED);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
