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
    switch (state) {
      case 'F':
        forward();
        soundFX(3000.0,30+400*(1+sin(millis()/5000)));
        break;
      case 'G':
        forwardleft();
        soundFX(3000.0,60);
        break;  
      case 'D':
        forwardright();
        soundFX(3000.0,60);
        break;  
      case 'N':
        backright();
        soundFX(3000.0,30+100*(1+sin(millis()/2500)));
        break;
      case 'C':
        backleft();
        soundFX(3000.0,30+100*(1+sin(millis()/2500)));
        soundFX(3000.0,30+100*(1+sin(millis()/2500)));
        soundFX(3000.0,30+100*(1+sin(millis()/2500)));
        soundFX(3000.0,30+100*(1+sin(millis()/2500)));
        break;
      case 'B':
        back();
        soundFX(3000.0,30+200*(1+sin(millis()/2500)));
        soundFX(3000.0,30+200*(1+sin(millis()/2500)));
        soundFX(3000.0,30+200*(1+sin(millis()/2500)));
        soundFX(3000.0,30+200*(1+sin(millis()/2500)));
        break;
      case 'L':
        left();
        soundFX(3000.0,60);
        soundFX(3000.0,60);
        soundFX(3000.0,60);
        soundFX(3000.0,60);
        break;
      case 'R':
        right();
        soundFX(3000.0,60);
        soundFX(3000.0,60);
        soundFX(3000.0,60);
        soundFX(3000.0,60);
        break;
      case 'H':
        soundFX(3000.0,30+200*(1+sin(millis()/2500)));
        soundFX(3000.0,60);
        soundFX(3000.0,30+200*(1+sin(millis()/2500)));
        soundFX(3000.0,60);
    }

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
void soundFX(float amplitude,float period){
 int uDelay=2+amplitude+amplitude*sin(millis()/period);
 for(int i=0;i<5;i++){
   digitalWrite(piezo,HIGH);
   delayMicroseconds(uDelay);
   digitalWrite(piezo,LOW);
   delayMicroseconds(uDelay);
 }
} 
