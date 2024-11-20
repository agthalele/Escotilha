#include <WiFi.h>
#include <ESP32Servo.h>
#include "site.h"


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

// GPIO the servo is attached to
static const int servoPin = 13;

// Nome do SSID (nome da rede Wi-Fi) e senha do Access Point
const char* ssid = "ESP32";
const char* password = "escotilha327";

// Configura o servidor web na porta 80
WiFiServer server(80);

// Variável para armazenar a requisição HTTP
String header;

// Variáveis para armazenar o estado atual dos GPIOs
String output26State = "off";
String output27State = "off";

// Definir os pinos GPIO
const int output26 = 13;
const int output27 = 13;

int rote = 180;

void setup() {
  Serial.begin(9600);  // Iniciar monitor serial

  // Configurar os pinos como saída
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  digitalWrite(output26, LOW);  // Inicialmente desligado
  digitalWrite(output27, LOW);  // Inicialmente desligado

  // Configurar o ESP32 como Access Point
  Serial.println("Configurando Access Point...");
  WiFi.softAP(ssid, password);  // Configurar rede Wi-Fi com SSID e senha
  
  // Imprimir o endereço IP do Access Point 
  Serial.println("Access Point configurado.");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());  // Exibe o IP da placa

  myservo.attach(servoPin);
  myservo.write(180);

  // Iniciar o servidor
  server.begin();
}

void loop() {
  WiFiClient client = server.available();  // Aguarda conexões de clientes

  if (client) {                             // Se um cliente se conectar
    Serial.println("Novo cliente conectado.");
    String currentLine = "";                // Armazena dados recebidos do cliente
    unsigned long currentTime = millis();   // Tempo atual
    unsigned long previousTime = currentTime; // Tempo anterior
    const long timeoutTime = 2000000;          // Tempo limite para desconexão

    while (client.connected() && (currentTime - previousTime <= timeoutTime)) {  // Enquanto o cliente estiver conectado
      if (client.available()) {             // Se há dados a serem lidos
        char c = client.read();             // Ler um byte
        Serial.write(c);                    // Imprimir o byte no monitor serial
        header += c;                        // Armazenar na string header
        if (c == '\n') {                    // Se a linha estiver vazia, significa que terminou a requisição
          if (currentLine.length() == 0) {
            // Enviar resposta HTTP ao cliente
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // Controle dos GPIOs via requisição HTTP
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("ABRIR");
              output26State = "on";  
              myservo.write(0);
            } 
            else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("FECHAR");
              output26State = "off";
              myservo.write(180);
            } 
             
            // Exibir a página HTML com botões de controle
            client.println(html);
            //client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            //client.println("<link rel=\"icon\" href=\"data:,\">");
            //client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;} .button { background-color: black; border: none; color: white; padding: 16px 40px; text-decoration: none; font-size: 64px; margin: 10px; cursor: pointer;} .button2 {background-color: #555555;}</style></head>");
            
            //client.println("<body><h5>ESP32 Access Point Web Server</h5>");
            
            // Exibir o estado do GPIO 26 e os botões de controle
            if (output26State=="off") {
              Serial.println(img1);
              client.println(img1);
              client.println("<p><a href=\"/26/on\"><button class=\"button1\">ABRIR</button></a></p>");
            } else {
              Serial.println(img2);
              client.println(img2);
              client.println("<p><a href=\"/26/off\"><button class=\"button2\">FECHAR</button></a></p>");
            }
            
            client.println("</body></html>");
            client.println();
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
      }
      currentTime = millis(); // Atualiza o tempo atual dentro do loop
    }
    header = "";  
    client.stop();
    Serial.println("Cliente desconectado.");
  }
}