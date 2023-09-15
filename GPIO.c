#include <stdio.h>
#include <wiringPi.h>

// GPIO pinini tanımla (BCM pin numarası olarak)
#define LED_PIN 18

int main() {
    // WiringPi'yi başlat (bu, GPIO pinlerini kullanmamıza olanak tanır)
    if (wiringPiSetupGpio() == -1) {
        printf("WiringPi başlatma hatası!\n");
        return 1;
    }

    // LED pini çıkış olarak ayarla
    pinMode(LED_PIN, OUTPUT);

    while (1) {
        // LED'i aç (HIGH)
        digitalWrite(LED_PIN, HIGH);
        printf("LED açık.\n");

        // Bir saniye bekleyin
        delay(1000);

        // LED'i kapat (LOW)
        digitalWrite(LED_PIN, LOW);
        printf("LED kapalı.\n");

        // Bir saniye daha bekleyin
        delay(1000);
    }

    return 0;
}
