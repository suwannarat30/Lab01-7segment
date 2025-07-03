#define SEG_A 19
#define SEG_B 18
#define SEG_C 5
#define SEG_D 17
#define SEG_E 16
#define SEG_F 4
#define SEG_G 0

// รูปแบบการเปิด segment สำหรับเลข 0-9 (1 = ON, 0 = OFF)
const byte digits[10][7] = {
  // A, B, C, D, E, F, G
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

int segmentPins[7] = { SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G };

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}

void clearDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], LOW); 
  }
}

void loop() {
  for (int i = 0; i <= 9; i++) {
    displayDigit(i);   // แสดงตัวเลข
    delay(1000);       // แสดง 1 วินาที
    clearDisplay();    // ดับหน้าจอ
    delay(300);        // พักก่อนแสดงเลขถัดไป
  } 
}

