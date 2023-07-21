#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define Exit           0
#define Read_Contacts  1
#define Add_Contacts   2
#define Print_Contacts 3

typedef struct
{
	char ime[20];
	char prezime[20];
	char broj[20];

}TKontakt;

TKontakt niz[20];

int brojac = 0;

int add( int* brojac, char* ime, char* prezime, char* broj, TKontakt* niz)
{
	strcpy(niz[*brojac].ime, ime);
	strcpy(niz[*brojac].prezime, prezime);
	strcpy(niz[*brojac].broj, broj);

   (*brojac)++;

   return 1;
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

void stop_program()
{
	printf("Program je prekinut, pocinjemo ponovo!\n");
	fflush(stdout);
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void add_Contacts()
{
	char ime[20], prezime[20], broj[20];

	printf("Unesite ime novog korisnika: ");
	fflush(stdout);
	scanf("%s",ime);
	printf("Unesite prezime novog korisnika: ");
	fflush(stdout);
	scanf("%s",prezime);
	printf("Unesite broj novog korisnika: ");
	fflush(stdout);
	scanf("%s",broj);

	if (add(&brojac, ime, prezime, broj, niz))
	    {
	        printf("Kontakt uspešno dodat!\n");
	    }
	    else
	    {
	        printf("Dodavanje kontakta nije uspelo!\n");
	    }
}

int main()
{
	const char* filename = "Format_Imenika.txt";

	int opcija;

	printf("Izaberite opciju:\n\n");

	printf("0) Ugasi program!\n\n");
	printf("1) Ucitavanje Imenika iz fajla!\n\n");
	printf("2) Dodavanje novog kontakta!\n\n");
	printf("3) Ispisi Imenik!\n\n");
	fflush(stdout);

while(1)
{
	scanf("%d", &opcija);

	switch(opcija)
{
		case Exit:
		{
			stop_program();
		}
		break;

		case Read_Contacts:
		{
			ucitaj_Format_Imenika(filename);
		}
		break;

		case Add_Contacts:
		{
			add_Contacts();
		}
		break;

		case Print_Contacts:
		{
			printALL(niz, brojac);
		}
		break;

    default:
		{
			printf("Uneli ste pogresan broj! Molim Vas koristite brojeve u rasponu od 0 - 3!");
			fflush(stdout);
		}
		break;
	}

  }
}

















