#ifndef FR_H_INCLUDED
#define FR_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include "..\type\Type.h"

File openFile(const char* name);

File createFile(const char* name);

void writeToFile(File f, byte buffer[], int size);

void readFromFile(File f, byte buffer[], int size);

void closeFile(File f);

#endif