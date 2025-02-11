//4.11 - change getop() to not need ungetch() using a static local variable.
#include <ctype.h>

int getch(void);

int getop(char s[]) {
    int i, c;
	static char buf = EOF;
	if (buf == EOF || buf = ' ' || buf == '\t')	{
    	while ((s[0] = c = getch()) == ' ' || c == '\t')
			;
    	s[1] = '\0';
	}
	else {
		c = buf;
	}	

    if (!isdigit(c) && c != '.' && c != '-') { // Check for operators, but allow '-' for negative numbers
        return c;
    }

    i = 0;
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') { // It's a negative number
            s[++i] = c;
            while (isdigit(s[++i] = c = getch()));
            if (c == '.') {
                while (isdigit(s[++i] = c = getch()));
            }
            s[i] = '\0';
            if (c != EOF) {
                buf = c;
            }
            return NUMBER;
        } else { // It's a '-' operator
            ungetch(c);
            return '-';
        }
    } else if (isdigit(c) || c == '.') { // Positive number or starting with a dot
        do {
            s[++i] = c;
        } while (isdigit(c = getch()));
        if (c == '.') {
            while (isdigit(s[++i] = c = getch()));
        }
        s[i] = '\0';
        if (c != EOF) {
            buf = c;
        }
        return NUMBER;
    }
    return -1; // Should not reach here, error code if it does
}
