#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

// Simüle edilen bir DAC için voltaj değerini hesaplayan işlev
double calculateVoltage(uint16_t digitalValue) {
    // Gerçek bir DAC çipi kullanıldığında burada voltaj hesaplaması yapılmalıdır
    // Simülasyon için basit bir dönüşüm: [0, 4095] aralığındaki dijital değeri [0.0, 5.0] V'ye dönüştürürüz
    return (5.0 * (double)digitalValue) / 4095.0;
}

int main() {
    // DAC çıkışını simüle etmek için bir döngü
    for (uint16_t digitalValue = 0; digitalValue <= 4095; digitalValue += 100) {
        double voltage = calculateVoltage(digitalValue);
        printf("Dijital Değer: %u, Voltaj: %.2f V\n", digitalValue, voltage);

        // DAC çıkışını belirtilen voltaj değeriyle güncellemek için bir işlem ekleyebilirsiniz.
        // Gerçek bir uygulamada, DAC çipine özel bir kütüphane veya sürücü kullanacaksınız.

        // Belirli bir süre bekleyin (örneğin, 1 saniye)
        sleep(1);
    }

    return 0;
}
