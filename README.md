# 🤖 Controle de Motores DC com Arduino e Ponte H L298N

Projeto didático para controlar **dois motores DC** utilizando **Arduino Uno** e uma **Ponte H L298N**.

Este projeto é ideal para robôs móveis, carrinhos autônomos, robôs sumô, projetos escolares, aulas de robótica educacional e testes iniciais de controle de motores.

---

## 📌 Objetivo do Projeto

O objetivo deste projeto é demonstrar como controlar dois motores DC usando uma Ponte H L298N, permitindo que o robô realize movimentos básicos, como:

* Andar para frente;
* Andar para trás;
* Girar para a direita;
* Girar para a esquerda;
* Parar os motores.

A Ponte H permite inverter o sentido de rotação dos motores por meio de sinais digitais enviados pelo Arduino.

---

## 🧰 Componentes Utilizados

| Componente                      | Quantidade |
| ------------------------------- | ---------: |
| Arduino Uno                     |          1 |
| Ponte H L298N                   |          1 |
| Motor DC                        |          2 |
| Rodas                           |          2 |
| Bateria externa para os motores |          1 |
| Jumpers macho-macho             |     Vários |
| Jumpers macho-fêmea             |     Vários |
| Chassi do robô                  |          1 |

---

## 🔌 Tabela de Pinagens

| Ponte H L298N   | Arduino / Componente              | Função                                   |
| --------------- | --------------------------------- | ---------------------------------------- |
| IN1             | Pino digital 2                    | Controle do sentido do Motor A           |
| IN2             | Pino digital 3                    | Controle do sentido do Motor A           |
| IN3             | Pino digital 4                    | Controle do sentido do Motor B           |
| IN4             | Pino digital 5                    | Controle do sentido do Motor B           |
| OUT1            | Motor A                           | Saída para um terminal do Motor A        |
| OUT2            | Motor A                           | Saída para o outro terminal do Motor A   |
| OUT3            | Motor B                           | Saída para um terminal do Motor B        |
| OUT4            | Motor B                           | Saída para o outro terminal do Motor B   |
| GND             | GND do Arduino                    | Terra comum                              |
| 5V              | 5V do Arduino ou saída da Ponte H | Alimentação lógica, depende do jumper 5V |
| 12V / VMS / VIN | Bateria externa                   | Alimentação dos motores                  |

---

## ⚠️ Atenção Sobre a Alimentação

Os motores **não devem ser alimentados diretamente pelo Arduino**.

O Arduino não fornece corrente suficiente para alimentar motores DC. Caso os motores sejam ligados diretamente ao Arduino, podem acontecer problemas como:

* Arduino reiniciando sozinho;
* Motores girando fracos;
* Travamento do sistema;
* Ponte H esquentando;
* Baixo desempenho;
* Possível dano ao Arduino.

Por isso, os motores devem ser alimentados por uma **fonte ou bateria externa**, conectada diretamente à Ponte H.

---

## 🔋 Alimentação Correta da Ponte H L298N

A Ponte H L298N possui normalmente três pontos principais de alimentação:

| Pino / Borne    | Função                             |
| --------------- | ---------------------------------- |
| 12V / VMS / VIN | Entrada da alimentação dos motores |
| GND             | Terra da alimentação               |
| 5V              | Alimentação lógica da Ponte H      |

A alimentação dos motores deve ser feita pelo borne `12V`, `VMS` ou `VIN`, dependendo do nome escrito na sua placa.

---

## 🧠 Regra Mais Importante: GND Comum

Mesmo usando bateria externa para os motores, o Arduino e a Ponte H precisam compartilhar o mesmo terra.

Portanto, conecte juntos:

```text
GND do Arduino
GND da Ponte H
GND da bateria externa
```

Se os GNDs não estiverem conectados, o Arduino pode até enviar os comandos para a Ponte H, mas a Ponte H pode não reconhecer corretamente os sinais.

---

## 🔌 Entendendo o Jumper 5V da Ponte H L298N

Alguns módulos L298N possuem um jumper chamado:

```text
5V-EN
5V ENABLE
JUMPER 5V
REGULADOR 5V
```

Esse jumper ativa ou desativa o regulador de tensão interno da placa.

A forma correta de ligação depende da tensão usada para alimentar os motores.

---

## ✅ Caso 1: Motores Alimentados com 7V a 12V

Exemplos:

* Bateria de 7,4V;
* Bateria de 9V;
* Fonte de 12V;
* Pack de pilhas adequado.

Nesse caso, normalmente o jumper 5V pode ficar conectado.

| Ligação             | Onde conectar              |
| ------------------- | -------------------------- |
| Positivo da bateria | 12V / VMS / VIN da Ponte H |
| Negativo da bateria | GND da Ponte H             |
| GND da Ponte H      | GND do Arduino             |
| IN1                 | Pino 2 do Arduino          |
| IN2                 | Pino 3 do Arduino          |
| IN3                 | Pino 4 do Arduino          |
| IN4                 | Pino 5 do Arduino          |
| 5V da Ponte H       | Não ligar ao 5V do Arduino |

Com o jumper conectado, a própria Ponte H usa o regulador interno para gerar a tensão lógica de 5V.

⚠️ Importante: se o jumper 5V estiver conectado, o pino 5V da Ponte H funciona como saída. Portanto, não ligue o 5V do Arduino nesse pino.

---

## ✅ Caso 2: Motores Alimentados com Mais de 12V

Exemplos:

* Fonte de 15V;
* Fonte de 18V;
* Fonte de 24V.

Nesse caso, é mais seguro remover o jumper 5V da Ponte H.

| Ligação                   | Onde conectar              |
| ------------------------- | -------------------------- |
| Positivo da fonte/bateria | 12V / VMS / VIN da Ponte H |
| Negativo da fonte/bateria | GND da Ponte H             |
| GND da Ponte H            | GND do Arduino             |
| 5V do Arduino             | 5V da Ponte H              |
| IN1                       | Pino 2 do Arduino          |
| IN2                       | Pino 3 do Arduino          |
| IN3                       | Pino 4 do Arduino          |
| IN4                       | Pino 5 do Arduino          |
| Jumper 5V                 | Removido                   |

Nesse caso, a Ponte H recebe a alimentação dos motores pela entrada de potência e recebe a alimentação lógica pelo 5V do Arduino.

---

## ✅ Caso 3: Motores Alimentados com 5V

Se os motores forem alimentados com uma fonte de 5V, o regulador interno da Ponte H pode não funcionar corretamente.

Nesse caso, remova o jumper 5V e alimente a parte lógica da Ponte H com o 5V do Arduino.

| Ligação              | Onde conectar              |
| -------------------- | -------------------------- |
| Positivo da fonte 5V | 12V / VMS / VIN da Ponte H |
| Negativo da fonte 5V | GND da Ponte H             |
| GND da Ponte H       | GND do Arduino             |
| 5V do Arduino        | 5V da Ponte H              |
| Jumper 5V            | Removido                   |

---

## 📌 Resumo da Alimentação

| Situação                               | Jumper 5V         | Pino 5V da Ponte H | Observação                             |
| -------------------------------------- | ----------------- | ------------------ | -------------------------------------- |
| Motores com 7V a 12V                   | Conectado         | Saída 5V           | Não ligar o 5V do Arduino nesse pino   |
| Motores com 5V                         | Removido          | Entrada 5V         | Ligar o 5V do Arduino no 5V da Ponte H |
| Motores acima de 12V                   | Removido          | Entrada 5V         | Ligar o 5V do Arduino no 5V da Ponte H |
| Arduino e motores com fontes separadas | Depende da tensão | Depende do jumper  | Sempre unir os GNDs                    |

---

## ❌ Ligações Que Devem Ser Evitadas

Não faça estas ligações:

```text
Não ligue motores diretamente no Arduino.
Não ligue o positivo da bateria no pino 5V do Arduino.
Não alimente o pino 5V da Ponte H se o jumper 5V estiver conectado.
Não deixe o GND da Ponte H separado do GND do Arduino.
Não use fonte fraca para os motores.
Não inverta a polaridade da alimentação.
Não teste o robô no chão antes de verificar se os motores giram corretamente.
```

---

## 🧠 Funcionamento da Ponte H

A Ponte H é um circuito que permite controlar o sentido de rotação de motores DC.

Cada motor é controlado por dois pinos digitais.

Neste projeto:

| Motor   | Pinos de controle |
| ------- | ----------------- |
| Motor A | IN1 e IN2         |
| Motor B | IN3 e IN4         |

Quando um pino recebe `HIGH` e o outro recebe `LOW`, o motor gira em um sentido.

Quando a lógica é invertida, o motor gira no sentido contrário.

Quando os dois pinos ficam em `LOW`, o motor para.

Quando os dois pinos ficam em `HIGH`, ocorre uma condição de freio.

---

## ✅ Tabela Verdade do Motor A

O Motor A é controlado pelos pinos `IN1` e `IN2`.

No código:

```cpp
#define in1 2
#define in2 3
```

| Estado do Motor A | IN1  | IN2  | Resultado                |
| ----------------- | ---- | ---- | ------------------------ |
| Sentido direto    | HIGH | LOW  | Motor A gira para frente |
| Sentido inverso   | LOW  | HIGH | Motor A gira para trás   |
| Parado            | LOW  | LOW  | Motor A parado           |
| Freio             | HIGH | HIGH | Motor A freado           |

---

## ✅ Tabela Verdade do Motor B

O Motor B é controlado pelos pinos `IN3` e `IN4`.

No código:

```cpp
#define in3 4
#define in4 5
```

| Estado do Motor B | IN3  | IN4  | Resultado                |
| ----------------- | ---- | ---- | ------------------------ |
| Sentido direto    | HIGH | LOW  | Motor B gira para frente |
| Sentido inverso   | LOW  | HIGH | Motor B gira para trás   |
| Parado            | LOW  | LOW  | Motor B parado           |
| Freio             | HIGH | HIGH | Motor B freado           |

---

## 🚗 Tabela de Movimentos do Robô

Combinando os dois motores, conseguimos controlar o movimento do robô.

| Movimento           | Motor A         | Motor B         | Resultado                 |
| ------------------- | --------------- | --------------- | ------------------------- |
| Frente              | Sentido direto  | Sentido direto  | Robô anda para frente     |
| Ré                  | Sentido inverso | Sentido inverso | Robô anda para trás       |
| Girar para direita  | Sentido direto  | Sentido inverso | Robô gira para a direita  |
| Girar para esquerda | Sentido inverso | Sentido direto  | Robô gira para a esquerda |
| Parar               | Parado          | Parado          | Robô para                 |
| Frear               | Freio           | Freio           | Robô trava os motores     |

---

## 💻 Código Arduino Completo

```cpp
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

  // Para os motores
  pararMotores();
  delay(1000);

  // Anda para trás
  tras();
  delay(2000);

  // Para os motores
  pararMotores();
  delay(1000);

  // Gira para a direita
  girarDireita();
  delay(1500);

  // Para os motores
  pararMotores();
  delay(1000);

  // Gira para a esquerda
  girarEsquerda();
  delay(1500);

  // Para os motores
  pararMotores();
  delay(1000);
}

// ========================
// FUNÇÕES DE MOVIMENTO
// ========================

void frente() {
  frenteMotorA();
  frenteMotorB();
}

void tras() {
  trasMotorA();
  trasMotorB();
}

void girarDireita() {
  frenteMotorA();
  trasMotorB();
}

void girarEsquerda() {
  trasMotorA();
  frenteMotorB();
}

void pararMotores() {
  pararMotorA();
  pararMotorB();
}

void frearMotores() {
  frearMotorA();
  frearMotorB();
}

// ========================
// MOTOR A
// ========================

void frenteMotorA() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void trasMotorA() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void pararMotorA() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void frearMotorA() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
}

// ========================
// MOTOR B
// ========================

void frenteMotorB() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void trasMotorB() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void pararMotorB() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void frearMotorB() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
}
```

---

## 🚗 Sequência de Movimentos do Código

Ao carregar o código no Arduino, o robô executará a seguinte sequência:

```text
1. Anda para frente por 2 segundos
2. Para por 1 segundo
3. Anda para trás por 2 segundos
4. Para por 1 segundo
5. Gira para a direita por 1,5 segundo
6. Para por 1 segundo
7. Gira para a esquerda por 1,5 segundo
8. Para por 1 segundo
9. Repete tudo novamente
```

---

## 🧪 Como Testar o Projeto

1. Monte o circuito conforme a tabela de pinagens.
2. Conecte o Arduino ao computador.
3. Abra a IDE Arduino.
4. Copie o código para um novo sketch.
5. Selecione a placa correta, por exemplo, Arduino Uno.
6. Selecione a porta correta.
7. Envie o código para o Arduino.
8. Levante o robô para as rodas não encostarem na mesa.
9. Ligue a alimentação externa dos motores.
10. Observe se os motores giram corretamente.
11. Depois de confirmar o funcionamento, coloque o robô no chão para testar os movimentos.

---

## 🔍 Como Corrigir Motor Girando ao Contrário

Se um motor estiver girando ao contrário, existem duas formas de corrigir.

### Opção 1: inverter os fios do motor

Troque os dois fios do motor na saída da Ponte H.

Exemplo:

```text
OUT1 ↔ OUT2
```

ou

```text
OUT3 ↔ OUT4
```

### Opção 2: alterar o código

Troque `HIGH` e `LOW` da função do motor correspondente.

Exemplo para inverter o Motor A:

```cpp
void frenteMotorA() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
```

Exemplo para inverter o Motor B:

```cpp
void frenteMotorB() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
```

---

## 🛠️ Possíveis Problemas e Soluções

| Problema                        | Possível causa                       | Solução                                               |
| ------------------------------- | ------------------------------------ | ----------------------------------------------------- |
| Motor não gira                  | Falta alimentação externa            | Verifique a bateria ou fonte dos motores              |
| Motor gira ao contrário         | Fios invertidos                      | Inverta os fios do motor ou ajuste o código           |
| Apenas um motor funciona        | Ligação incorreta                    | Verifique IN1, IN2, IN3, IN4, OUT1, OUT2, OUT3 e OUT4 |
| Arduino reinicia                | Motor consumindo muita corrente      | Use alimentação separada para os motores              |
| Robô não anda reto              | Motores com velocidades diferentes   | Ajuste mecanicamente ou use controle PWM              |
| Ponte H esquenta muito          | Corrente alta ou tensão inadequada   | Use dissipador, fonte adequada ou driver mais forte   |
| Motor está fraco                | Bateria fraca                        | Use bateria com corrente suficiente                   |
| Código envia, mas nada acontece | GND não está comum                   | Ligue GND do Arduino ao GND da Ponte H                |
| Motor vibra, mas não gira       | Bateria fraca ou motor travado       | Teste com outra bateria e verifique o eixo            |
| Ponte H não responde            | Jumper 5V incorreto                  | Confira se o jumper deve estar conectado ou removido  |
| Motor só gira para um lado      | Um dos pinos IN está mal conectado   | Verifique os jumpers e o código                       |
| Robô gira em vez de andar reto  | Motores montados em sentidos opostos | Inverta a lógica de um dos motores                    |

---

## 🔋 Dicas Importantes

* Não ligue motores diretamente no Arduino.
* Use bateria externa para alimentar os motores.
* Ligue todos os GNDs em comum.
* Teste os motores com o robô suspenso.
* Confira a polaridade da bateria.
* Evite curto-circuito nos terminais da Ponte H.
* Verifique o jumper 5V antes de ligar o sistema.
* Não alimente o pino 5V da Ponte H se o jumper 5V estiver conectado.
* Se a Ponte H esquentar muito, desligue o sistema e revise a alimentação.
* Use fios firmes para os motores.
* Evite usar pilhas fracas ou descarregadas.
* Use uma bateria com corrente suficiente para os motores.

---

## 📁 Estrutura Recomendada do Projeto

```text
controle-ponte-h-arduino/
│
├── README.md
├── controle_ponte_h.ino
└── imagens/
    ├── pinagem.png
    └── tabela-verdade.png
```

---

## 🖼️ Imagem da Pinagem

Caso você tenha uma imagem da pinagem, coloque o arquivo dentro da pasta `imagens`.

Use este comando no README:

```markdown
![Tabela de Pinagens](imagens/pinagem.png)
```

Se a imagem estiver na mesma pasta do README, use:

```markdown
![Tabela de Pinagens](pinagem.png)
```

---

## 🖼️ Imagem da Tabela Verdade

Caso você tenha uma imagem da tabela verdade, coloque o arquivo dentro da pasta `imagens`.

Use este comando no README:

```markdown
![Tabela Verdade da Ponte H](imagens/tabela-verdade.png)
```

Se a imagem estiver na mesma pasta do README, use:

```markdown
![Tabela Verdade da Ponte H](tabela-verdade.png)
```

---

## 📚 Conceitos Trabalhados

Este projeto trabalha conceitos importantes de robótica e eletrônica, como:

* Saídas digitais do Arduino;
* Controle de motores DC;
* Ponte H;
* Sentido de rotação;
* Alimentação externa;
* Terra comum;
* Tabela verdade;
* Organização de código em funções;
* Robótica móvel;
* Lógica de programação;
* Sistemas embarcados.

---

## 🚀 Melhorias Futuras

Algumas melhorias possíveis para este projeto:

* Adicionar controle de velocidade com PWM;
* Adicionar sensor ultrassônico;
* Adicionar sensores de faixa;
* Criar um robô sumô;
* Adicionar botão de início;
* Adicionar LEDs indicadores;
* Usar controle Bluetooth;
* Criar controle por aplicativo;
* Implementar desvio de obstáculos;
* Criar controle por joystick;
* Usar bateria recarregável;
* Montar chassi impresso em 3D;
* Adicionar display OLED;
* Criar diferentes modos de movimento.

---

## 👨‍🏫 Aplicação Educacional

Este projeto pode ser utilizado em aulas de:

* Arduino;
* Robótica educacional;
* Sistemas embarcados;
* Eletrônica básica;
* Automação;
* Programação em C/C++;
* Projetos de carrinhos autônomos;
* Robôs sumô;
* Introdução à engenharia;
* Oficinas maker.

---

## ✅ Resultado Esperado

Ao final da montagem e envio do código, o robô deverá movimentar os dois motores usando a Ponte H L298N.

O robô deverá executar movimentos básicos de:

* Frente;
* Ré;
* Giro para direita;
* Giro para esquerda;
* Parada;
* Freio dos motores.

---

## 👨‍💻 Autor

Desenvolvido para fins educacionais e projetos de robótica.

**Professor Bruno Michel Pera**

---

## 📄 Licença

Este projeto pode ser utilizado livremente para fins educacionais.

Sugestão de licença:

```text
MIT License
```

---

## ⭐ Contribuição

Contribuições são bem-vindas.

Você pode melhorar este projeto adicionando:

* Novos movimentos;
* Controle de velocidade;
* Diagramas de ligação;
* Imagens do circuito;
* Código com sensores;
* Estratégias para robô sumô;
* Documentação complementar.

---

## 🏁 Conclusão

Este projeto apresenta a base para controlar motores DC com Arduino e Ponte H L298N.

Com ele, é possível entender como funciona o controle de direção dos motores, a importância da alimentação externa, o uso correto do GND comum e a lógica de funcionamento de uma Ponte H.

A partir deste projeto, é possível evoluir para robôs mais completos, como robôs seguidores de linha, robôs sumô, carrinhos com controle remoto e veículos autônomos simples.

