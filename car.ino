int val;
const int trigPin = A2; 
const int echoPin = A3;
float duration, distance;
void Speed () {
  val= analogRead (A0);
  val = map(val, 680, 1023, 0, 255);
}

void preauton()
{
  
}
void setup() {
  // put your setup code here, to run once:
pinMode(4, OUTPUT); // left wheel
pinMode(5, OUTPUT);
pinMode(7, OUTPUT); // right wheel
pinMode(8, OUTPUT);
pinMode(3, OUTPUT); // speed control
pinMode(6, OUTPUT);
pinMode (9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
}
void off (){
  for (int x=3; x++; x<11)
  digitalWrite (x , LOW);       
}
void sense (){
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(5); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH); 
 distance = duration/74/2;
  Serial.print("Distance: "); 
 Serial.println(distance); 
}
void backwards (int b) {
   off();
  Speed();
  analogWrite (3, val);
  analogWrite (6, val);
  digitalWrite (5, HIGH);
  digitalWrite (8, HIGH);
  delay(b);
}
void forwards (int f) {
   off();
  Speed();
  analogWrite (3, val);
  analogWrite (6,val);
  digitalWrite (4, HIGH);
  digitalWrite (7, HIGH);
  delay(f);
}
void right (int l) {
   off();
  Speed();
  analogWrite (3, val);
  analogWrite (6, val);
  digitalWrite (4, HIGH);

  delay(l);
 }
void left (int r){
    off();
  Speed();
  analogWrite (3, val);
  analogWrite (6, val);
  digitalWrite (7,HIGH);
  delay(r);
}
void autonomous () {
sense ();
if ( distance > 1)
{
forwards (1000);
}

else 
{ 
  right (1000); 
}
}
void controler () {
}

void loop() {
  forwards (5000);
}

