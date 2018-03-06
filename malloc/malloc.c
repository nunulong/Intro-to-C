#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/
char *string_dup(char *src)
{
    char *dup_src;
    char *dup_index;
    int length = string_length(src);
    dup_src = malloc((length + 1) * sizeof(char));
    if (dup_src == NULL)
    {
        return ((char *)NULL);
    }
    dup_index = dup_src;
    while (*src)
    {
        *dup_index = *src;
        dup_index++;
        src++;
    }
    *dup_index = '\0';
    return dup_src;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    You may want to cast the input pointers to char pointers first before
    performing the copying. 
*/
void *mem_copy(void *dest, const void *src, int n)
{
    char *d = (char *)dest;
    char *s = (char *)src;
    for (int i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));

    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", target[i]);
    }

    printf("\n");

    return 0;
}
#endif