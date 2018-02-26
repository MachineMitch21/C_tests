#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024


char* using_fread(FILE* file_p)
{
    size_t size;

    if (file_p != NULL)
    {
        fseek(file_p, 0, SEEK_END);
        size = ftell(file_p);
        fseek(file_p, 0, SEEK_SET);

        char* buffer = (char*) malloc(sizeof(char) * (size));

        fread(buffer, 1, size, file_p);

        printf("\n\n%d\n%d\n\n", size, strlen(buffer));


        return buffer;
    }

    return NULL;
}


int main(int argc, char** argv)
{
    FILE* file_p = fopen(argv[1], "r");
    FILE* file_p2 = fopen(argv[2], "r");

    char* data = using_fread(file_p);
    char* data2 = using_fread(file_p2);

    printf("%s\n", data);
    printf("\n%s\n", data2);

    free(data);
    free(data2);
    fclose(file_p);
    fclose(file_p2);
    return 0;
}
