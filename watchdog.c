#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// Watchdog zaman aşımı süresi (milisaniye cinsinden)
#define WATCHDOG_TIMEOUT_MS 5000

// Watchdog durumu
bool watchdog_reset = false;

// Watchdog işleyicisi (simüle edilmiş)
void watchdog_handler(void) {
    // Watchdog zaman aşımına uğradığında gerçekleştirilmesi gereken işlemler burada yapılır
    printf("Watchdog zaman aşımına uğradı! Sistem yeniden başlatılıyor...\n");
    // Sistem yeniden başlatma işlemi burada simüle edilir
    watchdog_reset = true;
}

// Watchdog sıfırlama işlemi (simüle edilmiş)
void watchdog_reset_handler(void) {
    // Watchdog sıfırlama işlemi burada simüle edilir
    printf("Watchdog sıfırlama işlemi gerçekleştirildi.\n");
    watchdog_reset = false;
}

int main(void) {
    printf("Watchdog kullanımı başlıyor...\n");

    while (1) {
        // Watchdog sıfırlama işlemi simüle edilir (örneğin, her döngüde sıfırlanır)
        watchdog_reset_handler();

        // Sistem işlemleri burada gerçekleştirilir
        printf("Sistem işlemleri devam ediyor...\n");

        // Watchdog zaman aşımını simüle etmek için bir süre bekleyin
        for (uint32_t i = 0; i < WATCHDOG_TIMEOUT_MS; i++) {
            // İşlemciyi meşgul etmek için bir şeyler yapabilirsiniz
        }

        // Watchdog zaman aşımını kontrol et
        if (!watchdog_reset) {
            // Watchdog zaman aşımına uğrarsa, işleyiciyi çağırın
            watchdog_handler();
        }
    }

    return 0;
}
