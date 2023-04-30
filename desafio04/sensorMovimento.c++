int sensorPin = 2; // define o pino do sensor PIR como 2
int ledPin = 13; // define o pino do LED como 13
int sensorState = 0; // inicializa o estado do sensor como "sem movimento"

void setup() {
  pinMode(sensorPin, INPUT); // define o pino do sensor como entrada
  pinMode(ledPin, OUTPUT); // define o pino do LED como saída
  Serial.begin(9600); // inicializa a comunicação serial para debug
}

void loop() {
  sensorState = digitalRead(sensorPin); // lê o estado do sensor

  if (sensorState == HIGH) { // se o sensor detectar movimento
    digitalWrite(ledPin, HIGH); // acende o LED
    Serial.println("Movimento detectado!"); // envia uma mensagem para a porta serial
    delay(1000); // espera 1 segundo
  } else {
    digitalWrite(ledPin, LOW); // apaga o LED
  }
}
