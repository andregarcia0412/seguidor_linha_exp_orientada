#include <Servo.h>

int frente = 0;

int esquerda = 0;

int direita = 0;

Servo servo_4;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup() {
    //motor direito
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  //motor esquerdo
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  Serial.begin(9600);

  servo_4.attach(3, 500, 2500);

  direita = 0;
  esquerda = 0;
  frente = 0;
  servo_4.write(90);
  delay(100);

}

void loop() {
  int pwm = 180; //define a rotação dos motores, vai de 0 a 255

  if (frente <= 25){
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    servo_4.write(90);
    delay(500);
    frente = 0.01723 * readUltrasonicDistance(4,2);

    servo_4.write(180);
    delay(500);
    esquerda = 0.01723 * readUltrasonicDistance(4, 2);

    servo_4.write(0);
    delay(500);
    direita = 0.01723 * readUltrasonicDistance(4, 2);

    servo_4.write(90);
    delay(200);

    Serial.print("Frente: ");
    Serial.print(frente);
    Serial.print(" Direita: ");
    Serial.print(direita);
    Serial.print(" Esquerda: ");
    Serial.println(esquerda);
    Serial.println("-------------------------------------------------------------");
    if (direita > esquerda && direita > 50){
      andar_direita(200);
    } else if (esquerda > 50){
      andar_esquerda(200);
     } //else{
    //   andar_tras(200);
    // }

    delay(120);
  } else{
      frente = 0.01723 * readUltrasonicDistance(4, 2);
      andar_frente(200);
    }
  delay(200);
  }

  void andar_direita(int vel){
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
  void andar_esquerda(int vel){
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
  void andar_tras(int vel){
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
  void andar_frente(int vel){
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);   
  }
