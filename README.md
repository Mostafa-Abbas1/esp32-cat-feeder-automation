**ESP32 Automated Cat Feeder

A remotely controlled cat feeder based on ESP32 and controlled via the Blynk App.


🎯 Project Description

This automated cat feeder allows me to feed my cat from anywhere in the world via a smartphone app. The project combines IoT technology with practical home automation.

## 🛠️ Hardware Components

- **ESP32 (USB-C)**
- **MG995 Servo Motor** (360° Continuous Rotation)
- **USB-C Power Supply for the motor** (or another power supply 5V/2A)
- Food container
- Connection cables

## 📡 Software & Technologies

- **Programming Language:** C++ (Arduino)
- **Platform:** Arduino IDE
- **Cloud Service:** Blynk IoT Platform
- **Libraries:**
  - WiFi.h
  - BlynkSimpleEsp32.h
  - ESP32Servo.h

## ⚙️ Features

- ✅ Remote control via smartphone (Android/iOS)
- ✅ Works from anywhere (outside home WiFi)
- ✅ Precise 360° rotation for controlled food portions
- ✅ Real-time status updates
- ✅ Reliable cloud connection

## 🔌 Circuit Diagram (only between the esp32 and the servo)
```
ESP32          Servo Motor
─────          ───────────
GND    ───────> GND (Black)
D32    ───────> Signal (Yellow)
```

## 📱 Installation & Setup

### 1. Build Hardware
- Connect servo to ESP32 (see circuit diagram)
- Connect USB-C cable

### 2. Configure Arduino IDE
```bash
# Install ESP32 Board Support
Boards Manager URL: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

### 3. Install Libraries
- Blynk (by Volodymyr Shymanskyy)
- ESP32Servo

### 4. Customize Code
- Insert Blynk Auth Token
- Enter WiFi credentials
- Adjust Template ID

### 5. Upload Code
- Board: ESP32 Dev Module


## 📊 Technical Details

- **WiFi Connection:** 2.4 GHz
- **Servo Control:** PWM signal via GPIO 32
- **Cloud Ping:** ~37ms
- **Power Consumption:** ~500mA (ESP32) + 2A (Servo under load)

## 🎓 Learnings & Challenges

- IoT communication with cloud platforms
- Hardware integration (microcontroller + servo)
- Remote control via internet
- Power management (power supply for servo)
- Troubleshooting GPIO pin configurations
- Understanding continuous rotation servos vs standard servos
  

## 📄 License

MIT License - see [LICENSE](LICENSE) file

## 👤 Author

**Mostafa Abbas**
- GitHub: [@Mostafa-Abbas1] (https://github.com/Mostafa-Abbas1)
- LinkedIn: [Your LinkedIn Profile]
- Email: mostafaabw2@gmail.com
