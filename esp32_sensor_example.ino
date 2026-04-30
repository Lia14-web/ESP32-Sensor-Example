/*
 * ESP32 - Simple Sensor Data Simulation
 * Demonstrates: setup(), loop(), serial communication, analog reading
 */

const int ledPin = 2;  // Built-in LED on ESP32 boards
int sensorValue = 0;
unsigned long lastPrintTime = 0;
const unsigned long printInterval = 1000; // Print every 1 second

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println("ESP32 Virtual Sensor Ready...");
  Serial.println("------------------------------");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (millis() - lastPrintTime >= printInterval) {
    lastPrintTime = millis();
    
    // Read from an analog pin (pin 34 is safe, has no internal pull-up)
    sensorValue = analogRead(34);
    
    // Convert to simulated voltage (ESP32 is 3.3V, 12-bit ADC: 0-4095)
    float voltage = (sensorValue / 4095.0) * 3.3;
    
    Serial.print("Time (ms): ");
    Serial.print(millis());
    Serial.print(" | Raw ADC: ");
    Serial.print(sensorValue);
    Serial.print(" | Voltage: ");
    Serial.print(voltage, 2);
    Serial.println(" V");
    
    // Blink LED to show system is active
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
  }
}
