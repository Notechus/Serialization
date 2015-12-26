#ifndef SW_H_INCLUDED
#define SW_H_INCLUDED
#include "..\type\Type.h"

// place for defines
#define VERSION 0x0001

// place for functions
int writeByte(byte buffer[], int size, int pointer, byte value);

int writeShort(byte buffer[], int size, int pointer, Short value);

int writeInt(byte buffer[], int size, int pointer, Int value);

int writeLong(byte buffer[], int size, int pointer, Long value);

int writeFloat(byte buffer[], int size, int pointer, float value);

int writeDouble(byte buffer[], int size, int pointer, double value);

int writeChar(byte buffer[], int size, int pointer, char value);

int writeString(byte buffer[], int size, int pointer, String s);

#endif // SW_H_INCLUDED