#include <stdio.h>

float calculateVAT(float amount) {
    return amount * 0.15;
}

int main() {
    float amount;
    printf("Enter amount: ");
    scanf("%f", &amount);
    printf("VAT: %.2f\n", calculateVAT(amount));
    return 0;
}