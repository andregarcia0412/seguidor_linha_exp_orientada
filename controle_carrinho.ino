#include <SoftwareSerial.h>
//app inventor aula 9
// Definição dos pinos para comunicação com o módulo Bluetooth
int bluetoothTx = 9;  // Pino TX do módulo Bluetooth conectado ao RX do Arduino
int bluetoothRx = 8;  // Pino RX do módulo Bluetooth conectado ao TX do Arduino

// Inicialização do objeto para comunicação Bluetooth
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);


void setup() 
{
  // Inicialização da comunicação serial padrão (para comunicação com o computador via USB)
  Serial.begin(9600);
  
  // Inicialização da comunicação serial com o módulo Bluetooth
  bluetooth.begin(9600);

  // Motor Esquerdo
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}


void loop() 
{
  int timer = 150;
  // pedro: 125
  // andre: 150
  // dimitri: vai se fuder
  Serial.println(timer);
   if(bluetooth.available() > 0)
   {
	char direcao = bluetooth.read();
    if (direcao == '1') {
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    Serial.println("LIGADO");
    }
    if (direcao == '0') {
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    Serial.println("DESLIGADO");
    }

    if (direcao == '3'){
      digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      Serial.println("DIREITA");
      delay(timer);
      direcao = '4';
    }
    if (direcao == '2'){
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
      Serial.println("ESQUERDA");
      delay(timer);
      direcao = '4';
    }
    if (direcao == '4'){
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      Serial.println("PARADO");
    }
    if (direcao == '5'){
      digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      Serial.println("FULL RIGHT");
    }
    if (direcao == '6'){
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
      Serial.println("FULL LEFT");
    }
    if(direcao == '7'){
      for(int i = 1; i <= 1000; i++){
        direcao = bluetooth.read();
        if(direcao == '4'){
          break;
        }
        digitalWrite(7,HIGH);
        digitalWrite(6,LOW);
        digitalWrite(5,LOW);
        digitalWrite(4,HIGH);
        delay(200);
        digitalWrite(7,LOW);
        digitalWrite(6,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(4,LOW);
        delay(200);
      }

      }
    }
    
} 
