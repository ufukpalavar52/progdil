/*

dictionary.h
C dilinde sozluk veri yapisi

*/


#define COUNT 70

// String tipinde veri tutan yapi

typedef struct {

	char* key;
	char *values[COUNT];

} 

DictionaryOfString;


// Sozluk tipinde veri tutan yapi

typedef struct {

	char* key;
	DictionaryOfString values[2];

}

Dictionary[];


// Sozlukten parametre olarak girilen anahtara karsilik gelen string dizisini dondurme

DictionaryOfString* GetDictionaries(Dictionary dict, char* key) {

	if (dict[0].key == key)

		return dict[0].values;

	else

		return dict[1].values;

}

char** GetValues(DictionaryOfString dict[], char* key) {

	for (int i = 0; i < COUNT; i++)

		if (dict[i].key == key)

			return dict[i].values;

}
