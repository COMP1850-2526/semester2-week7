/* Compile & run this program and observe what happens */

#include <stdio.h>

void assign_values(int x[])
{
    for (int i = 0; i < 100; ++i) {
        x[i] = i;
    }
}

int main(void)
{
    int data[10] = { 0 };

    assign_values(data);
    printf("Done!\n");

    return 0;
}
