/*
 * ESP32 Automated Cat Feeder
 * 
 * This project controls a servo motor to dispense cat food remotely
 * via the Blynk IoT platform.
 * 
 * Hardware:
 * - ESP32 (USB-C)
 * - MG995 Servo Motor (360° Continuous Rotation)
 * - USB-C Power Supply (5V/2A)
 * 
 * Setup Instructions:
 * 1. Create a Blynk account and new project
 * 2. Copy your Template ID, Template Name, and Auth Token from Blynk
 * 3. Replace the placeholders below with your credentials
 * 4. Enter your WiFi SSID and password
 * 5. In Blynk app, add a Button widget on Virtual Pin V1 (Mode: PUSH)
 * 6. Optionally add a Label widget on Virtual Pin V2 for status messages
 * 
 * Pin Configuration:
 * - Servo Signal (Yellow) → GPIO 32 (D32)
 * - Servo VCC (Red) → 5V
 * - Servo GND (Black) → GND
 */

// Blynk Configuration - Replace with your credentials
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID_HERE"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME_HERE"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN_HERE"

// Enable debug output (optional, helps with troubleshooting)
#define BLYNK_PRINT Serial

// Include required libraries
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

// WiFi Credentials - Replace with your network details
char ssid[] = "YOUR_WIFI_SSID";
char password[] = "YOUR_WIFI_PASSWORD";

// Servo Configuration
Servo catFeederServo;
const int servoPin = 32;  // GPIO pin connected to servo signal wire

// Button handler for Blynk (Virtual Pin V1)
// This function is called when the button in the Blynk app is pressed
BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  
  if (buttonState == 1) {
    Serial.println("Feeding started!");
    
    // Continuous Rotation Servo - Rotate forward for 3 seconds
    catFeederServo.write(0);  // Full speed forward
    delay(3000);  // Adjust this duration to control portion size
    
    // Stop the servo
    catFeederServo.write(90);  // 90 = stop position for continuous servos
    Serial.println("Feeding completed!");
    
    // Send confirmation message to app
    Blynk.virtualWrite(V2, "Food dispensed!");
  }
}

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  
  // Initialize servo
  catFeederServo.attach(servoPin);
  catFeederServo.write(90);  // Set to STOP position
  
  // Connect to Blynk cloud via WiFi
  Serial.println("Connecting to WiFi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  
  Serial.println("ESP32 ready!");
}

void loop() {
  // Run Blynk - handles all cloud communication
  Blynk.run();
}