#define in1 5
#define in2 6
#define in3 10
#define in4 11
int state;
int piezo = 3; 
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(piezo,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
    Stop();
  }
}
void forward() {
  analogWrite(in1, 255);
  analogWrite(in3, 255);
}
void forwardleft() {
  analogWrite(in1, 50);
  analogWrite(in3, 255);
}
void forwardright() {
  analogWrite(in1, 255);
  analogWrite(in3, 50);
}
void back() {
  analogWrite(in2, 255);
  analogWrite(in4, 255);
}
void backright() {
  analogWrite(in2, 50);
  analogWrite(in4, 255);
}
void backleft() {
  analogWrite(in2, 255);
  analogWrite(in4, 50);
}
void left() {
  analogWrite(in4, 255);
  analogWrite(in1, 255);
}
void right() {
  analogWrite(in3, 255);
  analogWrite(in2, 255);
}
void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}
} 
