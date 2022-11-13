// Define stepper motor connections and steps per revolution:
#define dirX 2
#define stepX 3

#define dirY 4
#define stepY 5

#define stepsPerRevolution 1600

void setup() {
  // Declare pins as output:
  pinMode(stepX, OUTPUT);
  pinMode(stepY, OUTPUT);
  pinMode(dirX, OUTPUT);
  pinMode(dirY, OUTPUT);
}

void axisMove (uint8_t function_dirPin, uint8_t value, int stepPin, int steps) {
  // Set the spinning direction counter-clockwise:
  digitalWrite(function_dirPin, value);

  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < steps; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(200);
  }
}



void loop() {

  // Make a pass to the right by 20 stepsPerRevolution
  axisMove(dirX, LOW, stepX, stepsPerRevolution * 20);


  // Move blade forward
  axisMove(dirY, LOW, stepY, stepsPerRevolution/2);
  

  // Make a pass to the left by 20 stepsPerRevolution
  axisMove(dirX, HIGH, stepX, stepsPerRevolution * 20);


  // Move blade forward second time
  axisMove(dirY, LOW, stepY, stepsPerRevolution/2);


  // Make a pass to the right by 20 stepsPerRevolution
  axisMove(dirX, LOW, stepX, stepsPerRevolution * 20);


  // Move blade forward third time
  axisMove(dirY, LOW, stepY, stepsPerRevolution/2);


  // Make a pass to the left by 20 stepsPerRevolution
  axisMove(dirX, HIGH, stepX, stepsPerRevolution * 20);


  // Move blade forward fourth time
  axisMove(dirY, LOW, stepY, stepsPerRevolution/2);


  // Make a pass to the right by 20 stepsPerRevolution
  axisMove(dirX, LOW, stepX, stepsPerRevolution * 20);


  // Move blade forward fifth time
  axisMove(dirY, LOW, stepY, stepsPerRevolution/2);
  

  // Make a pass to the left by 20 stepsPerRevolution
  axisMove(dirX, HIGH, stepX, stepsPerRevolution * 20);
  

  // Move blade back to starting position
  axisMove(dirY, HIGH, stepY, 4000);

}
