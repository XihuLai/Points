/* strtok example */
#include <stdio.h>

#define NELEMS(x) ((sizeof (x))/(sizeof ((x)[0])))

template <int N, typename T>
static int sizeof_array( T (&arr)[N] )
{
    return N;
}

char *ss[] = {
    "c",
    "c++",
    "java",
    "lua",
};

int main ()
{
    printf("nums = %lu\n", NELEMS(ss));
    printf("nums = %d\n", sizeof_array(ss));
    return 0;
}
