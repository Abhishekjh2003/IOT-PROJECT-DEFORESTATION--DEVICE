
int led = 13;

void setup() {
  serial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() {
  digitalWrite(led,HIGH);
  serial.print("led is on");
  delay(2000);
  digitalWrite(led,LOW);
  serial.print("led is off")
  delay(2000);

}
