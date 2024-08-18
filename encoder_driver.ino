#include "globals.h"
volatile long left_enc_pos = 0L;
volatile long right_enc_pos = 0L;

/* Interrupt routine for LEFT encoder, taking care of actual counting */
void IRAM_ATTR ISR_LeftEncoder() {
  if (leftMotorDirection == FORWARD) { left_enc_pos++; } 
  else if (leftMotorDirection == BACKWARD) { left_enc_pos--; }
}

/* Interrupt routine for RIGHT encoder, taking care of actual counting */
void IRAM_ATTR ISR_RightEncoder() {
  if (rightMotorDirection == FORWARD) { right_enc_pos++; } 
  else if (rightMotorDirection == BACKWARD) { right_enc_pos--; }
}

/* Wrap the encoder reading function */
long readEncoder(int i) {
  if (i == LEFT) return left_enc_pos;
  else return right_enc_pos;
}

/* Wrap the encoder reset function */
void resetEncoder(int i) {
  if (i == LEFT){
    left_enc_pos=0L;
    return;
  } else { 
    right_enc_pos=0L;
    return;
  }
}

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}
