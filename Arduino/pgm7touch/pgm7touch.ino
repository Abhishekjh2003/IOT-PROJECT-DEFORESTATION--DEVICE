const int touchPin = 7; // T0 is one of the touch-enabled pins on ESP32

void setup() {
  Serial.begin(115200);
}

void loop() {
  int touchValue = touchRead(touchPin);

  Serial.print("Touch Value: ");
  Serial.println(touchValue);

  delay(1000); // You can adjust the delay as needed
}
