int trigpinlame_sensor=A0;
int flame_sensor=7;



void setup() {
  serial.begin(115200);
piMode(buzzer,OUTPUT);
pinMode(flame_sensor,INPUT)
}

void loop() {
   sensed=analogRead(flame_sensor)
   if(sensed==HIGH){
    Serial.println("danger")
   }else{
    Serial.println("no danger")
   }
  serial.println("flame is detected")
  // put your main code here, to run repeatedly:
}
