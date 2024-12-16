#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    errno = 0;
    printf("Number of argument: %d\n", argc);
    if (argc != 2)
    {
        errno = EINVAL;
        perror("Invalid number of arguments!");
    }
    else
    {
        printf("Your file name is '%s' and your word to search was '%s'", argv[0], argv[1]);
    }
    return 0;
}