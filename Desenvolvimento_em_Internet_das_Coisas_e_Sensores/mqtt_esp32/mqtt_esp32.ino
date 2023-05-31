#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "ICOMP_1A";
const char* password = "1comp@14#";
const char* mqtt_server = "test.mosquitto.org";
//const char* mqtt_server = "broker.hivemq.com";
//const char* mqtt_server = "broker.emqx.io";
  

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;
// Pinos GPIOs
const int LED1_Pin = 26;
// Pinos GPIOs
const int LED2_Pin = 27;


void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    if ((char)payload[1] == 'L') {
      digitalWrite(LED1_Pin, HIGH);  // Turn the LED off
      Serial.println("LED LIGADO");
    } else if ((char)payload[1] == 'D'){
      digitalWrite(LED1_Pin, LOW);  // Turn the LED off
      Serial.println("LED DESLIGADO");
    }
  } else {
    //digitalWrite(LED1_Pin, LOW); // Turn the LED on
    Serial.println("Erro LED 1");
  }

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '2') {
    if ((char)payload[1] == 'L') {
      digitalWrite(LED2_Pin, HIGH);  // Turn the LED off
      Serial.println("LED LIGADO");
    } else if ((char)payload[1] == 'D'){
      digitalWrite(LED2_Pin, LOW);  // Turn the LED off
      Serial.println("LED DESLIGADO");
    }
  } else {
    //digitalWrite(LED1_Pin, LOW); // Turn the LED on
    Serial.println("Erro LED 2");
  }
  
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outOutTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inInTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(LED1_Pin, OUTPUT);     // Initialize the LED 1 pin as an output
  pinMode(LED2_Pin, OUTPUT);     // Initialize the LED 2 pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  unsigned long now = millis();
  if (now - lastMsg > 3000) {
    lastMsg = now;
    ++value;
    snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("outOutTopic", msg);
  }
}
