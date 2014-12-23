#include <stdio.h>
#include <string.h>
#include <curses.h>
#define max 100

void replace_usws (char []);

int main() {

    char word[max];
    printf ("\n\x1B[1;44;37mMetin: ");
    scanf ("%[^\n]s", word);
    replace_usws (word);
    return 0;
}

void replace_usws (char  word[]) {

    int needle, wordstart, wordend;
    needle, wordstart = 0;
    wordend = strlen(word);
	
  for (needle = 0; wordstart < wordend; needle++) {
		if (word[needle] != '_') {
			
			wordstart = needle;
		}

  for (needle = wordend; wordend > 0; needle--) {
    if (word[needle] != '_') {
      
      wordend = needle;
    }

		printf ("\x1B[1;42;37m%c", word[needle]);   
	}

	printf ("\x1B[0m\n\n");
}
