#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <words.h>


// fonksiyon prototipleri

char** Generate (char*, int);
int Random (int);
char* StringMergeWithSpace (char*, char*);

int main (int argc, char *argv []) {

	// random fonksiyonu icin seeder ayari

	srand (time (NULL));

	// varsayilan parametreler

	char* language = "tr";
	int count = 10;

	// komut satiri parametreleri

	if (argc == 2) {

		language = (char*) argv [1];

	}

	else if (argc == 3) {

		language = (char*) argv [1];
		count = (int) atoi(argv [2]);

	}

	else if (argc > 3) {

		printf("\n\x1B[1;41;37mWrong parameters: random_name [lang] [number]\nAssuming default values.\x1B[0m\n");

	}
	
	char** results = Generate (language, count);

	printf("\n\x1B[1;44;37m\n\x1B[0m\n");

	for (int i = 0; i < count; i++)

		printf("\x1B[1;42;37m%d.\t%s\n", i+1, results[i]);

	printf("\x1B[1;44;37m\n\x1B[0m\n\n");
	return 0;
}


// isim-sifat cifti uretici

char** Generate (char* language, int count) {

	// sonuc dizisi icin bellekten yer talebi

	char** resultArray = malloc (sizeof(char*) * count);

	// sonuc dizisinin hazirlanmasi

	for (int i = 0; i < count; i++) {

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

// sayi uretici

int Random (int maxRange) {

	return rand () % maxRange;

}

// iki stringi aralarina bosluk karakteri yerlestirerek birlestirme

char* StringMergeWithSpace (char* str1, char* str2) {

	int length1 = strlen (str1);
	int length2 = strlen (str2);

	char* result = (char*) malloc ((length1 + length2) * sizeof (char));

	for (int i = 0; i < length1; i++)

		result [i] = str1 [i];

	result [length1] = ' ';

	for (int i = 0; i < length2; i++)

		result [i + length1 + 1] = str2[i];

	return result;

}
