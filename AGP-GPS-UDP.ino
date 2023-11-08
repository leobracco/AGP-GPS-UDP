#include <WiFi.h>
#include <AsyncUDP.h>

const char* ssid = "SSID";
const char* password = "PASWORD";
//Cambiar por el rango de ip de tu red
IPAddress multicastIP(192, 168, 1, 255);
const int multicastPort = 9999;
const int RXPin = 27;
const int baudRate = 115200;

AsyncUDP udp;

void setup() {
  Serial.begin(115200);
  Serial2.begin(baudRate, SERIAL_8N1, RXPin, -1); // Usamos Serial2 en el ESP32

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando a la red WiFi...");
  }
  
  Serial.println("Conectado a la red WiFi");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  if(udp.connect(multicastIP, multicastPort)) {
    Serial.println("UDP conectado a multicast");
  }
}

void loop() {
  static String nmeaSentence = "";
  while (Serial2.available()) {
    char inChar = (char)Serial2.read();
    nmeaSentence += inChar;

    // Verificar si el carácter es un fin de línea, lo que indica el final de una sentencia NMEA
    if (inChar == '\n') {
      udp.write((uint8_t*)nmeaSentence.c_str(), nmeaSentence.length());
      nmeaSentence = ""; // Limpiar la sentencia para la próxima lectura
    }
  }
}
