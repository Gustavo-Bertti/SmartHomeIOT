#include <Arduino.h>
#include <driver/adc.h>
#include <WiFi.h>
#include <PubSubClient.h>

const int potPin = 34;  
const int ledPin = 26;  
const char* ssid = "nomeDoWifi";  
const char* password = "senhaDoWifi";  
const char* mqttServer = "http://localhost";  
const int mqttPort = 15672;  

WiFiClient espClient;
PubSubClient client(espClient);

float energiaConsumida = 0;  
unsigned long ultimoTempo = 0;

const unsigned long INTERVALO_MEDICAO = 3600000;  
void setupWiFi() {
  Serial.print("Conectando no Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Conectado ao Wi-Fi");
}

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Tentando se conectar ao MQTT...");
    if (client.connect("esp32_client")) {
      Serial.println("Conectado ao MQTT");
    } else {
      Serial.print("Falha na conexão. Código de erro: ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void piscarLed() {
  digitalWrite(ledPin, HIGH);
  delay(200);  
  digitalWrite(ledPin, LOW);
}

void setup() {
  Serial.begin(9600);
  delay(100);

  analogSetPinAttenuation(potPin, ADC_11db);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  setupWiFi();
  client.setServer(mqttServer, mqttPort);

  Serial.println("Iniciando teste de consumo de energia...");
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();  

  unsigned long tempoAtual = millis();
  
  
  if (tempoAtual - ultimoTempo >= INTERVALO_MEDICAO) {
    int valorPot = analogRead(potPin);
    Serial.print("Leitura do potenciômetro: ");
    Serial.println(valorPot);  
    
    if (valorPot == 0) {
      Serial.println("Aviso: Leitura do potenciômetro é zero! Verifique as conexões.");
      return;
    }

    float maxValorPot = 4095.0; 
    float maxConsumo = 30.0;    
    float percentual = valorPot / maxValorPot; 
    float taxaConsumo = percentual * maxConsumo;    

    float tempoDecorrido = INTERVALO_MEDICAO / 1000.0;  

    energiaConsumida += taxaConsumo * (tempoDecorrido / 3600);  
    ultimoTempo = tempoAtual;

    
    String payload = String("{\"totalEnergy\":") + energiaConsumida +
                     String(",\"user\":{\"userId\":0,\"name\":\"string\",\"email\":\"string\",\"password\":\"stringst\",\"createdAt\":\"2024-11-21\"}}");

    client.publish("energia/consumo", payload.c_str());  

    
    piscarLed();

    Serial.print("Total Energy: ");
    Serial.print(energiaConsumida, 1);  
    Serial.println(" kWh | Payload enviado:");
    Serial.println(payload);
  }
}
