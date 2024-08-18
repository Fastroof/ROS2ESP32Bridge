#define RIGHT_MOTOR_BACKWARD 26
#define LEFT_MOTOR_BACKWARD  14
#define RIGHT_MOTOR_FORWARD  27
#define LEFT_MOTOR_FORWARD   12
#define RIGHT_MOTOR_ENABLE   25
#define LEFT_MOTOR_ENABLE    13

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
