
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printbincharpad(char c)
{
    for (int i = 7; i >= 0; --i)
    {
        putchar( (c & (1 << i)) ? '1' : '0' );
    }
    putchar('\n');
}

int main(int argc, char** argv)
{
    int number = 255;
    char c = 'a';

    printf("We are manipulating the number (%d) and the character (%c) with bitwise operations..\n\n", number, c);

    int ia_result = number & 128;
    char ca_result = c & 'b';

    printf("The & operator takes the logical AND of each bit of each input (outputting 1 if both bits in the same position of the inputs are 1)\n");
    printf("    Ex. 10011100\n");
    printf("        11100111\n");
    printf("        10000100\n");
    printf("%c & b = %c\n", c, ca_result);
    printf("%d & 128 = %d\n\n", number, ia_result);

    int io_result = number | 128;
    char co_result = c | 'b';

    printf("The | operator takes each bit of both inputs and compares to see if either of the bits is a 1 at each position, outputting a 1 to the new bit\n");
    printf("    Ex. 11011011\n");
    printf("        01101010\n");
    printf("        11111011\n");
    printf("%c | b = %c\n", c, co_result);
    printf("%d | 128 = %d\n\n", number, io_result);

    int ixor_result = number ^ 128;
    char cxor_result = c ^ 'b';

    printf("%c ^ b = %c\n", c, cxor_result);
    printf("%d ^ 128 = %d\n", number, ixor_result);

    char cshl_result = c << 2;
    int ishl_result = number << 2;

    printf("%c << 2 = %c\n", c, cshl_result);
    printf("%d << 2 = %d\n\n", number, ishl_result);

    char cshr_result = c >> 2;
    int ishr_result = number >> 2;

    printf("%c >> 2 = %c\n", c, cshr_result);
    printf("%d >> 2 = %d\n\n", number, ishr_result);

    char val1 = 'a';

    printbincharpad(val1);
    printbincharpad(~val1);

    for (int i = 0; i < 8; i++)
    {
        val1 = val1 ^ (1 << i);
    }

    printf("%c\n", val1);

    printbincharpad(val1);

    return 0;
}
