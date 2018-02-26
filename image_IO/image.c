#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int main(int argc, char** argv)
{
    size_t size;

    FILE* file_p = fopen("hoth.jpg", "rb");

    fseek(file_p, 0, SEEK_END);
    size = ftell(file_p);
    fseek(file_p, 0, SEEK_SET);

    char* buffer = (char*) malloc(sizeof(char) * size);

    fread(buffer, sizeof(char), size, file_p);

    memset(&buffer[size], '\0', 1);

    file_p = freopen("hoth.txt", "w", stdout);

    fwrite(buffer, sizeof(char), size, file_p);

    fclose(file_p);
    return 0;
}
