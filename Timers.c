#include "stm32f4xx.h"

// Zamanlayıcı kesmesi (TIM2) işleyicisi
void TIM2_IRQHandler(void) {
    // Zamanlayıcı kesme bayrağını sıfırla
    if (TIM2->SR & TIM_SR_UIF) {
        TIM2->SR &= ~TIM_SR_UIF;

        // LED'in durumunu tersine çevir
        if (GPIOA->ODR & GPIO_ODR_ODR_5) {
            GPIOA->BSRRH = GPIO_BSRR_BS_5; // LED'i kapat
        } else {
            GPIOA->BSRRL = GPIO_BSRR_BS_5; // LED'i aç
        }
    }
}

int main(void) {
    // RCC (Reset ve Clock Control) ayarları
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // GPIOA'yı etkinleştir
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // TIM2'yi etkinleştir

    // GPIOA ayarları
    GPIOA->MODER |= GPIO_MODER_MODER5_0; // GPIOA Pin 5'i çıkış olarak ayarla

    // TIM2 ayarları
    TIM2->PSC = 8399;  // Prescaler değeri (84 MHz'den 10 kHz'e düşürür)
    TIM2->ARR = 9999;  // Otomatik yeniden yükleme değeri (10 kHz'de 1 saniye)
    TIM2->DIER |= TIM_DIER_UIE; // Zamanlayıcı kesme etkinleştir

    // NVIC (Nested Vectored Interrupt Controller) ayarları
    NVIC_EnableIRQ(TIM2_IRQn);
    NVIC_SetPriority(TIM2_IRQn, 0);

    // Zamanlayıcıyı başlat
    TIM2->CR1 |= TIM_CR1_CEN;

    while (1) {
        // Ana döngüde başka işler yapabilirsiniz
    }
}
