#include <stdio.h>
#include <string.h>


/* romanDigit converts single roman digi1t to decimal numeral */
int romanDigit(char digit)
{
	switch (digit)
	{
		case 'M':
			return 1000;
		case 'D':
			return 500;
		case 'C':
			return 100;
		case 'L':
			return 50;
		case 'X':
			return 10;
		case 'V':
			return 5;
		case 'I':
			return 1;
	}
	return 0;
}


/* romanToInt converts a roman numeral repr. as string to integer. */
int romanToInt(char * s)
{	
	int length;
	int sum = 0;

	printf("%s\n", s);
	length = strlen(s);
	for (int i = 0; i < length; i++)
	{
		if (romanDigit(s[i]) >= romanDigit(s[i+1]))
		{
			sum += romanDigit(s[i]);
			
		}
		else
		{	sum += romanDigit(s[i+1]) - romanDigit(s[i]);
			i++;
		}  
	}
	return sum;
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

