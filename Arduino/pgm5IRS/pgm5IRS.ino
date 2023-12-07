int temp_sensor = 7;
void setup()
{
  pinMode(temp_sensor,INPUT);
}
void loop(){
int data=digitalRead(temp_sensor);
  Serial.println(data);
}