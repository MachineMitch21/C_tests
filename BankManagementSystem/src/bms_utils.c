
#include <bms/bms_utils.h>

char* bms_itos(int i)
{
    int len = snprintf(NULL, 0, "%d", i);
    char* str = malloc(sizeof(char) * (len + 1));

    snprintf(str, len + 1, "%d", i);

    return str;
}
