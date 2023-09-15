#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

// Simüle edilen bir ADC'den veri okuyan işlev
uint16_t readADC() {
    // Burada gerçek bir ADC'nin kullanılacağını ve veri okuma işlevinin burada oluşturulacağını varsayalım
    // Simülasyon için rasgele bir değer döndürüyoruz
    return (uint16_t)(rand() % 1024);
}

int main() {
    // ADC veri okuma döngüsü
    for (int i = 0; i < 10; i++) {
        uint16_t adcValue = readADC();
        printf("Okunan ADC Değeri: %u\n", adcValue);

        // ADC verilerini işleyebilirsiniz (örneğin, ortalamasını alabilirsiniz)
        // İşleme kodunu buraya ekleyin

        // Belirli bir süre bekleyin (örneğin, 1 saniye)
        sleep(1);
    }

    return 0;
}
