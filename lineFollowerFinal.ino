#define NUM_SENSORS 8     //number of sensors used
#define MIN_SPEED 200     //min speed
#define MAX_SPEED 255     //max speed
int sensor[NUM_SENSORS] = {2, 3, A5, A4, A3, A2, A1, A0}; //1, 2, 3, 4, 5, 6, 7, 8 sensor pins

int enable1 = 9;  // Enable Pin for motor 1
int enable2 = 10; // Enable Pin for motor 2

int motor1Pin1 = 7; //motor left
int motor1Pin2 = 8;
int motor2Pin1 = 13; //motor right
int motor2Pin2 = 12;

void setup() {
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  for (int i = 0; i < NUM_SENSORS; i++)
    pinMode(sensor[i], INPUT);
  setMotors(0, 0);
}

int lastSpeed = 0;

void loop() {
  int sensorValues[NUM_SENSORS];
  int isOut = 0;

  for (int i = 0; i < NUM_SENSORS; i++) {
    sensorValues[i] = digitalRead(sensor[i]);
    isOut += sensorValues[i];
  }

  int motorSpeed = 500 * sensorValues[0] + 200 * sensorValues[1] + 100 * sensorValues[2]
                   - 100 * sensorValues[5] - 200 * sensorValues[6] - 500 * sensorValues[7];
  motorSpeed = 2 * motorSpeed + 5 * (motorSpeed - lastSpeed);
  lastSpeed = motorSpeed;

  if (isOut == 0 && lastSpeed == 0) //off track
    setMotors(0, 0);
  else {
    int leftMotorSpeed = MIN_SPEED + motorSpeed;
    int rightMotorSpeed = MIN_SPEED - motorSpeed;

    // set motors speed using the two variables above
    setMotors(leftMotorSpeed, rightMotorSpeed);
  }
}

void setMotors(int motor1Speed, int motor2Speed) {
  //make sure to not exceed the lower and upper bounds
  if (motor1Speed > MAX_SPEED) motor1Speed = MAX_SPEED;
  if (motor2Speed > MAX_SPEED) motor2Speed = MAX_SPEED;
  if (motor1Speed < 0) motor1Speed = 0;
  if (motor2Speed < 0) motor2Speed = 0;

  analogWrite(enable1, motor1Speed);
  analogWrite(enable2, motor2Speed);

  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}
