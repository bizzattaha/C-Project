//
// Created by Bilal Karabulut on 6.05.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    printf("-----------------------------------------------------------------\n");
    printf("------------------------Sifreleme Programi------------------------\n");
    printf("-----------------------------------------------------------------\n");

    int sayi, bas1, bas2, bas3, bas4, bas5, sifreli_sayi;
    char c, islem;

    while (1) {
        printf("Lutfen 5 basamakli bir sayi giriniz: ");
        if (scanf("%d", &sayi) != 1 || sayi < 10000 || sayi > 99999) {
            printf("Gecersiz giris yaptiniz, lutfen tekrar deneyin.\n");
            while ((c = getchar()) != '\n' && c != EOF); // bufferi temizle
            continue;
        }
        break;
    }

    while (1) {
        printf("\nSayi girisiniz basarili, girilen sayiyi sifrelemek icin P'e, cikis icin E'ye basiniz: ");
        scanf(" %c", &islem);
        islem = toupper(islem); // seçim harfini büyük harfe dönüştür
        if (islem == 'P') {
            bas1 = (sayi / 10000 + 9) % 10;
            bas2 = (sayi % 10000 / 1000 + 9) % 10;
            bas3 = (sayi % 1000 / 100 + 9) % 10;
            bas4 = (sayi % 100 / 10 + 9) % 10;
            bas5 = (sayi % 10 + 9) % 10;

            sifreli_sayi = bas1 * 10000 + bas3 * 1000 + bas2 * 100 + bas4 * 10 + bas5;

            printf("\nSifreli sayiniz: %d\n", sifreli_sayi);
            break;
        } else if (islem == 'E') {
            printf("\nCikis yaptiniz...\n");
            break;
        } else {
            printf("\nGecersiz giris yaptiniz, lutfen P veya E harfini girin.\n");
            while ((c = getchar()) != '\n' && c != EOF); // bufferi temizle
            continue;
        }
    }

    return 0;
}
