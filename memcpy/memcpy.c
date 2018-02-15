#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A test using memcpy for a struct

typedef struct {
    double  _randomThing;
    int     _number;
    char*   _name;
} data_struct;

data_struct* createDataStruct(double d, int i, const char* c)
{
    data_struct* ds = malloc(sizeof(data_struct));
    ds->_randomThing = d;
    ds->_number = i;
    ds->_name = c;
    return ds;
}

void freeDataStruct(data_struct* ds)
{
    free(ds);
}

data_struct* data_structCopy(data_struct* ds)
{
    data_struct* copy = NULL;
    memcpy(&copy, &ds, sizeof(ds));
    return copy;
}

int main(int argc, char** argv)
{
    data_struct* ds1 = createDataStruct(2.2, 2, "Things");

    data_struct* ds2 = data_structCopy(ds1);

    ds1->_name = "Stuff";
    ds2->_number = 5;

    printf("DS1 data is: %s, %d, %f\n", ds1->_name, ds1->_number, ds1->_randomThing);
    printf("DS2 data is: %s, %d, %f\n", ds2->_name, ds2->_number, ds2->_randomThing);

    freeDataStruct(ds1);
    freeDataStruct(ds2);
    return 0;
}
