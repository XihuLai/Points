#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    struct stat buf;
    int r = stat(argv[1], &buf);

    if ( r == 0) {
        unsigned long sz = (buf.st_size >> 20);
        printf("size of %s = %ldMB\n", argv[1], sz);
    } else {
        printf("get size of %s failed\n", argv[1]);
    }

    return 0;
}
