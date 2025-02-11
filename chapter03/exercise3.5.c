#include <stdio.h>
#include <string.h> // Include for strlen

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    int x = 3950, y = 16;	//input n = 3950, b = 16, output expected = "F6E"
    char s[12];
    itob(x, s, y);
    printf("INPUT: %d, %d \nOUTPUT: \"%s\"\n", x, y, s);
    return 0;
}

void itob(int n, char s[], int b) {
    int i = 0;
    int r;

    do {
        r = n % b;
        if (r < 10) {
            s[i++] = r + '0';
        } else {
            s[i++] = r - 10 + 'A'; // Handle hex characters
        }
    } while ((n /= b) > 0);
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) { // Corrected loop
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
