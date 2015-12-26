#include "SerializationReader.h"

byte readByte(byte buffer[], int pointer)
{
	return buffer[pointer];
}

Short readShort(byte buffer[], int size, int pointer)
{
	return (Short) (buffer[pointer] << 8 | buffer[pointer + 1]);
}

Int readInt(byte buffer[], int size, int pointer)
{
	return (Int) (buffer[pointer] << 24 | buffer[pointer + 1] << 16) | (buffer[pointer + 2] << 8 | buffer[pointer + 3]);
}

Long readLong(byte buffer[], int size, int pointer)
{
	return (Long) (buffer[pointer] << 56 | buffer[pointer + 1] << 48 | buffer[pointer + 2] << 40 | buffer[pointer + 3] << 32)
		| (buffer[pointer + 4] << 24 | buffer[pointer + 5] << 16 | buffer[pointer + 6] << 8 | buffer[pointer + 7]);
}

float readFloat(byte buffer[], int size, int pointer)
{
	// 1bit, 8bit, 23bit
	float_bits f;
	Int se = readInt(buffer, size, pointer); // konkatenacja bitów znaku, exp i mantysy ( razem 32 bity)
	f.float_parts.sign = (se & 0x80000000) >> 31;
	f.float_parts.exponent = (se & 0x7f800000) >> 23;
	f.float_parts.mantisa = (se & 0x7fffff);

	return f.number;
}

double readDouble(byte buffer[], int size, int pointer)
{
	// 1bit, 11bit, 52bit
	double_bits d;
	Long se = readLong(buffer, size, pointer);
	d.double_parts.sign = (se & 0x8000000000000000) >> 63;
	d.double_parts.exponent = se & 0x7ff00000000000000l;
	return 0.0;
}

char readChar(byte buffer[], int size, int pointer)
{
	return (char) (buffer[pointer] << 8 | buffer[pointer + 1]);
}

char* readString(byte buffer[], int size, int pointer, int *string_size)
{
	return 0;
}