// Pino digital para o LED
int ledPin = 13;

void setup() {
  // Define o pino do LED como saída
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Acende o LED
  digitalWrite(ledPin, HIGH);
  delay(1000); // Aguarda 1 segundo

  // Apaga o LED
  digitalWrite(ledPin, LOW);
  delay(1000); // Aguarda 1 segundo
}
