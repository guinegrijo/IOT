#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "IIIII";
const char* password = "bonas341";

const char* mqttServer = "172.20.10.6"; // IP do seu servidor MQTT
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");

  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    while (!client.connect("ESP32_Client")) {
      Serial.println("Tentando conectar ao MQTT...");
      delay(1000);
    }
    Serial.println("Conectado ao MQTT");
  }

  // Enviar dados
  String payload = "{\"sensor\": \"temperatura\", \"valor\": 23.5}";
  client.publish("iot/esp32", payload.c_str());

  delay(5000);
}