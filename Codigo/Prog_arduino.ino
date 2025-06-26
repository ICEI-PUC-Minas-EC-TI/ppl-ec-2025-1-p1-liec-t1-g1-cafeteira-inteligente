#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h> // Para comunicação com o módulo Bluetooth

#define ONE_WIRE_BUS 8 // Pino digital onde o DS18B20 está conectado
#define RELAY_PIN 9    // Pino digital onde o relé está conectado

SoftwareSerial bluetooth(2, 3); // RX do Arduino, TX do Arduino

// Setup OneWire e DallasTemperature
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600); // Inicializa comunicação serial para depuração (Serial Monitor)
  Serial.println("Inicializando...");

  sensors.begin();
  Serial.print("Total de dispositivos OneWire encontrados: ");
  Serial.println(sensors.getDeviceCount());

  // Configura o pino do relé como saída e o mantém desligado inicialmente
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Garante que o relé comece desligado

  bluetooth.begin(9600);
  Serial.println("Bluetooth iniciado em 9600 bps.");
}

void loop() {
  // Solicita a temperatura do sensor DS18B20
  sensors.requestTemperatures();

  // Lê a temperatura em Celsius do primeiro sensor encontrado (índice 0)
  float tempC = sensors.getTempCByIndex(0);

  // Verifica se a leitura foi bem-sucedida
  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("Erro: Nao foi possivel ler a temperatura do DS18B20!");
  } else {
    // Prepara a string para enviar via Bluetooth
    String tempString = String(tempC, 2); // Converte float para String com 2 casas decimais
    tempString += "\n"; // Adiciona nova linha como terminador

    // Envia a string de temperatura para o módulo Bluetooth
    if (bluetooth.isListening()) { // Verifica se o SoftwareSerial está ativo
      bluetooth.print(tempString);
      //Serial.print("Enviado via Bluetooth: ");
      //Serial.print(tempString);
    } else {
      Serial.println("SoftwareSerial nao esta ativo para Bluetooth.");
    }
  }

  // --- Controle do Relé ---
  // Verifica se há dados disponíveis para ler do Bluetooth
  if (bluetooth.available()) {
    char receivedChar = bluetooth.read(); // Lê o caractere recebido

    if (receivedChar == 'L') {
      digitalWrite(RELAY_PIN, LOW); // Liga o relé
      Serial.println("Relé LIGADO (via Bluetooth: L)");
    } else if (receivedChar == 'D') {
      digitalWrite(RELAY_PIN, HIGH);  // Desliga o relé
      Serial.println("Relé DESLIGADO (via Bluetooth: D)");
    }
  }
  // --- Fim do Controle do Relé ---

  // Pequeno atraso antes da próxima leitura/envio
  delay(100); // Envia a cada 0,1 segundos e verifica o Bluetooth
}
