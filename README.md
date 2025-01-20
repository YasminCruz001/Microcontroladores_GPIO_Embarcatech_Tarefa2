# Controle de Pinos GPIO com BitDogLab e RP2040
Atividade 2 - Unidade 4

## Integrantes
- Yasmin Damasceno Cruz (TIC370101610)

Este projeto utiliza a ferramenta educacional **BitDogLab** para controlar pinos GPIO do microcontrolador **RP2040** através da porta serial **UART**. O objetivo é acionar um LED RGB e um buzzer, ambos conectados a GPIOs específicas, utilizando comandos escritos para serem interpretados pelo microcontrolador.

## Requisitos
- BitDogLab (versão 6.3)
- Cabo micro-USB para USB-A
- VS Code instalado
    - Extensão C/C++
- PuTTY para comunicação UART
- Pico SDK configurado
- Git instalado

## Configuração Inicial
1. Clone o repositório para sua máquina local:
   ```bash
   git clone <URL do Repositório>
2. Abra o projeto no VS Code.


## Execução
Utilize comandos para controlar os LEDs e o buzzer conforme descrito abaixo:

- verde: Liga o LED verde (GPIO 11) e desliga os LEDs azul e vermelho.
- azul: Liga o LED azul (GPIO 12) e desliga os LEDs verde e vermelho.
- vermelho: Liga o LED vermelho (GPIO 13) e desliga os LEDs azul e verde.
- branco: Liga os três LEDs.
- ciano: Liga os LEDs verde e azul.
- roxo: Liga os LEDs vermelho e azul.
- amarelo: Liga os LEDs vermelho e verde.
- off: Desliga todos os LEDs.
- buzzer: Emite um som no buzzer por 3 segundos com uma frequência de 300 Hz.
- reboot: Reinicia o dispositivo

## Vídeo Demonstrativo 

[Assista Aqui](https://drive.google.com/file/d/19uKgs0PTXdLT9GK1DYBOa9OH77JKIiio/view?usp=sharing)