//4.13 - write a recursive reverse(s) function.

#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void reverser(char s[]);

int main()
{	
	char test[] = {'!','d','l','r','o','w',' ','o','l','l','e','h','\0'};
	char test2[] = {'!','d','l','r','o','w',' ','o','l','l','e','h','\0'};
	reverse(test);
	reverser(test2);
	printf("%s\n%s\n", test, test2);
	return 0;
}

//original function
void reverse(char s[])
{
	int c, i, j;
	
	for (i=0, j = strlen(s)-1; i<j; i++, j--)	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

//recursive function
void reverser(char s[])	
{
	static int i=0, n;
	int c = s[i];

	if(c) {
		i++;
		reverser(s);
		s[n-i] = c;
		i--;
	}
	else	{
		n = i;
	}
}
