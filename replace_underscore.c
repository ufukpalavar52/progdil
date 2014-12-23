#include <stdio.h>
#include <string.h>

#define MAX 100

void replace_usws (char []);

int main() 
{

    char word[MAX];
    
    printf ("\n\x1B[1;44;37mMetin: ");
    
    gets(word);
    
    replace_usws (word);
    printf("\n%s", word);

	getchar();
	getchar();
        return 0;
}

void replace_usws (char  word[]) 
{
	
	int length, i, j;
	length = strlen (word);
   	printf ("\n");
   	
	for (i = 1; i < length-1; i++) 
		if (word[i] == '_'  &&  word[i-1] != '_' ) {
			word[i] = ' ';
		}


	for (j = length-1; j > 0; j--)
		if (word[j] == ' ' && ( word[j+1] == '_' || word[j-1] == '_' )) {
			word[j] = '_';
		 }
		 
}
