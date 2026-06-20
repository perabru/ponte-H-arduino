# 🤖 Controle de Motores DC com Arduino e Ponte H L298N

Projeto simples, didático e completo para controlar dois motores DC utilizando **Arduino Uno** e uma **Ponte H L298N**.

Este projeto é ideal para:

- Robôs móveis;
- Carrinhos autônomos;
- Robôs sumô;
- Projetos de robótica educacional;
- Testes iniciais com motores DC;
- Aulas de Arduino, eletrônica e sistemas embarcados.

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
| Ponte H L298N / Driver de Motor | 1 |
| Motor DC | 2 |
| Rodas | 2 |
| Bateria externa para motores | 1 |
| Jumpers | Vários |
| Chassi do robô | 1 |

---

## 🔌 Tabela de Pinagens

| Ponte H L298N | Pino Arduino | Função |
|---|---:|---|
| IN1 | 2 | Controle do sentido do Motor A |
| IN2 | 3 | Controle do sentido do Motor A |
| IN3 | 4 | Controle do sentido do Motor B |
| IN4 | 5 | Controle do sentido do Motor B |
| OUT1 | Motor A | Saída para um fio do Motor A |
| OUT2 | Motor A | Saída para o outro fio do Motor A |
| OUT3 | Motor B | Saída para um fio do Motor B |
| OUT4 | Motor B | Saída para o outro fio do Motor B |
| GND | GND Arduino | Terra comum |
| 5V / VLogic | 5V Arduino ou saída 5V da ponte | Alimentação lógica, depende do jumper |
| 12V / VMS / VIN | Bateria externa | Alimentação dos motores |

---

## ⚠️ Atenção Muito Importante Sobre a Alimentação

Os motores **não devem ser alimentados diretamente pelo Arduino**.

O Arduino fornece pouca corrente para alimentar motores DC. Se você tentar alimentar os motores diretamente pelo pino 5V do Arduino, podem ocorrer problemas como:

- Arduino reiniciando sozinho;
- Motores fracos;
- Ponte H esquentando;
- Travamentos;
- Baixa velocidade;
- Possível dano na placa.

Por isso, use uma **bateria externa** para alimentar os motores pela Ponte H.

---

## 🔋 Como Alimentar a Ponte H L298N Corretamente

A Ponte H L298N normalmente possui três pontos principais de alimentação:

| Pino / Borne | Função |
|---|---|
| 12V / VMS / VIN | Entrada da bateria dos motores |
| GND | Terra da alimentação |
| 5V / VLogic | Alimentação lógica do circuito interno |

---

## 🧠 Regra Principal do GND Comum

Mesmo usando bateria externa para os motores, o Arduino e a Ponte H precisam ter o mesmo referencial elétrico.

Portanto, ligue juntos:


GND do Arduino
GND da Ponte H
GND da bateria externa
