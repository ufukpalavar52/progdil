#include <stdio.h>
#include <string.h>
#include "RandomName.h"

int numberControl(char number[]);

int main()
{
	int t, i, numbercontrol, x;
	char language[10], number[5];
	
	printf("Turkce rastgele isim icin : tr"
		   "\nFor English random name : en"
		   "\nSelect: ");

again:

	scanf("%s",language);
	str_tolower(language);

	if(strcmp(language,"tr") != 0 && strcmp(language,"en") != 0 ) {
		printf("Boyle dil secenegi yoktur tekrar deneyin:");
		goto again;
	
	}

	printf("Uretilecek isim adedi:");

numberAgain:

	scanf("%s", number);
	numbercontrol = numberControl(number);

	if(numbercontrol == 1) {
		x = atoi(number);
		checkWord(x, language);
	} else {
		printf("Lutfen sayi giriniz: ");
		goto numberAgain;
	}

	getchar();
	getchar();
	return 0;
}

int numberControl(char number[])
{
	int len, i, d;
	len = strlen(number);
	for(i = 0; i< len; i++){
		if(isdigit(number[i]) != 0)
			d = 1;
		else {
		    d = 0;
			break;
		}
	}

	return d;
}


