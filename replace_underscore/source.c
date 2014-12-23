#include <stdio.h>
#include <string.h>
#define max 100

void replace_usws (char []);

int main () {

        char word [max];
        printf ("\n\x1B[1;44;37mMetin: ");
        scanf ("%[^\n]s", word);
        replace_usws (word);
        return 0;

}

void replace_usws (char  word[]) {

        int needle, wordstart, wordend;
        needle, wordstart = 0;
        wordend = strlen(word) - 1;

        for (needle = 0; wordstart < wordend; needle++) {

                if (word[needle] != '_') {
			
			wordstart = needle;
                        break;

		}

        }


        for (needle = wordend; wordend > 0; needle--) {

                if (word[needle] != '_') {
      
                        wordend = needle;
                        break;

                }

        }

        for (needle = wordstart; needle <= wordend; needle++) {

                if (word[needle] == '_') {

                        word[needle] = ' ';

                }
 
        }

        printf ("\x1B[1;42;37m%s\x1B[0m\n\n", word);

}
