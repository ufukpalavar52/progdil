#include <stdio.h>
#include <string.h>
#include <curses.h>

#define MAX 100

void ReplaceUnderscoreWithSpace (char []);

int main() {

    char kelime[MAX];
	int i;
	printf("\n\x1B[1;44;37mMetin: ");
	
	i=0;
	while (1) {

		scanf ("%c",&kelime[i]);
       	if (kelime[i] == '\n') {

		   kelime[i] = '\0';
		   break;

		}

		i++;

	}

	printf("\n");

	ReplaceUnderscoreWithSpace (kelime);

	getch();
	return 0;

}

void ReplaceUnderscoreWithSpace (char  kelime[]) {

	int uzunluk, i;
	uzunluk = strlen (kelime);
   
	for (i=0 ; i < uzunluk ; i++) {

		if (kelime[i] == '_' && (i > 0 && i < uzunluk - 1 ) ) {

			kelime[i] = ' ';

		}

		printf ("%c", kelime[i]);   
	}

	printf("\x1B[0m\n\n");
}
