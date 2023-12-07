#include <SoftwareSerial.h>

// Pin configuration for GSM module
#define GSM_TX 7
#define GSM_RX 8

SoftwareSerial gsmSerial(GSM_TX, GSM_RX);



// Phone number to send SMS
char phoneNumber[] = "+919632747119";  

void setup() {
  Serial.begin(9600);
  gsmSerial.begin(9600);
}

void loop()  {
    sendSMS("Deforestation alert! immediate action required.");
    delay(1000); 
}

void sendSMS(const char *message) {
  // Send AT commands to configure GSM module
  gsmSerial.println("AT");
  delay(1000);
  gsmSerial.println("AT+CMGF=1"); // Set the SMS mode to text
  delay(1000);
  
  // Compose the SMS message
  gsmSerial.print("AT+CMGS=\"");
  gsmSerial.print(phoneNumber);
  gsmSerial.println("\"");

  delay(1000);
  gsmSerial.println(message);

  delay(1000);
  gsmSerial.write(26); // Send Ctrl+Z to indicate the end of the message
  delay(1000);
}