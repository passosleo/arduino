#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress ip(192, 168, 2, 118);

IPAddress serverIP(192, 168, 2,108);
int serverPort = 4000;

EthernetClient client;

const int buttonPin = 12;
int buttonState = 0;

void setup() {
  Ethernet.begin(mac, ip);
  delay(1000);

  Serial.begin(9600);
  Serial.println("Cliente HTTP iniciado");

  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    if (client.connect(serverIP, serverPort)) {
      Serial.println("Conectado ao servidor HTTP");

      // Envie uma solicitação HTTP GET
      client.println("GET / HTTP/1.1");
      client.print("Host: ");
      client.println(serverIP);
      client.println("Connection: close");
      client.println();
    }
    else {
      Serial.println("Falha na conexão com o servidor HTTP");
    }
    
    delay(1000);
  }

  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
}
