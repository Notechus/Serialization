#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED
#include <inttypes.h>
#include <stdio.h>

/**
 *
 * W tym pliku znajdują się definicje wszystkich typów używanych w programie
 *
 */

// char jest gwarantowany 1 bajtowy
typedef uint8_t byte; // definiujemy bajt jako liczbe o wielkości 1 bajt (masło maślane, ale tak jest)
typedef int16_t Short; // niezależny od platformy 2 bajtowy short
typedef int32_t Int; // niezależny od platformy 4 bajtowy int
typedef int64_t Long; // niezależny od platformy 8 bajtowy long

/* Struktura pozwalająca na wydobycie bitów z typu float */
typedef union
{
	// jailbreak: works
	float number;
	struct
	{
		unsigned int mantisa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	} float_parts;
} float_bits;

/* Struktura pozwalająca na wydobycie bitów z typu double */
typedef union
{
	// jailbreak: works
	double number;
	struct
	{
		unsigned long long mantisa : 52; // musi być long long jeśli na danej maszynie long jest 32 bitowy
		unsigned long long exponent : 11;
		unsigned long long sign : 1;
	} double_parts;
} double_bits;

typedef struct
{
	int size;
	char* text;
} String;

// struktura zawierająca wskaźnik do pliku (wrapper dla wskaźnika) oraz ilość bajtów
typedef struct
{
	FILE* opened_file;
	uint32_t byte_count;
} File;

typedef struct
{
	// (x,y)
	float x;
	float y;
} Point;

typedef struct
{
	// a+bi
	float a;
	float b;
} Complex;

typedef struct
{
	//  a/b
	int32_t numerator;
	uint32_t denominator;
} Fraction;

typedef struct
{
	// y = ax + b
	float a;
	float b;
} Line;

typedef struct
{
	// ax^2 + bx + c
	float a;
	float b;
	float c;
} Quadratic;

typedef struct
{
	uint8_t day;
	uint8_t month;
	uint16_t year;
} Data;

typedef struct
{
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
} Time;

#endif