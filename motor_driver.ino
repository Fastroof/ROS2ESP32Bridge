void initMotorController() {
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT); 
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT); 
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_ENABLE, OUTPUT); 
  pinMode(LEFT_MOTOR_ENABLE, OUTPUT);

  digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
  digitalWrite(LEFT_MOTOR_ENABLE, HIGH);

  // Setup PWM for ESP32
  ledcAttach(LEFT_MOTOR_FORWARD, PWM_FREQ, PWM_RES);
  ledcAttach(LEFT_MOTOR_BACKWARD, PWM_FREQ, PWM_RES);
  ledcAttach(RIGHT_MOTOR_FORWARD, PWM_FREQ, PWM_RES);
  ledcAttach(RIGHT_MOTOR_BACKWARD, PWM_FREQ, PWM_RES);
}

void setMotorSpeed(int i, int spd) {
  unsigned char reverse = 0;

  if (spd < 0)
  {
    spd = -spd;
    reverse = 1;
  }
  if (spd > 255)
    spd = 255;

  if (i == LEFT) {
    if      (reverse == 0 && spd > 0) { ledcWrite(LEFT_MOTOR_FORWARD, spd); ledcWrite(LEFT_MOTOR_BACKWARD, 0); leftMotorDirection = FORWARD;}
    else if (reverse == 1) { ledcWrite(LEFT_MOTOR_BACKWARD, spd); ledcWrite(LEFT_MOTOR_FORWARD, 0); leftMotorDirection = BACKWARD;}
    else { ledcWrite(LEFT_MOTOR_FORWARD, 0); ledcWrite(LEFT_MOTOR_BACKWARD, 0); leftMotorDirection = STOPPED; }
  }
  else /*if (i == RIGHT) //no need for condition*/ {
    if      (reverse == 0 && spd > 0) { ledcWrite(RIGHT_MOTOR_FORWARD, spd); ledcWrite(RIGHT_MOTOR_BACKWARD, 0); rightMotorDirection = FORWARD;}
    else if (reverse == 1) { ledcWrite(RIGHT_MOTOR_BACKWARD, spd); ledcWrite(RIGHT_MOTOR_FORWARD, 0); rightMotorDirection = BACKWARD;}
    else { ledcWrite(RIGHT_MOTOR_BACKWARD, 0); ledcWrite(RIGHT_MOTOR_FORWARD, 0); rightMotorDirection = STOPPED; }
  }
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  setMotorSpeed(LEFT, leftSpeed);
  setMotorSpeed(RIGHT, rightSpeed);
}
