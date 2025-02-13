//4.14 - make macro swap(t,x,y) to swap x, y vars of type t.
//		 nb; no type checking in macro as type is implied.

#include <stdio.h>
#define swap(t,x,y) {t z; z = x, x = y, y = z;}

int main () 
{
    // Test cases for swap macro with integers
    printf("Testing swap macro with integers:\n");
    int a = 10, b = 20;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("After swap: a = %d, b = %d\n", a, b);

    // Test cases for swap macro with floats
    printf("\nTesting swap macro with floats:\n");
    float c = 3.14, d = 2.71;
    printf("Before swap: c = %f, d = %f\n", c, d);
    swap(float, c, d);
    printf("After swap: c = %f, d = %f\n", c, d);

    // Test cases for swap macro with characters
    printf("\nTesting swap macro with characters:\n");
    char e = 'A', f = 'B';
    printf("Before swap: e = %c, f = %c\n", e, f);
    swap(char, e, f);
    printf("After swap: e = %c, f = %c\n", e, f);
	
	return 0;
}
