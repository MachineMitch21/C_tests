
#include <stdio.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv)
{

    if (argv[1] == NULL)
    {
        printf("Please enter something to save to file\n\n\n");
    }
    else
    {
        FILE* file_p;

        file_p = fopen("test.txt", "w+");
        fprintf(file_p, argv[1]);
        fclose(file_p);

        char buffer[BUFFER_SIZE];

        file_p = fopen("test.txt", "r");
        while(fgets(buffer, sizeof(buffer), file_p) != NULL)
        {
            printf("%s", buffer);
        }

        if (feof(file_p))
        {
            printf("\n EOF REACHED\n");
        }
        else
        {
            printf("Something else happened");
        }

        fclose(file_p);
    }

    return 0;
}
