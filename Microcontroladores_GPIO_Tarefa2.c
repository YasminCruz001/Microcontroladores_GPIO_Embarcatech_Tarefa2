#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>
#include "pico/bootrom.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"

// Definição dos pinos dos LEDs e do buzzer
#define LED_VERDE_PIN 11
#define LED_AZUL_PIN 12
#define LED_VERMELHO_PIN 13
#define BUZZER_PIN 21

// Função para acionar o buzzer por uma determinada duração em ms
void acionar_buzzer(int duracao_ms)
{
    int tempo_restante = duracao_ms;
    while (tempo_restante > 0)
    {
        gpio_put(BUZZER_PIN, true);  // Liga o buzzer
        sleep_ms(1);                 // Aguarda 1 ms
        tempo_restante--;
        gpio_put(BUZZER_PIN, false); // Desliga o buzzer
        sleep_ms(1);                 // Aguarda mais 1 ms
        tempo_restante--;
    }
}

// Função para emitir um som no buzzer com uma frequência específica por uma duração
void emitir_som(int duracao_ms, int frequencia_hz)
{
    int atraso_microsegundos = 1000000 / (2 * frequencia_hz);  // Calcula o atraso em microsegundos com base na frequência
    int total_ciclos = (duracao_ms * 1000) / (2 * atraso_microsegundos);  // Calcula o número de ciclos
    for (int i = 0; i < total_ciclos; i++)
    {
        gpio_put(BUZZER_PIN, true);  // Liga o buzzer
        sleep_us(atraso_microsegundos);  // Aguarda o atraso calculado
        gpio_put(BUZZER_PIN, false); // Desliga o buzzer
        sleep_us(atraso_microsegundos);  // Aguarda novamente
    }
}
