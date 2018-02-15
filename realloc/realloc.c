#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    char* buffer;

    if (!(argc < 2))
    {
        int sizeOfArg = strlen(argv[1]);

        if (buffer == NULL)
        {
            printf("Could not allocate memory for buffer.\n\n");
        }
        else
        {
            char* arg = argv[1];
            strcat(buffer, arg);
            printf(buffer);
        }

        free(buffer);
    }

    return 0;
}
