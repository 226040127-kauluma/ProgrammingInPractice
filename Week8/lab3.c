#include <stdio.h>

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

int main() {
    float basic, housing, transport;
    printf("Basic salary: ");
    scanf("%f", &basic);
    printf("Housing allowance: ");
    scanf("%f", &housing);
    printf("Transport allowance: ");
    scanf("%f", &transport);
    printf("\nGross salary: %.2f\n", calculateSalary(basic, housing, transport));
    return 0;
}