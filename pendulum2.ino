#define LIGHT 13
#define RECIEVE 2
#define SOUND 3


void setup() {
  // put your setup code here, to run once:
  pinMode(LIGHT, OUTPUT);
  pinMode(RECIEVE, INPUT);
  Serial.begin(57600);
  attachInterrupt(digitalPinToInterrupt(RECIEVE), catchTime, FALLING);
  pinMode(SOUND, OUTPUT);
  digitalWrite(LIGHT, HIGH);
}

//testing line

long lastmillis = 0;
bool flag = false;
void catchTime () {
  if(flag == false){
    lastmillis = millis();
    flag = true;
  }
}

  
void loop() {
  // put your main code here, to run repeatedly:
  if(flag){
    digitalWrite(SOUND, HIGH);
    Serial.println(lastmillis);
    delay(200);
    digitalWrite(SOUND, LOW);
    flag = false;
  }

}
