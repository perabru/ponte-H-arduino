#define in1 2
#define in2 3
#define in3 4
#define in4 5

void setup() {
  // Motor A
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Motor B
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // Anda para frente
  frente();
  delay(2000);

  pararMotores();
  delay(1000);

  // Anda para trás
  tras();
  delay(2000);

  pararMotores();
  delay(1000);

  // Gira para a direita
  girarDireita();
  delay(1500);

  pararMotores();
  delay(1000);

  // Gira para a esquerda
  girarEsquerda();
  delay(1500);

  pararMotores();
  delay(1000);
}

// ========================
// FUNÇÕES DOS MOTORES
// ========================

void frente() {
  frenteMotorA();
  frenteMotorB();
}

void tras() {
  trasMotorA();
  trasMotorB();
}

void frenteMotorA() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void frenteMotorB() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void trasMotorA() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void trasMotorB() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void pararMotorA() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void pararMotorB() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void pararMotores() {
  pararMotorA();
  pararMotorB();
}

void girarDireita() {
  frenteMotorA();
  trasMotorB();
}

void girarEsquerda() {
  trasMotorA();
  frenteMotorB();
}
