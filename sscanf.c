

/*
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

			  char ime[20];
			  char prezime[20];
			  char broj[20];

			 if(sscanf(line, "%[^|]|%[^|]|%[^\n]", ime, prezime, broj) == 3)
			 {
			  printf("%d) Ime: %s, Prezime: %s, Broj_telefona: %s\n\n", brojac, ime, prezime, broj);

			 }
		  }

}

*/
