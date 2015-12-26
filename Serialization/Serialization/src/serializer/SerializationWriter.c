#include "SerializationWriter.h"

int writeByte(byte buffer[], int size, int pointer, byte value)
{
	buffer[pointer++] = value;
	return pointer;
}

int writeShort(byte buffer[], int size, int pointer, Short value)
{
	buffer[pointer++] = (byte) ((value >> 8) & 0xff);
	buffer[pointer++] = (byte) ((value >> 0) & 0xff);
	return pointer;
}

int writeInt(byte buffer[], int size, int pointer, Int value)
{
	buffer[pointer++] = (byte) ((value >> 24) & 0xff);
	buffer[pointer++] = (byte) ((value >> 16) & 0xff);
	buffer[pointer++] = (byte) ((value >> 8) & 0xff);
	buffer[pointer++] = (byte) ((value >> 0) & 0xff);
	return pointer;
}

int writeLong(byte buffer[], int size, int pointer, Long value)
{
	buffer[pointer++] = (byte) ((value >> 56) & 0xff);
	buffer[pointer++] = (byte) ((value >> 48) & 0xff);
	buffer[pointer++] = (byte) ((value >> 40) & 0xff);
	buffer[pointer++] = (byte) ((value >> 32) & 0xff);
	buffer[pointer++] = (byte) ((value >> 24) & 0xff);
	buffer[pointer++] = (byte) ((value >> 16) & 0xff);
	buffer[pointer++] = (byte) ((value >> 8) & 0xff);
	buffer[pointer++] = (byte) ((value >> 0) & 0xff);
	return pointer;
}

int writeFloat(byte buffer[], int size, int pointer, float value)
{
	// już działa ( wcześniej zapomnieliśmy o konkatenacji bitów )
	// liczba zmienno przecinkowa float będzie postaci (-1)^s * 2^c * m
	// w pamięci jest to reprezentowane odwrotnie mantisa * 2^exponent * (-1)^sign
	// IEEE754 single precision
	float_bits f;
	f.number = value;
	Int bits = (f.float_parts.sign << 31) | (f.float_parts.exponent << 23) | f.float_parts.mantisa;
	pointer = writeInt(buffer, size, pointer, bits);

	return pointer;
}

int writeDouble(byte buffer[], int size, int pointer, double value)
{
	// wydaje się działać
	// IEEE754 double precision
	double_bits d;
	d.number = value;
	Long bits = (d.double_parts.sign << 63) | (d.double_parts.exponent << 52) | d.double_parts.mantisa;
	pointer = writeLong(buffer, size, pointer, bits);

	return pointer;
}

int writeChar(byte buffer[], int size, int pointer, char value)
{
	// this is only for API's sake...to have separate functionality
	// because byte is really char(but unsigned)
	buffer[pointer++] = (byte) ((value >> 8) & 0xff);
	buffer[pointer++] = (byte) ((value >> 0) & 0xff);
	return pointer;
}

int writeString(byte buffer[], int size, int pointer, String s)
{
	// wpisujemy rozmiar przed stringiem: (short)03 SEB
	// nie będzie znaku końca łańcucha \0
	pointer = writeShort(buffer, size, pointer, s.size);
	int i = 0;
	while (i < s.size)
	{
		pointer = writeChar(buffer, size, pointer, s.text[i]);
		i++;
	}
	return pointer;
}