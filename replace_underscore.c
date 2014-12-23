#include <stdio.h>
#include <string.h>
#include <curses.h>
#define MAX 100

void replace_usws (char []);

int main() {

    char word[MAX];
    int needle;
    printf ("\n\x1B[1;44;37mMetin: ");
    
    needle = 0;
    while (1) {
    	
    	scanf ("%c", &word[needle]);
       	if (word[needle] == '\n') {
       		
       		word[needle] = '\0';
		break;
	}

		needle++;
    }
    
    replace_usws (word);
    return 0;
}

void replace_usws (char  word[]) {
	
	int length, needle;
	length = strlen (word);
   	printf ("\n");
   	
	for (needle = 0; needle < length; needle++) {
		if (word[needle] == '_' && (needle > 0 && needle < length - 1 )) {
			
			word[needle] = ' ';
		}

		printf ("\x1B[1;42;37m%c", word[needle]);   
	}

	printf ("\x1B[0m\n\n");
}
