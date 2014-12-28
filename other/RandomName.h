#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <direct.h>


#define MAX 84
#define Limit 5000


char string_list[Limit][MAX] = {0};


int random_name_producer(int number, char project_name[], char names[][MAX], char adjectives[][MAX], int namelen, int adjlen,int z)
{
	int i = 0, control, filecontrol;
	char str[MAX];

	FILE* Project_Name;

	if ((Project_Name = fopen(project_name, "a" )) == NULL)
		printf("Dosya Acilamadi");
	else
	{
		srand((long)time(NULL));
		
		for ( ; i<number; )
		{ 
			str[0] = 0;  
			strcat(str, adjectives[ (rand() % adjlen) ]);
			strcat(str, "-" );
			strcat(str, names[ (rand() % namelen) ]);
			
			control = string_control(str, string_list, i);
			filecontrol = file_control(str, project_name);
		    
			if (control == 1 && filecontrol == 1)
			{
			   strcat(string_list[i],str);
			   Print_screen(i);
			   fprintf(Project_Name,"\n%s",str);
			   create_folder(str,z);
			   i++;
			}
		}
		
		fclose(Project_Name);
	}
}


int string_control(char string[],char string_list_control[][MAX], int count)
{
	int i = 0, d = 1;
	for ( ; i<=count;  )
	{
		if(strcmp(string_list_control[i], string) != 0 )
			d = 1;
		else {
			d = 0;
			break;
		}
		i++;
	}
	return d;
}

int file_control( char string[] ,char project_name[] )
{

	char file_string_list[MAX];
        int d;

	FILE* project_name_read;

	if ((project_name_read = fopen(project_name, "r")) == NULL)
		printf("Dosya acilmadi");
	else
		while (!feof(project_name_read))
		{
		   fscanf(project_name_read, "%s", file_string_list);
		   if( strcmp(file_string_list, string) != 0 )
			  d = 1;
		   else {
			  d = 0;
			  break;
		   }
		}
	
	
	fclose(project_name_read);
	return d;
}


int create_folder(char str[], int z)
{
	char s[MAX];

	if (z == 0 ) {
	    strcpy(s,"turkce-proje-ismi//");
	    mkdir(s);
	} else if (z == 1) {
		strcpy(s,"english-project-name//");
		mkdir(s);
	}

    
	strcat(s, str);
	mkdir(s);
	
}

int Print_screen(int i)
{
	printf("\n%d. %s",i+1, string_list[i]);

}

int str_tolower(char str[] )
{
	int x = strlen(str), i;
	for (i = 0; i < x; i++)
	       str[i] = tolower(str[i]);
}


int vocable_number (char k[][MAX])
{
	int i = 0, t, d = 1;
	
	while( d != 0) {
		if (strcmp("", k[i]) == 0)
			d = 0;
		else
		        i++;	
	}

	return i;
}

