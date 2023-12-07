#include <SoftwareSerial.h>

// Define the RX and TX pins for SoftwareSerial
#define RX_PIN 10
#define TX_PIN 11

// Create a SoftwareSerial object
SoftwareSerial gsmModule(RX_PIN, TX_PIN);

void setup() {
  // Start serial communication with the computer
  Serial.begin(9600);

  // Start serial communication with the GSM module
  gsmModule.begin(9600);

  // Provide time for the GSM module to initialize
  delay(2000);

  Serial.println("Setup complete. Ready to send SMS.");
}

void loop() {
  // Your main code goes here

  // Example: Sending an SMS
  sendSMS("+919353704302", "Hello from Arduino!");

  // Delay for a while
  delay(1000);
}

void sendSMS(String phoneNumber, String message) {
  // Command to set SMS mode
  gsmModule.println("AT+CMGF=1");
  delay(1000);

  // Command to set the recipient phone number
  gsmModule.print("AT+CMGS=\"");
  gsmModule.print(phoneNumber);
  gsmModule.println("\"");
  delay(1000);

  // Send the SMS message
  gsmModule.print(message);
  delay(1000);

  // Send Ctrl+Z to indicate the end of the message
  gsmModule.write(0x1A);
  delay(1000);
}
