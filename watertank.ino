
const int trigPin = 16;
const int echoPin = 5;

#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  duration = pulseIn(echoPin, HIGH);
  
  
  distanceCm = duration * SOUND_VELOCITY/2;
  
  
  distanceInch = distanceCm * CM_TO_INCH;
  
  
  Serial.println(duration);
  delay(1000);
}
