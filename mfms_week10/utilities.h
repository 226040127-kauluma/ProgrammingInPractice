#ifndef UTILITIES_H
#define UTILITIES_H

int readInt(void);
float readFloat(void);
void readString(char *buffer, int size);

int getValidInt(void);
int getMenuChoice(int min, int max);
double getValidDouble(void);
void getValidString(char *buffer, int size);

#endif