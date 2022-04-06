#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define MAX(a, b) ((a) > (b) ? (a) : (b))


char * substr(char * s, int start, int end)
{	
	char* result;
	result = (char*) malloc(end - start + 1);
	
	for (int i = start; i <= end; i++)
	{
		result[i - start] = s[i];
	}
	result[end + 1] = '\0';
	
	return result;
	
}

int expandFromCenter(char * s, int left, int right)
{
	int L = left;
	int R = right;
	int length = strlen(s);	/* dont care */
	while (L >= 0 && R < length && s[L] == s[R])
	{
		L--;
		R++;
	}
	return R - L - 1;		
}

/* longestPalindrome: expand from center, slow */
char * longestPalindrome(char * s)
{
	int start = 0;
	int end = 0;
	int length = strlen(s);
	
	for (int i = 0; i < length; i++)
	{
		int len1 = expandFromCenter(s, i, i);		/* center on char */
		int len2 = expandFromCenter(s, i, i + 1);	/* center inbetween */
		int len = MAX(len1, len2);
		if (len > end - start)
		{
			start = i - (len - 1) / 2;
			end = i + len / 2;	
		}
	}
	return substr(s, start, end);
}


int main(void)
{	
	char buf[1001];
	while (fscanf(stdin, "%1000s", buf) != EOF)
	{
		printf("%s\n", buf);
		printf("%s\n", longestPalindrome(buf));	
	}
	return 0;
}

