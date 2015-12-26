#ifndef SR_H_INCLUDED
#define SR_H_INCLUDED
#include "..\type\Type.h"

// place for defines
#define VERSION 0x0001

// place for functions
byte readByte(byte buffer[], int size, int pointer);

Short readShort(byte buffer[], int size, int pointer);

Int readInt(byte buffer[], int size, int pointer);

Long readLong(byte buffer[], int size, int pointer);

float readFloat(byte buffer[], int size, int pointer);

double readDouble(byte buffer[], int size, int pointer);

char readChar(byte buffer[], int size, int pointer);

char* readString(byte buffer[], int size, int pointer, int *string_size);

#endif 