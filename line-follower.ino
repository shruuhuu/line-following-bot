// IR Sensor pins
const int leftSensorPin = 10;
const int rightSensorPin = 9;

// Motor control pins
const int enA = 3; // PWM pin for Motor A
const int in2 = 4;
const int in1 = 5;
const int enB = 8; // PWM pin for Motor B
const int in3 = 6;
const int in4 = 7;

void setup() {
  // Initialize sensor pins as input
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  // Initialize motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set initial motor speeds
  analogWrite(enA, 255); // Full speed for Motor A
  analogWrite(enB, 255); // Full speed for Motor B

  Serial.begin(9600);
}

void loop() {
  // Read the sensor values
  int leftStatus = digitalRead(leftSensorPin);
  int rightStatus = digitalRead(rightSensorPin);

  // Print the sensor values to the serial monitor
  Serial.print("Left Sensor: ");
  Serial.print(leftStatus);
  Serial.print("  |  Right Sensor: ");
  Serial.println(rightStatus);

  // Line following logic
  if (leftStatus == HIGH && rightStatus == HIGH) {
    // Move forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 255); // Full speed for Motor A   
    analogWrite(enB, 255); // Full speed for Motor B
  } else if (leftStatus == HIGH && rightStatus == LOW) {
    // Turn left
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 150); // Full speed for Motor A
    analogWrite(enB, 0); // Full speed for Motor B
  } else if (leftStatus == LOW && rightStatus == HIGH) {
    // Turn right
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0); // Full speed for Motor A
    analogWrite(enB, 150); // Full speed for Motor B
  } else {
    // Stop
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0); // Stop Motor A
    analogWrite(enB, 0); // Stop Motor B
  }

  delay(100); // Small delay for stability
}

