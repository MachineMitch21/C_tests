
#include <bms/database_manager.h>

void db_print_sqlite3_version()
{
    printf("%s\n", sqlite3_libversion());
}

void db_alter_customer(int customer_id, char** cols_vals, size_t num_changes, int* result_code)
{
    int i;
    for (i = 0; i < num_changes * 2; i+=2)
    {
        printf("%s, %s\n", cols_vals[i], cols_vals[i+1]);
    }
}
