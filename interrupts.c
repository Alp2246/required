#include "stm32f4xx.h"
#include <stdio.h>

// Kesme işleyicisi (interrupt handler)
void TIM2_IRQHandler(void) {
    if (TIM2->SR & TIM_SR_UIF) {
        TIM2->SR &= ~TIM_SR_UIF;  // Zamanlayıcı kesme bayrağını sıfırla
        TIM2->CR1 &= ~TIM_CR1_CEN; // Zamanlayıcıyı kapat
    }
}

int main(void) {
    // RCC ayarları
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // GPIOA'yı etkinleştir
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // TIM2'yi etkinleştir

    // GPIO ayarları
    GPIOA->MODER |= GPIO_MODER_MODER0_0; // PA0'i çıkış olarak ayarla

    // TIM2 ayarları
    TIM2->PSC = 8399;  // Prescaler değeri (84 MHz'den 10 kHz'e düşürür)
    TIM2->ARR = 9999;  // Otomatik yeniden yükleme değeri (10 kHz'de 1 saniye)
    TIM2->DIER |= TIM_DIER_UIE; // Zamanlayıcı kesme etkinleştir

    // NVIC ayarları
    NVIC_EnableIRQ(TIM2_IRQn);
    NVIC_SetPriority(TIM2_IRQn, 0);

    while (1) {
        printf("Bir tuşa basın...\n");
        // Burada bir tuşa basılmasını bekleyen kod
        // Tuşa basıldığında, zamanlayıcıyı başlatmak için aşağıdaki kodu kullanabilirsiniz:
        // TIM2->CR1 |= TIM_CR1_CEN;
        // Ardından, kesme işleyicisi zamanlayıcıyı durduracaktır.
    }
}
