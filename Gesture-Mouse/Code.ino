#include <Wire.h>
#include <MPU6050_tockn.h>
#include <BleMouse.h>

MPU6050 mpu(Wire);
BleMouse bleMouse("Gesture Mouse", "VR Creations", 100);

//  Pins 
#define LEFT_CLICK  18
#define RIGHT_CLICK 19

//  Calibration 
float pitchOffset = 0;
float rollOffset  = 0;

//  Tuning (DPI ~800–1600 feel) 
float sensitivity  = 1.0;
float deadZone     = 6.0;
float smoothFactor = 0.18;


// smoothing variables
float smoothX = 0;
float smoothY = 0;

void calibrateIMU() {
  Serial.println("Calibrating... Keep board flat");
  delay(2000);

  float pitchSum = 0;
  float rollSum = 0;

  for (int i = 0; i < 200; i++) {
    mpu.update();
    pitchSum += mpu.getAngleX();
    rollSum  += mpu.getAngleY();
    delay(5);
  }

  pitchOffset = pitchSum / 200.0;
  rollOffset  = rollSum / 200.0;

  Serial.println("Calibration done");
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(LEFT_CLICK, INPUT_PULLUP);
  pinMode(RIGHT_CLICK, INPUT_PULLUP);

  mpu.begin();
  mpu.calcGyroOffsets(true);

  calibrateIMU();

  bleMouse.begin();
  Serial.println("BLE Gesture Mouse Ready");
}

void loop() {
  mpu.update();

  if (!bleMouse.isConnected()) return;

  // Read angles
  float pitch = mpu.getAngleX() - pitchOffset;
  float roll  = mpu.getAngleY() - rollOffset;

  // Dead zone
  if (abs(pitch) < deadZone) pitch = 0;
  if (abs(roll)  < deadZone) roll  = 0;

  // Smoothing (low-pass filter)
  smoothX += (roll  - smoothX) * smoothFactor;
  smoothY += (pitch - smoothY) * smoothFactor;

  // Dynamic speed (natural feel)
  float speedX = abs(smoothX) > 15 ? 2.0 : sensitivity;
  float speedY = abs(smoothY) > 15 ? 2.0 : sensitivity;

  int moveX = smoothX * speedX;
  int moveY = smoothY * speedY;
  // Fine control for small movements (slow micro-motions)
if (abs(smoothX) < 10) moveX *= 0.7;
if (abs(smoothY) < 10) moveY *= 0.7;


  // Limit movement (important!)Z : -0.03

  moveX = constrain(moveX, -8, 8);
  moveY = constrain(moveY, -8, 8);


  // Move mouse
  if (moveX != 0 || moveY != 0) {
    bleMouse.move(moveX, moveY);
  }

  //  Clicks 
  if (digitalRead(LEFT_CLICK) == LOW)
    bleMouse.press(MOUSE_LEFT);
  else
    bleMouse.release(MOUSE_LEFT);

  if (digitalRead(RIGHT_CLICK) == LOW)
    bleMouse.press(MOUSE_RIGHT);
  else
    bleMouse.release(MOUSE_RIGHT);

  delay(8); // controls update rate
}
