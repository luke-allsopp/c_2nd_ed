//4.1 - write the function strrindex(s,t), which returns the position of the rightmost occurence of r is or -1 is there is none.
#include <string.h>

/* strrindex: return  rightmost index of t in s, -1 if none
 * using sting.h to get t string length to iterate backwards */
int strrindex(char s[], char t[])
{
    int i, j, k;
	int tl = strlen(t);

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=tl-1; k>=0 && s[j]==t[k]; j++, k--)
            ;
        if (k == -1)
            return i;		//if it gets here, all of t matched?
    }
    return -1;
}


/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
