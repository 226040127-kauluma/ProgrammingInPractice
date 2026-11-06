#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilities.h"

#define LINE_SIZE 256

static int readLine(char *line, int size)
{
    if (fgets(line, size, stdin) == NULL) {
        return 0;
    }
    line[strcspn(line, "\n")] = '\0';
    return 1;
}

int readInt(void)
{
    char line[LINE_SIZE];
    char *end;
    long value;
    while (1) {
        if (!readLine(line, LINE_SIZE)) return 0;
        if (line[0] == '\0') {
            printf("Input cannot be empty. Enter a whole number: ");
            continue;
        }
        value = strtol(line, &end, 10);
        while (isspace((unsigned char)*end)) end++;
        if (*end != '\0') {
            printf("Invalid input. Enter a whole number: ");
            continue;
        }
        return (int)value;
    }
}

float readFloat(void)
{
    char line[LINE_SIZE];
    char *end;
    float value;
    while (1) {
        if (!readLine(line, LINE_SIZE)) return 0.0f;
        if (line[0] == '\0') {
            printf("Input cannot be empty. Enter a number: ");
            continue;
        }
        value = strtof(line, &end);
        while (isspace((unsigned char)*end)) end++;
        if (*end != '\0') {
            printf("Invalid input. Enter a number: ");
            continue;
        }
        if (value < 0) {
            printf("Value cannot be negative. Enter a number: ");
            continue;
        }
        return value;
    }
}

void readString(char *buffer, int size)
{
    char line[LINE_SIZE];
    int i;
    int hasText;
    while (1) {
        if (!readLine(line, LINE_SIZE)) {
            buffer[0] = '\0';
            return;
        }
        hasText = 0;
        for (i = 0; line[i] != '\0'; i++) {
            if (!isspace((unsigned char)line[i])) hasText = 1;
        }
        if (!hasText) {
            printf("Input cannot be empty. Try again: ");
            continue;
        }
        if ((int)strlen(line) >= size) {
            printf("Too long (maximum %d characters). Try again: ", size - 1);
            continue;
        }
        strcpy(buffer, line);
        return;
    }
}

int getValidInt(void) { return readInt(); }

int getMenuChoice(int min, int max)
{
    int choice;
    while (1) {
        choice = readInt();
        if (choice >= min && choice <= max) return choice;
        printf("Invalid choice. Enter a number from %d to %d: ", min, max);
    }
}

double getValidDouble(void) { return (double)readFloat(); }
void getValidString(char *buffer, int size) { readString(buffer, size); }