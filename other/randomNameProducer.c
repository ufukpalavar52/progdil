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

	gets(language);
	str_tolower(language);
	
	if(strcmp(language,"") == 0 ) {
		
		checkWord(1, "tr");
		getchar();
		return 0;

	} else if(strcmp(language,"tr") != 0 && strcmp(language,"en") != 0 ) {
		
		printf("Boyle dil secenegi yoktur tekrar deneyin:");
		goto again;
	
	} else
		printf("Uretilecek isim adedi:");

tryAgain:

	scanf("%s", number);
	numbercontrol = numberControl(number);

	if(numbercontrol == 1) {
		x = atoi(number);
		checkWord(x, language);
	} else {
		printf("Lutfen sayi giriniz: ");
		goto tryAgain;
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
