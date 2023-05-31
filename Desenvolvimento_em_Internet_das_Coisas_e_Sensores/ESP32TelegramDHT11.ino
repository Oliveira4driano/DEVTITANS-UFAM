#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "DHT.h"

#define WIFI_SSID "ICOMP_1A"
#define WIFI_PASSWORD "1comp@14#"
#define BOTtoken "XXX"

#define LED_PIN 22
#define DHT_PIN 23
#define DHTTYPE DHT11

#define BOT_SCAN 1000 
long lastTimeScan;
bool ledStatus;

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
DHT dht(DHT_PIN, DHTTYPE);

void handleNewMessages(int numNewMessages) {
  float humidity, temperature;
  String message, chat_id, text, from_name;

  for (int i=0; i<numNewMessages; i++) {
    chat_id = String(bot.messages[i].chat_id);
    from_name = bot.messages[i].from_name;    
    text = bot.messages[i].text;
    Serial.println(text);

    if (text == "/ledon") {
      digitalWrite(LED_PIN, HIGH);
      ledStatus = true;
      bot.sendMessage(chat_id, "Led está ligado", "");
      Serial.println("Led esta ligado");
    }

    if (text == "/ledoff") {
      ledStatus = false;
      digitalWrite(LED_PIN, LOW);
      bot.sendMessage(chat_id, "Led está desligado", "");
      Serial.println("Led esta desligado");
    }

    if( text == "/env") {
      humidity = dht.readHumidity();
      temperature = dht.readTemperature();
      message = "A temperatura é de " + String(temperature, 2) + " graus celsius.\n";
      message += "A umidade relativa do ar é de " + String(humidity, 2)+ "%.\n";
      bot.sendMessage(chat_id, message, "Markdown");
      Serial.println(message);      
    }

    if (text == "/status") {
      String message = "Led está ";
      if(ledStatus){
        message += "ligado";
      }else{
        message += "desligado";
      }
      message += ". \n";
      humidity = dht.readHumidity();
      temperature = dht.readTemperature();
      message += "A temperatura é de " + String(temperature, 2) + " graus celsius.\n";
      message += "A umidade relativa do ar é de " + String(humidity, 2)+ "%.\n";
      bot.sendMessage(chat_id, message, "");
      Serial.println(message);      
    }

    if (text == "/start") {
      String welcome = from_name + ", bem vindo ao Bot do DevTitans do Barreto.\n";
      welcome += "Para interagir, use um dos comandos a seguir.\n";
      welcome += "/ledon : para ligar o Led \n";
      welcome += "/ledoff : para desligar o Led \n";
      welcome += "/env : saber a temperatura e umidade do ambiente \n";
      welcome += "/status : para saber o status dos sensores e atuadores \n";
      bot.sendMessage(chat_id, welcome, "");
    }
  }
}


void setupWifi(){  
  Serial.print("Connecting Wifi: ");
  Serial.println(WIFI_SSID);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
}

void setupPins(){
  pinMode(LED_PIN, OUTPUT); 
  pinMode(DHT_PIN, INPUT_PULLUP); 
  digitalWrite(LED_PIN, LOW);
  ledStatus = false;
  dht.begin();
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  setupWifi();
  setupPins();
  lastTimeScan = millis();
}

void loop() {
  if (millis() > lastTimeScan + BOT_SCAN)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);  
    while(numNewMessages) {
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeScan = millis();
  }
}
