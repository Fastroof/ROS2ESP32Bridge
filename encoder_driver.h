#define LEFT_ENC_PIN_A 23
#define RIGHT_ENC_PIN_A 18
   
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();

void IRAM_ATTR ISR_LeftEncoder();
void IRAM_ATTR ISR_RightEncoder(); 
