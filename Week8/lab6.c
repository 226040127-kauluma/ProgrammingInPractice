#include <stdio.h>

int searchEmployee(int id, int ids[], int size) {
    for(int i = 0; i < size; i++) {
        if(ids[i] == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int id, pos;
    int size = 5;

    printf("Enter employee ID: ");
    scanf("%d", &id);

    pos = searchEmployee(id, employeeIDs, size);

    if(pos!= -1) {
        printf("Employee found at position %d.\n", pos);
    } else {
        printf("Employee not found.\n");
    }
    return 0;
}