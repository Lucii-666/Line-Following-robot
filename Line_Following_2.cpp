// === Motor Pins ===
#define enA 11
#define in1 10
#define in2 9

#define enB 5
#define in3 7
#define in4 6

// === IR Sensor Pins ===
#define leftIR 3
#define rightIR 2

// === Speed ===
int speed = 50;

void setup() {
  Serial.begin(9600);

  // Motor setup
  pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);

  // IR sensor setup
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void loop() {
  int left = digitalRead(leftIR);
  int right = digitalRead(rightIR);

  // Debug output
  Serial.print("Left: "); Serial.print(left);
  Serial.print(" | Right: "); Serial.println(right);

  // === Logic ===
  if (left == LOW && right == LOW) {
    // Both sensors on black — Go straight
    forward();
  }
  else if (left == LOW && right == HIGH) {
    // Left on black, right on white — Turn left
    turnLeft();
  }
  else if (left == HIGH && right == LOW) {
    // Right on black, left on white — Turn right
    turnRight();
  }
  else {
    // Both on white — Stop or search
    stopMotors();
  }

  delay(10); // optional debounce
}

// === Motion Functions ===
void forward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
}

void turnRight() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void stopMotors() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
}
