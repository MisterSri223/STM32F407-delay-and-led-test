#include "main.h"

void delay(uint32_t time_ms) {
    uint32_t count = 0;
    TIM1 -> SR &= ~TIM_SR_UIF;                              //Clear flag before delay
    while (count < time_ms) {
        if (TIM1 -> SR & TIM_SR_UIF) {
            count += 1;                                     //increase count everytime UIF set
            TIM1 -> SR &= ~TIM_SR_UIF; 
        }
    }
}
//led sequence
void led(uint32_t speed) {
    GPIOD -> ODR |= GPIO_ODR_ODR_12;
    delay(speed);
    GPIOD -> ODR &= ~GPIO_ODR_ODR_12;
    GPIOD -> ODR |= GPIO_ODR_ODR_13;
    delay(speed);
    GPIOD -> ODR &= ~GPIO_ODR_ODR_13;
    GPIOD -> ODR |= GPIO_ODR_ODR_14;
    delay(speed);
    GPIOD -> ODR &= ~GPIO_ODR_ODR_14;
    GPIOD -> ODR |= GPIO_ODR_ODR_15;
    delay(speed);
    GPIOD -> ODR &= ~GPIO_ODR_ODR_15;
}
//setup
void setup() {
    clock_setup();
    gpio_setup();
    timer_setup();

    //reset everypin to 0
    GPIOD -> ODR &= ~(GPIO_ODR_ODR_12 | 
                    GPIO_ODR_ODR_13 | 
                    GPIO_ODR_ODR_14 | 
                    GPIO_ODR_ODR_15);
}