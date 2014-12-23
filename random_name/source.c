/*

prog_dil - isim uretici

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include </home/cihan/Desktop/prog_dil/random_name/words.h>

//
// fonksiyon prototipleri
//
char** Generate(char*, int);
int Random(int);
char* StringMergeWithSpace(char*, char*);

//
// main fonksiyonu
//
int main(int argc, char *argv[])
{
	// random fonksiyonu icin seeder ayari
	srand(time(NULL));

	// varsayilan parametreler
	char* language = "tr";
	int count = 10;

	// komut satiri parametreleri
	if (argc == 3)
	{
		language = (char*)argv[1];
		count = (long)argv[2];
	}
	
	char** results = Generate(language, count);

	for (int i = 0; i < count; i++)
		printf("%d. %s\n", i+1, results[i]);

	return 0;
}

//
// isim-sifat cifti uretici
//
char** Generate(char* language, int count)
{
	// sonuc dizisi icin bellekten yer talebi
	char** resultArray = malloc(sizeof(char*) * count);

	// sonuc dizisinin hazirlanmasi
	for (int i = 0; i < count; i++)
	{
		/*
		const char s[] = "";
		strcpy(s, GetValues(GetDictionaries(words, language), "names")[Random(COUNT)]);
		strcat(s, " ");
		strcat(s, GetValues(GetDictionaries(words, language), "adjectives")[Random(COUNT)]);
		*/
		
		resultArray[i] = StringMergeWithSpace(GetValues(GetDictionaries(words, language), "adjectives")[Random(COUNT)], GetValues(GetDictionaries(words, language), "names")[Random(COUNT)]);
	}

	return resultArray;
}

//
// sayi uretici
//
int Random(int maxRange)
{
	return rand() % maxRange;
}

//
// iki stringi aralarina bosluk karakteri yerlestirerek birlestirme
//
char* StringMergeWithSpace(char* str1, char* str2)
{
	int length1 = strlen(str1);
	int length2 = strlen(str2);

	char* result = (char*)malloc((length1 + length2) * sizeof(char));

	for (int i = 0; i < length1; i++)
		result[i] = str1[i];
	result[length1] = ' ';
	for (int i = 0; i < length2; i++)
		result[i + length1 + 1] = str2[i];


	return result;
}
