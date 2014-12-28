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
