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

// Função para configurar um pino GPIO como saída
void configurar_gpio(int pino)
{
    gpio_init(pino);              
    gpio_set_dir(pino, GPIO_OUT); 
    gpio_put(pino, false);        
}

int main()
{
    stdio_init_all();  

    // Configura os pinos dos LEDs e do buzzer
    configurar_gpio(LED_VERDE_PIN);
    configurar_gpio(LED_AZUL_PIN);
    configurar_gpio(LED_VERMELHO_PIN);
    configurar_gpio(BUZZER_PIN);

    char comando[10];  // Vetor para armazenar o comando digitado pelo usuário

    while (true)
    {
        scanf("%9s", comando);  
        printf("%s\n", comando); 

        
        if (strcmp(comando, "verde") == 0)
        {
            gpio_put(LED_AZUL_PIN, false);
            gpio_put(LED_VERDE_PIN, true);
            gpio_put(LED_VERMELHO_PIN, false);
        }
        else if (strcmp(comando, "azul") == 0)
        {
            gpio_put(LED_AZUL_PIN, true);
            gpio_put(LED_VERDE_PIN, false);
            gpio_put(LED_VERMELHO_PIN, false);
        }
        else if (strcmp(comando, "vermelho") == 0)
        {
            gpio_put(LED_AZUL_PIN, false);
            gpio_put(LED_VERDE_PIN, false);
            gpio_put(LED_VERMELHO_PIN, true);
        }
        else if (strcmp(comando, "branco") == 0)
        {
            gpio_put(LED_AZUL_PIN, true);
            gpio_put(LED_VERMELHO_PIN, true);
            gpio_put(LED_VERDE_PIN, true);
        }
        else if (strcmp(comando, "ciano") == 0)
        {
            gpio_put(LED_VERMELHO_PIN, false);
            gpio_put(LED_VERDE_PIN, true);
            gpio_put(LED_AZUL_PIN, true);
        }
        else if (strcmp(comando, "roxo") == 0)
        {
            gpio_put(LED_VERMELHO_PIN, true);
            gpio_put(LED_VERDE_PIN, false);
            gpio_put(LED_AZUL_PIN, true);
        }
        else if (strcmp(comando, "amarelo") == 0)
        {
            gpio_put(LED_VERMELHO_PIN, true);
            gpio_put(LED_VERDE_PIN, true);
            gpio_put(LED_AZUL_PIN, false);
        }
        else if (strcmp(comando, "buzzer") == 0)
        {
            emitir_som(3000, 300);  // Emite um som no buzzer por 3 segundos com 300 Hz
        }
        else if (strcmp(comando, "off") == 0)
        {
            
            gpio_put(LED_VERMELHO_PIN, false);
            gpio_put(LED_VERDE_PIN, false);
            gpio_put(LED_AZUL_PIN, false);
        }
        else if (strcmp(comando, "reboot") == 0)
        {
            reset_usb_boot(0, 0);  // Reinicia o dispositivo
        }
        else
        {
            printf("Comando inválido, tente novamente!\n");  
        }
    }
}
