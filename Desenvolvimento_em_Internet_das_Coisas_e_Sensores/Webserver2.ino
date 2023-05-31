#include <WiFi.h>

const char* ssid = "ICOMP_1A";
const char* password = "1comp@14#";
WiFiServer server(80);
String header;   // armazena o request HTTP

// Estado atual do LED1
bool led1Status = false;

// Pinos GPIOs
const int LED1_Pin = 26;

void setup() {
  Serial.begin(115200);
  pinMode(LED1_Pin, OUTPUT);
  digitalWrite(LED1_Pin, LOW);

  // Conexao com a rede Wi-Fi
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Imprime o endereco IP local e inicia o Servidor Web
  Serial.println("");
  Serial.println("WiFi conectado.");
  Serial.println("Endereco IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();
  if (client) {                    
    while (client.connected()) { 
        if (client.available()) {
            char c = client.read();  
            header += c;
            if (c == '\n') {
                client.println("HTTP/1.1 200 OK");
                client.println("Content-type:text/html");
                client.println();

                // ajusta os GPIOs on e off
                if (header.indexOf("GET /LED1/on") >= 0) {
                    Serial.println("LED1 on");
                    led1Status = true;
                    digitalWrite(LED1_Pin, HIGH); 
                } else if (header.indexOf("GET /LED1/off") >= 0) {
                    Serial.println("LED1 off");
                    led1Status = false;
                    digitalWrite(LED1_Pin, LOW); 
                } 
                // Gera a pagina HTML
                client.println("<html>");
                client.println("<body><h1>ESP32 Web Server</h1>");
                if (led1Status) {
                    client.println("<p>LED1 - State ON</p>");
                    client.println("<p><a href=\"/LED1/off\"><button class=\"button\">OFF</button></a></p>");
                }
                else {
                    client.println("<p>LED1 - State OFF</p>");
                    client.println("<p><a href=\"/LED1/on\"><button class=\"button\">ON</button></a></p>");
                }
                client.println("</body></html>");
                header = "";
                // Fecha a conexao
                client.stop();
            } // if nova linha 
        } // if cliente disponivel
    } // if cliente conectado
  } // if cliente se conectou
} // loop
