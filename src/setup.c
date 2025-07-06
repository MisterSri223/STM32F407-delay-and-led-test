#include "main.h"

void clock_setup() {
    RCC -> AHB1ENR |= RCC_AHB1ENR_GPIODEN;                  //enable GPIO D
    RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;                   //enable timer1
}
void gpio_setup() {
    //set pin 12, 13, 14, 15 to output mode
    GPIOD -> MODER |= GPIO_MODER_MODE12_0;
    GPIOD -> MODER |= GPIO_MODER_MODE13_0;
    GPIOD -> MODER |= GPIO_MODER_MODE14_0;
    GPIOD -> MODER |= GPIO_MODER_MODE15_0;
}
void timer_setup() {
    TIM1 -> PSC = 15;                                       //prescale 16MHz/(15+1) = 1MHz
    TIM1 -> ARR = 999;                                      //autoreload 1MHz/(999+1) = 1kHz
    TIM1 -> CR1 |= TIM_CR1_URS;                             //Only counter overflow/underflow generates an update interrupt.
    TIM1 -> DIER |= TIM_DIER_UIE;                           //Update interrupt enabled
    TIM1 -> SR &= ~TIM_SR_UIF;                              //Clear any pending update interrupt flag (UIF)

    TIM1 -> CR1 |= TIM_CR1_CEN;                             //enable timer1
}
