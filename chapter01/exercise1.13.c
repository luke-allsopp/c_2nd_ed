#include<stdio.h>

#define IN        1
#define OUT       0
#define MAXLENGTH 11

int main()
{
  int i = 0;
  int j =0;    
  int c = 0;
  int nchar = 0;  
  int inspace = IN;  
  int wordlen[MAXLENGTH]; 

  for(i = 0; i < MAXLENGTH; ++i)
    wordlen[i] = 0;

  while((c = getchar()) != EOF)
    {
      if(c == ' ' || c == '\t' || c == '\n')
	{
	  if (inspace == OUT)
	    {
	      if(nchar < MAXLENGTH)
		++wordlen[nchar];
	    }
	  
	  inspace = IN;
	  nchar = 0;
	}
      else
	{
	  ++nchar;
	  if(c == '"' || c == '\'')
	    --nchar;
	  inspace = OUT;
	}
    }


  for(i = 1; i < MAXLENGTH; ++i)
    {
      printf("%2d| ", i);
      for(j = 0; j < wordlen[i]; ++j)
	putchar('*');

      putchar('\n');
    }

  
  return 0;
}
