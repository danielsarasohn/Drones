int val;
void Speed()
{
  val = analogRead(A0);
  val = map(val, 680, 1023, 0, 255);
}
void turningSpeed()
{
  analogWrite(3, 255);
  analogWrite(3, 255);
}
void setup() {
  // put your setup code here, to run once:


  pinMode(4, OUTPUT); // left wheel
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT); // right wheel
  pinMode(8, OUTPUT);
  pinMode(3, OUTPUT); // speed control
  pinMode(6, OUTPUT);
  Serial.begin(9600);  
  analogWrite(3, val);
  analogWrite(6, val);
}

void off () {
  digitalWrite (5, LOW);
  digitalWrite (4, LOW);
  digitalWrite (8, LOW);
  digitalWrite (7, LOW);
}
void backwards (int x) {
  Speed();  
  off();
  Serial.print("bananab");
  analogWrite(3, val);
  analogWrite(6, val);
  digitalWrite (5, LOW);
  digitalWrite (4, HIGH);
  digitalWrite (8, HIGH);
  digitalWrite (7, LOW);
  delay(x);
  off();
}
void forwards (int d) {
  Speed();
  Serial.print("bananaf");
  analogWrite(3, val);
  analogWrite(6, val);
  off();
  digitalWrite (4, LOW);
  digitalWrite (5, HIGH);
  digitalWrite (7, LOW);
  digitalWrite (8, HIGH);
  delay(d);
  off();
}
void left() {
  Serial.print("bananal");
  turningSpeed();
  off();
  digitalWrite (8, LOW);
  digitalWrite (7, HIGH);
  digitalWrite (4, LOW);
  digitalWrite (5, LOW);
  delay(750);
  off();
}
void right() {
  turningSpeed();
  Serial.print("bananar");
  off();
  digitalWrite (5, LOW);
  digitalWrite (4, HIGH);
  digitalWrite (8, LOW);
  digitalWrite (7, LOW);
  delay(750);
  off();
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(3, val);
  analogWrite(6, val);
  backwards(5000);
  forwards(5000);
  left();
  right();
}
