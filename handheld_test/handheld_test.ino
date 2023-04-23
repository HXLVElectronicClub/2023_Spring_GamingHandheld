#include "LedControl.h"

/////////COPY THIS SECTION ///////////
/* Joystick PINs */
#define JOY_SW      26
#define JOY_VRY     25
#define JOY_VRX     33
#define JOY_5V      32
#define JOY_GND     27

// Handle different hardware variation
// X direction needs reverse
//#define REVERSE_X
// Y direction needs reverse
#define REVERSE_Y
// need to swap X and Y
//#define SWAP_X_Y

/* Display PINs */
#define LED1_CLK     4
#define LED1_CS      16
#define LED1_DIN     17

#define LED2_CLK     21
#define LED2_CS      22
#define LED2_DIN     23

#define BTNP 19
#define BTNN 18
////////END OF COPY ///////////////

#define LED_BUILTIN 2

LedControl lc1 = LedControl(LED1_DIN, LED1_CLK, LED1_CS, 1);
LedControl lc2 = LedControl(LED2_DIN, LED2_CLK, LED2_CS, 1);

void setup() {
  Serial.begin(9600);
  
  pinMode(JOY_SW, INPUT_PULLUP);
  pinMode(JOY_VRX, INPUT);
  pinMode(JOY_VRY, INPUT);
  pinMode(JOY_5V,OUTPUT);
  digitalWrite(JOY_5V,1);
  pinMode(JOY_GND,OUTPUT);
  digitalWrite(JOY_GND,0);

  pinMode(BTNP, INPUT_PULLUP);
  pinMode(BTNN, OUTPUT);
  digitalWrite(BTNN, 0);

  lc1.shutdown(0, false);
  lc1.setIntensity(0, 4);
  
  lc2.shutdown(0, false);
  lc2.setIntensity(0, 4);
}

int state = 0;
void loop() {
   if (state == 0) {
    testLed();
    state = 1;
  } else {
    testControl();
  }
}

void testLed() {
  digitalWrite(LED_BUILTIN,1);
  Serial.println("Testing LED...\n");
  for (int r = 0; r<16; r++) {
    for (int c = 0; c < 8; c++) {
         if (r < 8) {
          lc1.setLed(0,r,c,1);
         } else {
          lc2.setLed(0,r-8,c,1);
         }
         delay(100);
    }
    //digitalWrite(LED_BUILTIN,~digitalRead(LED_BUILTIN));
  }
  
  digitalWrite(LED_BUILTIN,0);
}

void testControl() {
  int rawx = analogRead(JOY_VRX);
  int rawy = analogRead(JOY_VRY);
#ifdef SWAP_X_Y
  int dx = map(rawy, 0, 4095, 0, 7);
  int dy = map(rawx, 0, 4095, 0, 7);
#else
  int dx = map(rawx, 0, 4095, 0, 7);
  int dy = map(rawy, 0, 4095, 0, 7);
#endif
#ifdef REVERSE_X
  dx = 7-(dx);
#endif
#ifdef REVERSE_Y
  dy = 7-(dy);
#endif

  int sw = digitalRead(JOY_SW);
  int btn = digitalRead(BTNP);

  Serial.print("VRX=");
  Serial.print(rawx);
  Serial.print("\tVRY=");
  Serial.print(rawy);
  Serial.print("\tdx=");
  Serial.print(dx);
  Serial.print("\tdy=");
  Serial.print(dy);
  Serial.print("\tSW=");
  Serial.print(sw);
  Serial.print("\tbtn=");
  Serial.print(btn);
  Serial.println();

  lc1.clearDisplay(0);
  lc1.setLed(0,dx, dy, 1);
  lc2.clearDisplay(0);
  
  if (sw == 0 
    || btn == 0
  ) {
    lc2.setRow(0,3,0x18);
    lc2.setRow(0,4,0x18);
    delay(50);
    lc2.setRow(0,2,0x18);
    lc2.setRow(0,3,0x24);
    lc2.setRow(0,4,0x24);
    lc2.setRow(0,5,0x18);
  } 

  delay(100);
}
