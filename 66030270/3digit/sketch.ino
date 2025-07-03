// Segment pins
const int segA = 18;
const int segB = 5;
const int segC = 17;
const int segD = 16;
const int segE = 4;
const int segF = 19;
const int segG = 2;


const int digit1 = 15;
const int digit2 = 21;
const int digit3 = 22;


const byte digits[10] = {
  //GFEDCBA
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

void setup() {
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);

  // Turn off all digits
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, HIGH);
  digitalWrite(digit3, HIGH);
}

void displayDigit(int digit, int number) {
  byte segs = digits[number];

  digitalWrite(segA, segs & 0b00000001);
  digitalWrite(segB, (segs >> 1) & 0b1);
  digitalWrite(segC, (segs >> 2) & 0b1);
  digitalWrite(segD, (segs >> 3) & 0b1);
  digitalWrite(segE, (segs >> 4) & 0b1);
  digitalWrite(segF, (segs >> 5) & 0b1);
  digitalWrite(segG, (segs >> 6) & 0b1);

  // Activate the desired digit
  digitalWrite(digit, LOW);
  delay(3);
  digitalWrite(digit, HIGH);
}

void loop() {
  static int value = 0;
  int hundreds = (value / 100) % 10;
  int tens = (value / 10) % 10;
  int units = value % 10;

  displayDigit(digit1, hundreds);
  displayDigit(digit2, tens);
  displayDigit(digit3, units);

  delay(5);

  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate > 500) {
    value = (value + 1) % 1000;
    lastUpdate = millis();
  }
}
