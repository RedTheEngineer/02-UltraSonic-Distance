


  const int trigPin = 9;
  const int echoPin = 10;

  const int yellowLED =6;
  const int redLED= 7;
  const int buzzerPin=8;


  unsigned long duration;

  unsigned long previousBlinkTime = 0;
  const unsigned long blinkInterval = 500;
  bool yellowState = false;


 float distance;

void setup() {
  // put your setup code here, to run once:


  pinMode(yellowLED,OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin,OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();


  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

 duration = pulseIn(echoPin, HIGH, 30000);

 if(duration == 0){
   digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    noTone(buzzerPin);
    yellowState = false;
     previousBlinkTime = currentTime;

 }else{





distance = (duration * 0.0343 )/ 2;
   Serial.println(distance);
   

   if(distance <= 30){

    yellowState = false;
    previousBlinkTime = currentTime;

    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    tone(buzzerPin,1000);

   }else if(distance <= 100 && distance > 30){

     noTone(buzzerPin);
    digitalWrite(redLED, LOW);


       
    if (currentTime - previousBlinkTime >= blinkInterval) {
        yellowState = !yellowState;
        digitalWrite(yellowLED, yellowState);
        previousBlinkTime = currentTime;
    }




   }else{
    yellowState = false;
    previousBlinkTime = currentTime;


    digitalWrite(redLED, LOW);
     digitalWrite(yellowLED, LOW);
      noTone(buzzerPin);

   }



 }




   
}
