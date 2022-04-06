#include <stdio.h>
#include <string.h>

/* romanToInt converts a roman numeral repr. as string to integer. */
int romanToInt(char * s)
{	
	int length;
	printf("%s\n", s);
	length = strlen(s);
	return length;
}

int main(void)
{	
	char buf[100];
	while (fscanf(stdin, "%99s", buf) != EOF)
	{
		printf("%i\n", romanToInt(buf));	
	}
	return 0;
}

