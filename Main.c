#include <stdio.h>
#include <string.h>

typedef struct
{
	char ime[20];
	char prezime[20];
	char broj[20];

}TKontakt;

TKontakt niz[10];

int brojac = 0;

void add( int* brojac, char* ime, char* prezime, char* broj, TKontakt* niz)
{
	strcpy(niz[*brojac].ime, ime);
	strcpy(niz[*brojac].prezime, prezime);
	strcpy(niz[*brojac].broj, broj);

   (*brojac)++;

}

void printALL(TKontakt* niz, int size)
{
	int i = 0;
	do
	{
		printf("%d) Ime: %s, Prezime: %s, Broj: %s\n\n", i + 1, niz[i].ime, niz[i].prezime, niz[i].broj);

		i++;
		fflush(stdout);
	}
	while(i < size);
}

void ucitaj_Format_Imenika(const char* filename)
{
	FILE *file;

		char line[100];

		file = fopen("Format_Imenika.txt", "r");

		  while (fgets(line, sizeof(line), file))
		  {
			  char* ime = strtok(line, "|");
			  char* prezime = strtok(NULL, "|");
			  char* broj = strtok(NULL, "\n");

			  add(&brojac, ime, prezime, broj, niz);
		  }

		   fclose(file);
}

int main()
{
	const char* filename = "Format_Imenika.txt";

	int opcija;

	printf("Izaberite opciju:\n\n");

	printf("1) Ucitavanje Imenika iz fajla!\n\n");
	printf("2) Dodavanje novog kontakta!\n\n");
	printf("3) Ispisi Imenik!\n\n");
	printf("0) Ugasi program!\n\n");
	fflush(stdout);

while(1)
{
	scanf("%d", &opcija);
	fflush(stdout);

		switch(opcija)
		{
		case 1:
		{
			ucitaj_Format_Imenika(filename);
		}
		break;

		case 2:
		{
			printf("Nije jos podrzano!\n");
			fflush(stdout);
		}
		break;

		case 3:
		{
			printALL(niz, brojac);
		}
		break;

    default:

	   switch(opcija)
	    {
		case 0:
		{
			printf("Nije jos podrzano!\n");
			fflush(stdout);
		}
		break;

    default:
		{
			printf("Uneli ste pogresan broj! Molim Vas koristite brojeve u rasponu od 0 - 3!");
			fflush(stdout);
		}
		break;
		}
	   break;
		}
}
}
















