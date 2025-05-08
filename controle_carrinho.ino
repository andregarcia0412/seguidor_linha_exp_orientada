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
  //fazer o mapping do pwm de 0 a 1000
  int pwm = 200;
  int timer = 225;
  Serial.println(pwm, timer);
   if(bluetooth.available() > 0)
   {
	char direcao = bluetooth.read();
    if (direcao == '1') {
    analogWrite(7,pwm);
    digitalWrite(6,LOW);
    analogWrite(5,pwm);
    digitalWrite(4,LOW);
    Serial.println("LIGADO");
    }
    if (direcao == '0') {
    digitalWrite(7,LOW);
    analogWrite(6,pwm);
    digitalWrite(5,LOW);
    analogWrite(4,pwm);
    Serial.println("DESLIGADO");
    }

    if (direcao == '3'){
      digitalWrite(7,LOW);
      analogWrite(6,pwm);
      analogWrite(5,pwm);
      digitalWrite(4,LOW);
      Serial.println("DIREITA");
      delay(timer);
      direcao = '4';
    }
    if (direcao == '2'){
      analogWrite(7,pwm);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      analogWrite(4,pwm);
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
      analogWrite(6,pwm);
      analogWrite(5,pwm);
      digitalWrite(4,LOW);
      Serial.println("FULL RIGHT");
    }
    if (direcao == '6'){
      analogWrite(7,pwm);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      analogWrite(4,pwm);
      Serial.println("FULL LEFT");
    }
    if (direcao == '7'){
      pwm += 100;
      timer += 25;
      if(pwm > 1000){
        pwm = 1000;
        timer -= 25;
      }
    if (direcao == '8'){
      pwm -= 100;
      timer -= 25;
      if(pwm < 0){
        pwm = 0;
        timer -= 25;
      }
    }
    }
} }
