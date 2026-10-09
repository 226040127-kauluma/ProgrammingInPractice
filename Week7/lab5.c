#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100] = "ABC Office Supplies";
    char town[50] = "Windhoek";
    char sentence[200];

    strcpy(sentence, name);
    strcat(sentence, " operates in ");
    strcat(sentence, town);
    strcat(sentence, ".");

    printf("%s\n", sentence);
    return 0;
}