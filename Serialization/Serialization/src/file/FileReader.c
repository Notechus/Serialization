#include "FileReader.h"

File openFile(const char* name)
{
	// mode must be either wb or rb
	File f;
	f.opened_file = fopen(name, "rb");
	if (f.opened_file == NULL)
	{
		printf("Nie udalo sie otworzyc pliku.");
		return f;
	}
	fseek(f.opened_file, 0L, SEEK_END);
	f.byte_count = ftell(f.opened_file);
	fseek(f.opened_file, 0, SEEK_SET);
	return f;
}

void float_test()
{
	float number = 1.5f;
	FILE *file = fopen("foo.bin", "wb");
	size_t n = fwrite(&number, sizeof(number), 1, file); // wrzuca do pliku 0000 c03f (dziwna reprezentacja?)
	fclose(file);
}

File createFile(const char* name)
{
	// mode must be either wb or rb
	File f;
	f.opened_file = fopen(name, "wb");
	if (f.opened_file == NULL)
	{
		printf("Nie udalo sie otworzyc pliku.");
		return f;
	}
	return f;
}

void writeToFile(File f, byte buffer[], int size)
{
	size_t ret_code = fwrite(buffer, sizeof *buffer, size, f.opened_file);
	if (ret_code < (int) sizeof(buffer))
	{
		if (ferror(f.opened_file))
		{
			printf("Error occured while writing to file.\n");
		}
	}
}

void readFromFile(File f, byte buffer[], int size)
{
	// usually size will be the file size
	size_t ret_code = fread(buffer, sizeof *buffer, size, f.opened_file);
	if (ret_code == size) printf("Data were read succesfully.\n");
	else
	{
		// error handler
		if (feof(f.opened_file)) printf("Unexpected end of file.\n");
		else if (ferror(f.opened_file)) printf("Error reading file.");
	}
}

void closeFile(File f)
{
	f.byte_count = 0;
	fclose(f.opened_file);
}