#include <stdio.h>
#include <stdlib.h>
#include "serializer\SerializationWriter.h"
#include "serializer\SerializationReader.h"
#include "file\FileReader.h"

#define BUFFERSIZE 4

int main(int argc, char* argv[])
{

	byte buffer[BUFFERSIZE];
	File wejscie, wyjscie;
	wejscie = createFile("dane");
	int pointer = writeFloat(buffer, BUFFERSIZE, 0, 1.5f);
	writeToFile(wejscie, buffer, BUFFERSIZE);
	closeFile(wejscie);

	wyjscie = openFile("dane");
	byte wynik[BUFFERSIZE];
	readFromFile(wyjscie, wynik, BUFFERSIZE);
	float res = readFloat(wynik, BUFFERSIZE, 0);
	printf("%f\n", res);

	system("PAUSE");
	return 0;
}