// orang rotatory encoder code
int encoderA = 2;  // encoder's channel A
int encoderB = 3;  // ''B
int count = 0;   // Counter for position
int aState;
int aLastState;  
int stateA=0;
int stateB=0;
int LStateA=0;
int LStateB=0;
void setup() {
  Serial.begin(9600);
  pinMode(encoderA, INPUT_PULLUP);  // A at HIGH
  pinMode(encoderB, INPUT_PULLUP);  // B ''
  attachInterrupt(digitalPinToInterrupt(encoderA), rotation, CHANGE);  // Only check when A goes from LOW-->HIGH
  attachInterrupt(digitalPinToInterrupt(encoderB), rotation, CHANGE);
  aLastState = digitalRead(encoderA);
}

void rotation() {
  stateA = digitalRead(encoderA);
  stateB = digitalRead(encoderB);
  if (stateA != LStateA) { 
      if(stateA != stateB){
        count++;
      }
      else{
        count--;
      }
  } 
  else{                             
    if(stateB != stateA){
        count--;
      }
      else{
        count++;
      }
  }
  LStateA = stateA;
  LStateB = stateB;
}

void loop() {
  aState = digitalRead(encoderA);
   if (aState != aLastState){     
     Serial.print("Position: ");
     Serial.println(count);
   } 
   aLastState = aState;
}