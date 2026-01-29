/**
 ******************************************************************************
 * @file           : main.c
 * @brief          :
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "STM32F446RE_Base.h"
#include "uart.h"
#include "irq.h"
#include "dma.h"

/* ============== Test States ============== */
typedef enum {
    STATE_IDLE,           // Așteaptă prima apăsare
    STATE_RUN_TEST1,      // Rulează test FĂRĂ DMA
    STATE_WAIT_TEST2,     // Așteaptă a doua apăsare
    STATE_RUN_TEST2,      // Rulează test CU DMA
    STATE_DONE            // Testele complete
} test_state_t;

/* ============== Global Variables ============== */
volatile test_state_t current_state = STATE_IDLE;
volatile uint8 button_pressed = 0;

// Variabile pentru test
volatile uint32 cpu_counter = 0;
volatile uint32 led_toggles = 0;
volatile uint8 transfer_done = 0;

// Rezultate salvate pentru comparație
uint32 result_test1_counter = 0;
uint32 result_test1_toggles = 0;
uint32 result_test2_counter = 0;
uint32 result_test2_toggles = 0;

// Buffer de test - 500 caractere 'A'
#define TEST_BUFFER_SIZE 500
uint8 test_buffer[TEST_BUFFER_SIZE];

/* ============== Function Prototypes ============== */
static void init_hardware(void);
static void init_test_buffer(void);
static void print_welcome(void);
static void run_test_without_dma(void);
static void run_test_with_dma(void);
static void print_results(void);
static void toggle_led(void);

/* ============== Main ============== */
int main(void)
{
    init_hardware();
    init_test_buffer();
    print_welcome();

    while(1)
    {
        switch(current_state)
        {
            case STATE_IDLE:
                // Așteaptă butonul
                if(button_pressed) {
                    button_pressed = 0;
                    current_state = STATE_RUN_TEST1;
                }
                break;

            case STATE_RUN_TEST1:
                run_test_without_dma();
                current_state = STATE_WAIT_TEST2;
                printf("\n\rApasa butonul pentru TEST 2 (CU DMA)...\n\r");
                break;

            case STATE_WAIT_TEST2:
                if(button_pressed) {
                    button_pressed = 0;
                    current_state = STATE_RUN_TEST2;
                }
                break;

            case STATE_RUN_TEST2:
                run_test_with_dma();
                current_state = STATE_DONE;
                print_results();
                break;

            case STATE_DONE:
                if(button_pressed) {
                    button_pressed = 0;
                    current_state = STATE_IDLE;
                    print_welcome();
                }
                break;
        }
    }

    return 0;
}

/* ============== Hardware Init ============== */
static void init_hardware(void)
{
    // GPIO pentru LED (PA5)
    vDo_AHB1ENR_EnableClockAccessToGPIO(GPIO_PORT_A);
    gpio_config_t led_cfg;
    led_cfg.direction = OUTPUT;
    vDoConfigDirection(GPIO_PORT_A, PIN_5, led_cfg);

    // UART
    vDoUSARTx_cfg();

    // DMA pentru UART TX
    dma_uart_init();

    // Buton interrupt (PC13)
    PC13_exti_init();
}

/* ============== Init Test Buffer ============== */
static void init_test_buffer(void)
{
    // Umple buffer-ul cu 'A'
    memset(test_buffer, 'A', TEST_BUFFER_SIZE);
}

/* ============== Print Welcome ============== */
static void print_welcome(void)
{
    printf("\n\r");
    printf("======================================================\n\r");
    printf("       DMA TEST - STM32F446RE\n\r");
    printf("======================================================\n\r");
    printf("Acest test compara performanta CPU:\n\r");
    printf("  - TEST 1: Trimite 500 bytes FARA DMA (blocking)\n\r");
    printf("  - TEST 2: Trimite 500 bytes CU DMA (non-blocking)\n\r");
    printf("\n\r");
    printf("In timpul transferului, CPU numara intr-un loop.\n\r");
    printf("Counter mai mare = CPU mai liber!\n\r");
    printf("======================================================\n\r");
    printf("\n\rApasa butonul pentru TEST 1 (FARA DMA)...\n\r");
}

/* ============== Toggle LED ============== */
static void toggle_led(void)
{
    GPIO_A_REG->GPIOx_ODR ^= (1 << 5);
    led_toggles++;
}

/* ============== TEST 1: Fără DMA ============== */
static void run_test_without_dma(void)
{
    printf("\n\r");
    printf("------------------------------------------------------\n\r");
    printf("TEST 1: FARA DMA (Blocking)\n\r");
    printf("------------------------------------------------------\n\r");
    printf("Trimit %d caractere...\n\r", TEST_BUFFER_SIZE);
    printf("\n\r");

    // Reset contoare
    cpu_counter = 0;
    led_toggles = 0;

    // Trimite BLOCKING - CPU ocupat tot timpul
    // Nu putem număra în paralel deoarece funcția blochează
    uart_send_buffer_blocking(test_buffer, TEST_BUFFER_SIZE);

    // Counter-ul rămâne 0 pentru că CPU a fost blocat

    printf("\n\r\n\r");
    printf("Transfer complet!\n\r");
    printf("  Counter CPU: %lu\n\r", cpu_counter);
    printf("  LED toggles: %lu\n\r", led_toggles);
    printf("------------------------------------------------------\n\r");

    // Salvează rezultatele
    result_test1_counter = cpu_counter;
    result_test1_toggles = led_toggles;
}

/* ============== TEST 2: Cu DMA ============== */
static void run_test_with_dma(void)
{
    printf("\n\r");
    printf("------------------------------------------------------\n\r");
    printf("TEST 2: CU DMA (Non-blocking)\n\r");
    printf("------------------------------------------------------\n\r");
    printf("Trimit %d caractere cu DMA...\n\r", TEST_BUFFER_SIZE);
    printf("\n\r");

    // Reset contoare
    cpu_counter = 0;
    led_toggles = 0;
    transfer_done = 0;

    // Pornește DMA transfer (non-blocking!)
    dma_uart_send(test_buffer, TEST_BUFFER_SIZE);

    // CPU numără și face toggle LED cât timp DMA lucrează în background
    while(!transfer_done) {
        cpu_counter++;
        if(cpu_counter % 100000 == 0) {
            //for(volatile uint32 i = 0; i < 10000; i++);
            toggle_led();
        }
    }

    // Așteaptă puțin să se termine ultimul byte pe UART
    for(volatile uint32 i = 0; i < 10000; i++);

    printf("\n\r\n\r");
    printf("Transfer complet!\n\r");
    printf("  Counter CPU: %lu\n\r", cpu_counter);
    printf("  LED toggles: %lu\n\r", led_toggles);
    printf("------------------------------------------------------\n\r");

    // Salvează rezultatele
    result_test2_counter = cpu_counter;
    result_test2_toggles = led_toggles;
}

/* ============== Print Results ============== */
static void print_results(void)
{
    printf("\n\r");
    printf("======================================================\n\r");
    printf("               REZULTATE COMPARATIE\n\r");
    printf("======================================================\n\r");
    printf("  FARA DMA Counter:  %lu\n\r", result_test1_counter);
    printf("  CU DMA Counter:    %lu\n\r", result_test2_counter);
    printf("\n\r");

    if(result_test2_counter > result_test1_counter && result_test1_counter > 0) {
        uint32 ratio = result_test2_counter / result_test1_counter;
        printf("  CPU a fost de ~%lux mai liber cu DMA!\n\r", ratio);
    } else if(result_test2_counter > 0 && result_test1_counter == 0) {
        printf("  CPU complet blocat fara DMA, liber cu DMA!\n\r");
    } else {
        printf("  Eroare - verifica implementarea\n\r");
    }

    printf("======================================================\n\r");
    printf("\n\rApasa butonul pentru a reporni testul...\n\r");
}

/* ============== Interrupt Handlers ============== */

// Buton PC13
void EXTI15_10_IRQHandler(void)
{
    if((EXTI->PR & (1 << 13)) != 0) {
        EXTI->PR |= (1 << 13);  // Clear pending
        button_pressed = 1;
    }
}

// NOTĂ: DMA1_Stream6_IRQHandler este în dma.c
