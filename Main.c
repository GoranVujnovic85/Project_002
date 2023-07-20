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

int main()
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

	   for(int i = 0; i < brojac; i++)
	   {
		   printf("%d) Ime: %s, Prezime: %s, Broj_telefona: %s\n\n", i + 1, niz[i].ime, niz[i].prezime, niz[i].broj);
	   }
}



















