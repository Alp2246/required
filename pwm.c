#include "stm32f4xx.h"

void configurePWM() {
    // TIM3 ayarları
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; // TIM3'ü etkinleştir
    TIM3->PSC = 0; // Prescaler değeri (84 MHz'de)
    TIM3->ARR = 999; // Otomatik yeniden yükleme değeri (84 kHz'de 1 ms)
    
    // PWM modu ayarları
    TIM3->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; // PWM mod 1 etkinleştir (TIM3_CH1)
    TIM3->CCMR1 |= TIM_CCMR1_OC1PE; // Çıkışı güncellemeden önce ön yükleme etkinleştir
    TIM3->CCER |= TIM_CCER_CC1E; // TIM3_CH1 etkinleştir (PWM sinyali)
    
    // Çıkış pinini ayarla (PA6)
    GPIOA->MODER |= GPIO_MODER_MODER6_1; // PA6'ya alternatif fonksiyon atanır
    GPIOA->AFR[0] |= 0x02000000; // AF2 (TIM3) seçilir
}

void setPWMDutyCycle(uint16_t dutyCycle) {
    // PWM görev döngüsünü ayarla (0-1000 arası)
    TIM3->CCR1 = dutyCycle;
}

int main(void) {
    // RCC ayarları
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // GPIOA'yı etkinleştir

    configurePWM(); // PWM konfigürasyonu

    while (1) {
        // PWM parlaklık kontrolü (0-100%)
        for (uint16_t dutyCycle = 0; dutyCycle <= 1000; dutyCycle += 10) {
            setPWMDutyCycle(dutyCycle);
            for (volatile int i = 0; i < 10000; i++); // Gecikme
        }
    }
}
