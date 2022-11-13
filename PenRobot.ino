// Define stepper motor connections and steps per revolution:
#define dirPin 2
#define stepPin 3

#define dirPin2 4
#define stepPin2 5

#define stepsPerRevolution 1600

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}

void xPositive (uint8_t function_dirPin) {
  // Set the spinning direction counter-clockwise:
  digitalWrite(function_dirPin, LOW);

  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution * 20; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(200);
  }
}

void xNegative (uint8_t function_dirPin) {
  // Set the spinning direction counter-clockwise:
  digitalWrite(function_dirPin, HIGH);

  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution * 20; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(200);
  }
}

void yPositive (uint8_t function_dirPin) {
  // Set the spinning direction counter-clockwise:
  digitalWrite(function_dirPin, LOW);

  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < 800; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(200);
  }
}

void yNegative (uint8_t function_dirPin) {
  // Set the spinning direction counter-clockwise:
  digitalWrite(function_dirPin, HIGH);

  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < 2400; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(200);
  }
}




void loop() {

  // Make a pass to the right by 40 stepsPerRevolution
  xPositive(dirPin);
  xPositive(dirPin);


  // Move blade forward
  yPositive(dirPin2);
  
  // Make a pass to the left by 40 stepsPerRevolution
  xNegative(dirPin);
  xNegative(dirPin);


  // Move blade forward second time
  yPositive(dirPin2);


  // Make a pass to the right by 40 stepsPerRevolution
  xPositive(dirPin);
  xPositive(dirPin);


  // Move blade forward third time
  yPositive(dirPin2);


  // Make a pass to the left by 40 stepsPerRevolution
  xNegative(dirPin);
  xNegative(dirPin);
  
  
  // Move blade back to starting position
  yNegative(dirPin2);
}