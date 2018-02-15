#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char* str = "255.87";
    printf("No conversion: %s\n", str);

    double str_atof = atof(str);
    printf("atof: %.2f\n", str_atof);

    int str_atoi = atoi(str);
    printf("atoi: %d\n", str_atoi);

    long str_atol = atol(str);
    printf("atol: %d\n", str_atol);

    long long str_atoll = atoll(str);
    printf("atoll: %d\n", str_atoll);
    return 0;
}
