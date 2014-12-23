#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <direct.h>


#define MAX 84
#define Limit 5000


char string_list[Limit][MAX] = {0};

int checkWord(int number, char language[])
{
	int i = 0, adjlen , namelen, z;
	char project_name[MAX]={0};
	char names[][MAX] =
	{
          "Anvil",
	  "Arrow",
	  "Apple",
	  "Balloon",
	  "Baseball",
	  "Bathtub",
	  "Candle",
	  "Canvas",
	  "Clock",
	  "Desert",
	  "Dew",
	  "Daw",
	  "Eag",
	  "Eraser",
	  "English",
	  "Flag",
	  "Flower",
	  "Flut",
	  "Glasses",
	  "Glowstick",
	  "Guilt",
	  "Hanger",
	  "Hat",
	  "Helmet",
	  "iceberg",
	  "icecube",
	  "ice",
	  "Jack",
	  "Jambon",
	  "Judo",	
	  "Kilt",
	  "Kite",
	  "Knife",
	  "Lace",
	  "Lamp",
	  "Leg warmers",
          "Mallet",
          "Map",
	  "Microphone",
	  "Nail",
	  "Needle",
	  "Nut",
	  "Password",
	  "Pen",
	  "Pencil",
	  "Radio",
	  "Receipt",
	  "Rock",
	  "Sandpaper",
	  "Scissors",
	  "Scotchtape",
	  "Thermometer",
	  "Thread",
	  "Tire",
	  "Uranus",
	  "Unusual",
	  "Unsightly",
	  "Voice",
	  "Valley",
	  "Volcano",
          "Wandering",
	  "Warm",
	  "waterfall",
	  "Zit",
	  "Zipper",
	  "Zoo",
	  ""
	};

	char adjectives[][MAX] =
	{
	  "Attractive",
	  "Average",
	  "Amiable",
	  "Beautiful",
	  "Big",
	  "Broad",
	  "Chubby",
	  "Clean",
	  "Colorful",
	  "Damaged",
	  "Dark",
	  "Deep",
	  "Energized",
	  "Energetic",
	  "Enigmatic",
	  "Fancy",
	  "Fat",
	  "Filthy",
	  "Gigantic",
	  "Gorgeous",
	  "Graceful",
	  "High",
	  "Hollow",
	  "Huge",
	  "Large",
	  "Little",
	  "Long",
	  "Mammoth",
	  "Massive",
	  "Miniature",
	  "Narrow",
	  "Natural",
	  "Nine",
	  "Outlet",
	  "One",
	  "One Hundred",
	  "Petite",
	  "Plain",
	  "Precious",
	  "Radioactive",
	  "Resilient",
	  "Right",
	  "Talented",
	  "Tasteless",
	  "Teal",
	  "Undisturbed",
	  "Unsightly",
	  "Unwavering",
	  "Voiceless",
	  "Wandering",
	  "Warm",
	  "Wealthy",
	  "Whispering",
	  "Zealous",
	  ""
	};
	
	char trAdjectives[][MAX]=
	{
	  "Ak",
	  "Akilli",
	  "Aliskin",
	  "Beyaz",
	  "Buyuk",
	  "Bos",
	  "Cimri",
	  "Caliskan",
	  "Comert",
	  "Dar",
	  "Dolu",
	  "Diri",
	  "Esnek",
	  "Esrarengiz",
	  "Esmer",
	  "Felek",
	  "Farkli",
	  "Firildak",
	  "Gri",
	  "Gevzek",
	  "Genc",
	  "Hain",
	  "Hasta",
	  "Hos",
	  "igrenc",
	  "ince",
	  "iri",
	  "Japon",
	  "Jiletci",
	  "Judocu",
	  "Kara",
	  "Kirli",
	  "Kirmizi",
	  "Lekeli",
	  "Lezzetli",
	  "Liseli",
	  "Mor",
	  "Maceraci",
	  "Mavi",
	  "Nahos",
	  "Naneli",
	  "Nisanci",
	  "Objectif",
	  "Obur",
	  "Orantili",
	  "Pahali",
	  "Pastaci",
	  "Pembe",
	  "Rahat",
	  "Renkli",
	  "Ruzgarli",
	  "Sabirli",
	  "Sabunlu",
	  "Siyah",
	  "Turuncu",
	  "Tahtali",
	  "Taklitci",
	  "Ugurlu",
	  "Umutlu",
	  "Unlu",
	  "Vakitkli",
	  "Vasitali",
	  "Verimli",
	  "Yakisikli",
	  "Yanik",
	  "Yesil",
	  "Zayif",
	  "Zehirli",
	  "Zor",
	  ""
	};

	char trNames[][MAX]=
	{
	  "Araba",
	  "Aslan",
	  "At",
	  "Baba",
	  "Balik",
	  "Bal",
	  "Cam",
	  "Cep",
	  "Ceviz",
	  "Dede",
	  "Dayi",
	  "Durak",
	  "Elma",
	  "Elmas",
	  "Erik",
	  "Fidan",
	  "Findik",
	  "Fok",
	  "Garaj",
	  "Gaz",
	  "Gemi",
	  "Hamsi",
	  "Hashas",
	  "Havuc",
	  "igne",
	  "inek",
	  "ip",
	  "Jaguar",
	  "Jimlastik",
	  "Judo",
	  "Kalem",
	  "Kestane",
	  "Kitap",
	  "Lastik",
	  "Liman",
	  "Limon",
	  "Mandalina",
	  "Marti",
	  "Muz",
	  "Naftalin",
	  "Nar",
	  "Not",
	  "Okul",
	  "Otobus",
	  "Oyku",
	  "Palamut",
	  "Patates",
	  "Pilot",
	  "Radar",
	  "Radyo",
	  "Ray",
	  "Saat",
	  "Sabun",
	  "Seker",
	  "Tabak",
	  "Tabiat",
	  "Tekerlek",
	  "Ufuk",
	  "Ucak",
	  "Uskumru",
	  "Vali",
	  "Vagon",
	  "Veli",
	  "Yakut",
	  "Yengec",
	  "Yelken",
	  "Zaman",
	  "Zeybek",
	  "Zumrut",
	  ""
	};
	
	if(strcmp(language,"tr") == 0) {

       z = 0;
	   strcat(project_name,"turkceProjeIsmi.txt");
	   namelen = vocable_number(trNames);
	   adjlen = vocable_number(trAdjectives);
	   random_name_producer(number, project_name, trNames, trAdjectives, namelen, adjlen, z);

	} else {

		z = 1;
	    strcat(project_name,"englishProjectName.txt");
	    namelen = vocable_number(names);
	    adjlen = vocable_number(adjectives);
	    random_name_producer(number, project_name, names, adjectives, namelen, adjlen, z);
	}
	
}

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

