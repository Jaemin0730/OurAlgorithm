#include<stdio.h>

void BitPrint(char i) {
    for (int j = 7; j >= 0; j--)
    {
        printf("%d", (i >> j) & 1);
    }
}

int main(void) {
    char i;

    for (i = -5; i < 6; i++)
    {
        printf("%3d = ", i);
        BitPrint(i);
        printf("\n");
    }
}