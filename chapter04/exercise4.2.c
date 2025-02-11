//4.2 - extend atof to handle sci notation (e E, and a optionally signed exponent)
//
//needs to be built with -lm flag to compile with math.h.. why? idk
//cc exercise4.2.c -o exercise4.2 -lm
#include <stdio.h>
#include <ctype.h>	//for isspace(), isdigit()
#include <math.h>  // for pow()

double atof(char s[])
{
    double val, power;
    int i , sign;
	int ex, exsign;

    for (i=0; isspace(s[i]); i++){
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		exsign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-') {
			i++;
		}
		for (ex = 0; isdigit(s[i]); i++) {
			ex = 10 * ex + (s[i] -'0');
		}
		return sign * val / power * pow(10.0, exsign * ex);
	} else {
    return sign * val / power;
	}
}

//test
int main() 
{
  char s1[] = "  -123.45456e2  ";
  char s2[] = "1.2345E-3";
  char s3[] = "123213";
  printf("\"%s\" = %f\n", s1, atof(s1));
  printf("\"%s\" = %f\n", s2, atof(s2));
  printf("\"%s\" = %f\n", s3, atof(s3));
  return 0;
}
