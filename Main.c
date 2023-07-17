#include <stdio.h>

int main()
{
	FILE *file;
	char line[10];

	file = fopen("Format_Imenika.txt", "r");

	  while (fgets(line, sizeof(line), file))
	  {
	           printf("%s", line);
	  }

	   fclose(file);
}
