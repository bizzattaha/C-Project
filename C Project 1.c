#include <stdio.h>

void print_duration(int months) {
    int years = months / 12;
    int remainingMonths = months % 12;
    printf("Yıl: %d, Ay: %d\n", years, remainingMonths);
}

void print_money(float amount) {
    printf("%.1f $\n", amount);
}

void print_entry(float loanAmount, float interestRate, int months) {
    printf("Kredi Tutarı: ");
    print_money(loanAmount);
    
    printf("Yıllık Faiz Oranı: %.2f\n", interestRate);
    
    printf("Süre: ");
    print_duration(months);
    
    float totalInterest = (loanAmount / 100) * (interestRate / 12) * months;
    printf("Toplam Faiz Tutarı: ");
    print_money(totalInterest);
    
    float monthlyPayment = (loanAmount + totalInterest) / months;
    printf("Aylık Ödeme: ");
    print_money(monthlyPayment);
    
    printf("------------------------\n");
}

int main() {
    char name[100];
    float interestRate, loanAmount;
    int maxYear, maxMonth, interval;
    char choice;
    
    printf("--------------------------------------------\n");
    printf("---- Welcome to the Interest Calculator ----\n");
    printf("--------------------------------------------\n");
    
    do {
        printf("Adınızı girin: ");
        scanf("%s", name);
        
        printf("Yıllık Faiz Oranı: ");
        scanf("%f", &interestRate);
        
        printf("Kredi Tutarı: ");
        scanf("%f", &loanAmount);
        
        printf("Maksimum Yıl: ");
        scanf("%d", &maxYear);
        
        printf("Maksimum Ay: ");
        scanf("%d", &maxMonth);
        
        printf("Yineleme Aralığı (Ay): ");
        scanf("%d", &interval);
        
        printf("------------------------\n");
        printf("Rapor:\n");
        printf("Kullanıcı: %s\n", name);
        printf("------------------------\n");
        
        int totalMonths = maxYear * 12 + maxMonth;
        int i;
        float totalLoanAmount = 0.0;
        float totalPayment = 0.0;
        float monthlyPayment;
        for (i = interval; i <= totalMonths; i += interval) {
            print_entry(loanAmount, interestRate, i);
            monthlyPayment = (loanAmount + ((loanAmount / 100) * (interestRate / 12) * i)) / i;
            totalLoanAmount += loanAmount;
            totalPayment += monthlyPayment;
        }
        printf("\n\n");
        printf("------------------------\n");
        printf("Kredi Raporu:\n");
        printf("Toplam Kredi Tutarı: ");
        print_money(totalLoanAmount);
        printf("Toplam Ödenecek Tutar: ");
        print_money(totalPayment);
        printf("Aylık Ödeme Tutarı: ");
        print_money(monthlyPayment);
        printf("Kredi Tutarı: ");
        print_money(loanAmount);
        
        printf("------------------------\n");
        printf("Devam etmek için 'Y' veya 'y' girin, Çıkmak için herhangi bir tuşa basın: ");
        scanf(" %c", &choice);
        printf("------------------------\n");
    } while (choice == 'Y' || choice == 'y');
    
    return 0;
}
