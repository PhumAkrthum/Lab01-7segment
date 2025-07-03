
const int segmentA = 18;
const int segmentB = 5;
const int segmentC = 17;
const int segmentD = 16;
const int segmentE = 4;
const int segmentF = 0; 
const int segmentG = 2;
const int segmentDP = 15; 


const int numbers[10][8] = {
  // a, b, c, d, e, f, g, dp
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW},  // 0
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},   // 1
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW},   // 2
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW},   // 3
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW},   // 4
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW},   // 5
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  // 6
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},    // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}, // 8
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW}   // 9
};

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, Phum!");
  Serial.println("Hello, Kmitl");
  Serial.println("Starting 7-segment countdown...");

  
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT); 
}

void loop() {
  // นับเลข 0 ถึง 9
  for (int i = 0; i <= 9; i++) {
    displayNumber(i); // แสดงตัวเลข
    Serial.print("Displaying: ");
    Serial.println(i);
    delay(1000); 
  }
  
}


void displayNumber(int num) {
  
  if (num >= 0 && num <= 9) {
    digitalWrite(segmentA, numbers[num][0]);
    digitalWrite(segmentB, numbers[num][1]);
    digitalWrite(segmentC, numbers[num][2]);
    digitalWrite(segmentD, numbers[num][3]);
    digitalWrite(segmentE, numbers[num][4]);
    digitalWrite(segmentF, numbers[num][5]);
    digitalWrite(segmentG, numbers[num][6]);
    digitalWrite(segmentDP, numbers[num][7]); 
  } else {
    
    digitalWrite(segmentA, LOW);
    digitalWrite(segmentB, LOW);
    digitalWrite(segmentC, LOW);
    digitalWrite(segmentD, LOW);
    digitalWrite(segmentE, LOW);
    digitalWrite(segmentF, LOW);
    digitalWrite(segmentG, LOW);
    digitalWrite(segmentDP, LOW);
    Serial.println("Invalid number for display.");
  }
}
