#Laboratório 4: Introdução ao ESP32

Neste laboratório faremos quatro atividades usando o emulador Wokwi. Você pode simplesmente copiar os quatro link de compartilhamento dos quatro projetos como texto simples.

### PRIMEIRO: LED piscante (saída digital)

Faça um circuito que contenha um ESP32, um LED e um resistor (330 ohms), de acordo com o que foi mostrado em sala de aula. Codifique para que o LED acenda e apague em intervalos de um em um segundo. Pode copiar e colar dos slides tranquilamente e fazendo os ajustes necessários. Leve em consideração a pinagem. ENTREGÁVEL: Compartilhe o link do teu projeto.
´´´
https://wokwi.com/projects/364385009873963009

#define LED_PIN 32
void setup() {
pinMode(LED_PIN, OUTPUT);
}
void loop() {
digitalWrite(LED_PIN, HIGH);
delay(1000);
digitalWrite(LED_PIN, LOW);
delay(1000);
}
´´´

### SEGUNDO: Potenciômetro (entrada analógica)

Faça um circuito que contenha um ESP32 e um potenciômetro, de acordo com o que foi mostrado em sala de aula. Codifique para que o valor atual da residência, um valor entre 0 e 4095, seja mostrado na Serial. Pode copiar e colar o código dos slides tranquilamente e, se for o caso, fazendo os ajustes necessários. Leve em consideração a pinagem, uma vez que nem todos os pinos podem ler entradas analógicas. ENTREGÁVEL: Compartilhe o link do teu projeto.
´´´
https://wokwi.com/projects/364385490187875329

#define POT_PIN 2
void setup() {
pinMode(POT_PIN, INPUT);
Serial.begin(115200);
}
void loop() {
Serial.println(analogRead(POT_PIN));
delay(10);
}
´´´
### TERCEIRO: LED (saída digital) acionado por um botão de pressão (entrada digital)

Faça um circuito que contenha um ESP32, um LED, um resistor (330 ohms) e um botão de pressão, de acordo com o que foi mostrado em sala de aula. Codifique para que o LED apague, caso o botão esteja sendo pressionado, ou acenda caso o botão não esteja sendo pressionado. Pode copiar e colar dos slides tranquilamente. Não esqueça de levar em consideração a pinagem. ENTREGÁVEL: Compartilhe o link do teu projeto.
´´´
https://wokwi.com/projects/364389794210971649

const int ledPin = 32;
const int Botao = 23;
int estadoBotao;
void setup(){
pinMode(ledPin, OUTPUT);
pinMode(Botao, INPUT_PULLUP);
}
void loop(){
estadoBotao = digitalRead(Botao);
if (estadoBotao == HIGH)
digitalWrite(ledPin, HIGH);
else if (estadoBotao == LOW)
digitalWrite(ledPin, LOW);
}
´´´

#### QUARTO: LED (saída digital) acionado por um botão de pressão (entrada digital) como se fosse uma chave liga-desliga

Faça um circuito que contenha um ESP32, um LED, um resistor (330 ohms) e um botão de pressão, de acordo com o que foi mostrado em sala de aula. Codifique para que o LED alterne entre ligado e apagado conforme o botão seja pressionado e solto, como se fosse uma chave liga-desliga. Considerando que o LED inicia apagado, caso o botão seja pressionado (e solto), o LED passa a estar ligado. Caso o botão seja pressionado (e solto) novamente, o LED passa a estar desligado. Pode copiar e colar dos slides tranquilamente. Não esqueça de levar em consideração a pinagem. ENTREGÁVEL: Compartilhe o link do teu projeto.
´´´
https://wokwi.com/projects/364390739703630849

const int ledPin = 32; const int Botao = 23;
int guarda_estado = false;
void setup(){
pinMode(ledPin, OUTPUT);
pinMode(Botao, INPUT_PULLUP);
}
void loop(){
if (digitalRead(Botao)) {
guarda_estado = !guarda_estado;
while (digitalRead(Botao)); // espera soltar o botao
}
if (guarda_estado == HIGH)
digitalWrite(ledPin, HIGH);
else digitalWrite(ledPin, LOW);
delay(100);
}
´´´
