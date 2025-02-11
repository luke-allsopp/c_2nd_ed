//exercise 4.5 - add access to library functions like sin, exp and pow using math.h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP	100
#define NUMBER	'0'
#define MAXVAL  100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char []);
void push(double);
double pop(void);
void showTop(void);
void duplicate(void);
void swapItems(void);
void clearStack(void);
int getch(void);
void ungetch(int);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)	{
		switch (type)	{
		case 
		case NUMBER:
			push(atof(s));
			break;
		case IDENTIFIER:
        	dealWithName(s);
        	break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
        case '/':
			op2 = pop();
			if (op2 != 0.0)	{
				push(pop() / op2);
			}
			else
				printf("Error: zero divisor\n");
			break;
		case '%':											// % handling. manually calculated modulus to avoid double <> int casting shit
			op2 = pop();
			if (op2 != 0.0)	{
				double op1 = pop ();
				double result = op1 = (int)(op1 / op2) * op2;
				push(result);
			}
			else {
				printf("Error: zero divisor\n");
			}
			break;
        case '?':
            showTop();
            break;
        case '#':
            duplicate();
            break;
        case '~':
            swapItems();
            break;
        case '!':
            clearStack();
			break;
		case '^':
			break;
		case '':
			break;
		case '':
			break;
        case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("Error: Unknown Command \t%s\n" , s);
			break;
		}
	}
	return 0;
}

void push(double f) 
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t'); 

    s[1] = '\0';

    if (c == EOF)
        return EOF;

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
                ungetch(c); 
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
            ungetch(c);
        }
        return NUMBER;
    }
    return c; // Should not reach here
}

int getch (void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch (int c)
{
	if (bufp >= BUFSIZE)	{
		printf("ungetch: too many characters\n");
	}
	else	{
		buf[bufp++] = c;
	}
}

void showTop(void)
{
	if(sp>0)	{
		printf("Top of stack contents:\t%8g\n", val[sp-1]);
	}else	{
		printf("Stack is empty\n");
	}
}

void duplicate(void)
{
	double temp = pop();
	push(temp);
	push(temp);
}

void swapItems(void)
{
	double item1 = pop();
	double item2 = pop();

	push(item1);
	push(item2);
}

void clearStack(void)
{
	sp=0;
}

void dealWithName(char s[])
{
   double op2;

   if( 0 == strcmp(s, "sin"))
      push(sin(pop()));
   else if( 0 == strcmp(s, "cos"))
      push(cos(pop()));
   else if (0 == strcmp(s, "exp"))
      push(exp(pop()));
   else if(!strcmp(s, "pow"))
   {
      op2 = pop();
      push(pow(pop(), op2));
   }
   else
      printf("%s is not a supported function.\n", s);
}
