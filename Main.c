#include <stdio.h>
#include <string.h>


int main()
{
	FILE *file;
	char line[100];

    int brojac = 0;

	file = fopen("Format_Imenika.txt", "r");

	  while (fgets(line, sizeof(line), file))
	  {
		  brojac ++;

		  char* ime = strtok(line, "|");
		  char* prezime = strtok(NULL, "|");
		  char* broj = strtok(NULL, "\n");

	      printf("%d) Ime: %s, Prezime: %s, Broj_telefona: %s\n\n", brojac, ime, prezime, broj);

	  }

	   fclose(file);
}
