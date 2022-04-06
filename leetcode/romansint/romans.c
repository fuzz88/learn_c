#include <stdio.h>
#include <string.h>


/* romanDigit converts single roman digit to decimal numeral */
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
	for (int i = length - 1; i != -1; i--)
	{	
		sum += romanDigit(s[i]);
		if (i - 1 > 0)
		{
			switch (s[i]) 
			{
				case 'M':
					switch (s[i-1])
					{
						case 'C':
							sum -= romanDigit('C');
							i -= 1;
							break;
					}
				case 'D':
					switch (s[i-1])
					{
						case 'C':
							sum -= romanDigit('C');
							i -= 1;
							break;
					}
				case 'C':
					switch (s[i-1])
					{
						case 'X':
							sum -= romanDigit('X');
							i -= 1;
							break;
					}
				case 'L':
					switch (s[i-1])
					{
						case 'X':
							sum -= romanDigit('X');
							i -= 1;
							break;
					}
				case 'X':
					switch (s[i-1])
					{
						case 'I':
							sum -= romanDigit('I');
							i -= 1;
							break;
					}
				case 'V':
					switch (s[i-1])
					{
						case 'I':
							sum -= romanDigit('I');
							i -= 1;
							break;
					}
				}
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

