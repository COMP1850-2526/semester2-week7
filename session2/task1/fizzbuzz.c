/* A classic mathematical game for children */

#include <stdio.h>

int main(void)
{
    int fizz = 0;
    int buzz = 0;
    int fizz_buzz = 0;

    for (int i = 1; i <= 100; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
            ++fizz_buzz;
        }
        else if (i % 3 == 0) {
            ++fizz;
        }
        else if (i % 5 == 0) {
            ++buzz;
        }
    }

    printf("Fizzes: %d\n", fizz);
    printf("Buzzes: %d\n", buzz);
    printf("Fizz Buzzes: %d\n", fizz_buzz);

    return 0;
}
