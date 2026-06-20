# 🤖 Controle de Motores DC com Arduino e Ponte H

Projeto simples e didático para controlar dois motores DC utilizando **Arduino** e uma **Ponte H**.

Este projeto é ideal para robôs móveis, carrinhos autônomos, robôs sumô, projetos de robótica educacional e testes iniciais com motores.

---

## 📌 Objetivo

O objetivo deste projeto é demonstrar como controlar dois motores DC usando uma Ponte H, permitindo que o robô realize movimentos básicos como:

- Andar para frente;
- Andar para trás;
- Girar para a direita;
- Girar para a esquerda;
- Parar os motores.

---

## 🧰 Componentes Utilizados

| Componente | Quantidade |
|---|---:|
| Arduino Uno | 1 |
| Ponte H / Driver de Motor | 1 |
| Motor DC | 2 |
| Rodas | 2 |
| Bateria externa para motores | 1 |
| Jumpers | Vários |
| Chassi do robô | 1 |

---

## 🔌 Tabela de Pinagens

| Ponte H | Pino Arduino | Função |
|---|---:|---|
| IN1 | 2 | Controle do Motor A |
| IN2 | 3 | Controle do Motor A |
| IN3 | 4 | Controle do Motor B |
| IN4 | 5 | Controle do Motor B |
| VCC lógico | 5V | Alimentação lógica da Ponte H |
| GND | GND | Terra comum |
| VM / 12V / Motor Power | Bateria externa | Alimentação dos motores |
| OUT1 e OUT2 | Motor A | Saída para o motor esquerdo ou direito |
| OUT3 e OUT4 | Motor B | Saída para o outro motor |

---

## ⚠️ Atenção à Alimentação

Os motores **não devem ser alimentados diretamente pelo Arduino**, pois eles consomem mais corrente do que a placa consegue fornecer.

Use uma bateria externa para alimentar os motores pela Ponte H.

Também é muito importante ligar todos os terras juntos:

```text
GND do Arduino
GND da Ponte H
GND da bateria externa
