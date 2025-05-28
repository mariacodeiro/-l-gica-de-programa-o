#include <Servo.h>

// Definições dos pinos
const int LED_VERMELHO = 10;
const int LED_VERDE = 7;
const int LEDS_AZUIS[] = {2, 3, 4};
const int SERVO_PIN = 12;

Servo servoPorta;

int acertos = 0;
int tentativas = 0;
bool portaAberta = false;

// Funções auxiliares
void piscarLED(int pino, int vezes, int tempo = 300) {
  for (int i = 0; i < vezes; i++) {
    digitalWrite(pino, HIGH);
    delay(tempo);
    digitalWrite(pino, LOW);
    delay(tempo);
  }
}

void acenderJoia(int nivel) {
  if (nivel >= 1 && nivel <= 3) {
    digitalWrite(LEDS_AZUIS[nivel - 1], HIGH);
  }
}

void abrirPortaSabedoria() {
  portaAberta = true;

  Serial.println("\n✨ PARABÉNS! Você conquistou as 3 joias sagradas!");
  Serial.println("🛕 A Porta da Sabedoria está se abrindo...");

  for (int angulo = 0; angulo <= 90; angulo++) {
    servoPorta.write(angulo);
    delay(10);
  }

  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_VERDE, HIGH);
    for (int j = 0; j < 3; j++) digitalWrite(LEDS_AZUIS[j], HIGH);
    delay(200);
    digitalWrite(LED_VERDE, LOW);
    for (int j = 0; j < 3; j++) digitalWrite(LEDS_AZUIS[j], LOW);
    delay(200);
  }

  for (int i = 0; i < 3; i++) digitalWrite(LEDS_AZUIS[i], HIGH);
}

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  for (int i = 0; i < 3; i++) pinMode(LEDS_AZUIS[i], OUTPUT);

  servoPorta.attach(SERVO_PIN);
  servoPorta.write(0); // Porta fechada

  Serial.println("=======================================");
  Serial.println("🔐 Bem-vindo à Fortaleza do Dado Sagrado!");
  Serial.println("🎲 Acerte o número entre 1 e 6 para conquistar joias.");
  Serial.println("💎 Ao acertar 3 vezes, a Porta da Sabedoria se abrirá!");
  Serial.println("=======================================");
}

void loop() {
  if (portaAberta) return;

  int numeroSagrado = random(1, 7);

  Serial.println("\nDigite seu palpite (1-6):");
  while (!Serial.available());
  int palpite = Serial.parseInt();
  while (Serial.available()) Serial.read(); // Limpa buffer

  if (palpite < 1 || palpite > 6) {
    Serial.println(" Palpite inválido. Digite um número entre 1 e 6.");
    return;
  }

  Serial.print(" Seu palpite: ");
  Serial.println(palpite);
  Serial.print(" Número sagrado: ");
  Serial.println(numeroSagrado);

  if (palpite == numeroSagrado) {
    Serial.println(" CORRETO! Você conquistou uma joia!");
    acertos++;
    piscarLED(LED_VERDE, 3);
    acenderJoia(acertos);
    if (acertos == 3) abrirPortaSabedoria();
  } else {
    Serial.println(" INCORRETO! O guardião rejeitou seu palpite.");
    piscarLED(LED_VERMELHO, 3);
  }

  tentativas++;
  Serial.print(" Progresso: ");
  Serial.print(acertos);
  Serial.print(" / 3 acertos | Tentativas: ");
  Serial.println(tentativas);
}
