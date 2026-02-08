/* Task 3: assertions and conditional debugging statements */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int* get_values(int argc, char* argv[])
{
    int* values = NULL;

    if (argc > 1) {
        values = calloc(argc - 1, sizeof(int));
        for (int i = 0; i < argc - 1; ++i) {
            values[i] = atoi(argv[i + 1]);
        }    
    }

    return values;
}

long sum_values(int data[], int n)
{
    assert(data != NULL);
    assert(n > 0);

    long result = 0L;

    for (int i = 0; i < n; ++i) {
        result += data[i];
    }

    return result;
}

int main(int argc, char* argv[])
{
    int* data = NULL;
    int num_values = 0;

    data = get_values(argc, argv);
    num_values = argc - 1;

    #ifdef VERBOSE
    printf("Data storage: %p\n", data);
    printf("Number of values: %d\n", num_values);
    #endif

    long sum = sum_values(data, num_values);

    #ifdef VERBOSE
    printf("Returned from sum_values()\n");
    #endif

    free(data);

    #ifdef VERBOSE
    printf("Freed allocated storage\n");
    #endif

    printf("Sum of values = %ld\n", sum);

    return 0;
}
