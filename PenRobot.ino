// Define stepper motor connections and steps per rev:
#define dirX 2
#define stepX 3

#define dirY 4
#define stepY 5

#define stepsPerRev 1600

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

  // Spin the stepper motor 1 rev quickly:
  for (int i = 0; i < steps; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(200);
  }
}


void xMove (uint8_t value) {axisMove(dirX, value, stepX, stepsPerRev * 20);}
void yMove (uint8_t value, int steps) {axisMove(dirY, value, stepY, steps);}
void makePass (uint8_t value) {xMove(value), yMove(LOW, stepsPerRev);}

void sixPasses () {
  //Pass 1, to the right.
  makePass(LOW),
  //Pass 2, to the left.
  makePass(HIGH),
  //Pass 3, right.
  makePass(LOW),
  //Pass 4, left.
  makePass(HIGH),
  //Pass 5, right.
  makePass(LOW),
  //Pass 6, back to the starting position.
  xMove(HIGH), yMove(HIGH, stepsPerRev * 5);
  }


void loop() {
  // Make a six passes
  sixPasses();
}
