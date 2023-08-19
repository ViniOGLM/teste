//Nesta pogramação vamos testar o bluetooh do ESP-32
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

char valorRecebido;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32 GOLIM"); 
  Serial.println("O dispositivo já pode ser pareado!");

  pinMode(13, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    valorRecebido =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
    
    if(valorRecebido == '1')
    {
     SerialBT.println("LED 1 ligado:");
     digitalWrite(13, HIGH);
     digitalWrite(LED_BUILTIN, HIGH);
    }
    if(valorRecebido == '2')
    {
     SerialBT.println("LED 1 desligado:");
      digitalWrite(13, LOW);
     digitalWrite(LED_BUILTIN, LOW);
    }    
  }
  delay(30);
}