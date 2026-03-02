// DECLARAÇÕES DOS PINOS:
const int trigger = 10;
const int echo = 11;

const int motorE_frente = 4;
const int motorE_tras   = 5;
const int motorD_frente = 7;
const int motorD_tras   = 8;

const int pwmE = 6;
const int pwmD = 9;

const int buzzer = 3;

// config dos pinos
void setup() {

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(motorE_frente, OUTPUT);
  pinMode(motorE_tras, OUTPUT);
  pinMode(motorD_frente, OUTPUT);
  pinMode(motorD_tras, OUTPUT);

  pinMode(pwmE, OUTPUT);
  pinMode(pwmD, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

// Segue a movimentação dos motores
void frente(int velocidade) {

  digitalWrite(motorE_frente, HIGH);
  digitalWrite(motorE_tras, LOW);
  digitalWrite(motorD_frente, HIGH);
  digitalWrite(motorD_tras, LOW);

  analogWrite(pwmE, velocidade);
  analogWrite(pwmD, velocidade);
}

void re(int velocidade) {

  digitalWrite(motorE_frente, LOW);
  digitalWrite(motorE_tras, HIGH);
  digitalWrite(motorD_frente, LOW);
  digitalWrite(motorD_tras, HIGH);

  analogWrite(pwmE, velocidade);
  analogWrite(pwmD, velocidade);
}

void esquerda(int velocidade) {

  digitalWrite(motorE_frente, LOW);
  digitalWrite(motorE_tras, HIGH);
  digitalWrite(motorD_frente, HIGH);
  digitalWrite(motorD_tras, LOW);

  analogWrite(pwmE, velocidade);
  analogWrite(pwmD, velocidade);
}

void direita(int velocidade) {

  digitalWrite(motorE_frente, HIGH);
  digitalWrite(motorE_tras, LOW);
  digitalWrite(motorD_frente, LOW);
  digitalWrite(motorD_tras, HIGH);

  analogWrite(pwmE, velocidade);
  analogWrite(pwmD, velocidade);
}
void parar() {

  digitalWrite(motorE_frente, LOW);
  digitalWrite(motorE_tras, LOW);
  digitalWrite(motorD_frente, LOW);
  digitalWrite(motorD_tras, LOW);
}
//ULTRASSÔNICO
float medirDistancia() {

  digitalWrite(trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  long tempo = pulseIn(echo, HIGH);
  return (tempo * 0.0343) / 2.0;
}

//SENSOR DE COR (adaptar ao seu sensor)
String lerCor() {

  int r = random(0,255);
  int g = random(0,255);
  int b = random(0,255);

  if (r < 50 && g < 50 && b < 50) return "preto";
  if (r > 200 && g > 200 && b > 200) return "branco";
  if (g > r && g > b) return "verde";
  if (r > g && r > b) return "vermelho";
  if (b > r && b > g) return "azul";

  return "nenhuma";
}
//  LOOP CÓDIGO AQUI NESSA FUNÇÃO RODA DE FORMA INFINITA 
void loop() {
  float distancia = medirDistancia();
  String cor = lerCor();
  if (cor == "vermelho") {
    parar();
    tone(buzzer, 1000);
    delay(800);
    noTone(buzzer);
  }
  else if (cor == "verde") {
    direita(180);
    delay(350);
  }
  else if (cor == "azul") {
    esquerda(180);
    delay(350);
  }
  else if (distancia < 15) {

    parar();
    delay(200);
    re(150);
    delay(400);
    if (random(0,2) == 0)
      esquerda(180);
    else
      direita(180);

    delay(400);
  }
  else if (cor == "preto") {
    frente(180);
  }
  else {
    frente(150);
  }
  delay(50);
}
