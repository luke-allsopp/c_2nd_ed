/* Exercise 1-21:
 * Write a program entab that replaces strings of spaces with the minimim number of tabs and blanks to achieve the same spacing. 
 * when either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
 */
#include <stdio.h>

#define TABLEN 5
      
int main()
{
  int c, i = 0, j;
	
  while((c = getchar()) != EOF){
		
    if(c == ' '){
			
      ++i; 									
		
      if((i % TABLEN) == 0) {				
        putchar('\t');
	  }
    }
		
    else{
			
      for(j = 0; j < (i % TABLEN); ++j) {
        putchar(' ');
	  }			
      putchar(c);
			
      if(i != 0) {
        i = 0;
      }	
	}	
  }
}
