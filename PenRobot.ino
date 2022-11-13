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


void xMove (uint8_t value) {axisMove(dirX, value, stepX, stepsPerRev * 10);}
void yMove (uint8_t value, int steps) {axisMove(dirY, value, stepY, steps);}

void sixPasses () {
  //Pass 1
  xMove(LOW), yMove(LOW, stepsPerRev),
  //Pass 2
  xMove(HIGH), yMove(LOW, stepsPerRev),
  //Pass 3
  xMove(LOW), yMove(LOW, stepsPerRev),
  //Pass 4
  xMove(HIGH), yMove(LOW, stepsPerRev),
  //Pass 5
  xMove(LOW), yMove(LOW, stepsPerRev),
  //Pass 6
  xMove(HIGH), yMove(HIGH, stepsPerRev * 5);
  }


void loop() {

  // Make a six passes
  sixPasses();

}
