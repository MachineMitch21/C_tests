
#include <bms/database_manager.h>

static int record_callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void db_print_sqlite3_version()
{
    printf("%s\n", sqlite3_libversion());
}

void db_open(sqlite3* db, int* result_code)
{
    *result_code = sqlite3_open("bms.db", &db);

    if (*result_code != SQLITE_OK)
    {
        fprintf(stderr, "Cannot open bms database..\n", sqlite3_errmsg(db));
        return;
    }
    else
    {
        fprintf(stdout, "BMS database opened successfully..\n");
    }
}

void db_close(sqlite3* db)
{
    sqlite3_close(db);
}

void db_create_customer(char** cols_vals, size_t num_elements, int* result_code)
{
    sqlite3* db;
    char* errMsg = NULL;

    *result_code = sqlite3_open("../bms.db", &db);

    if (*result_code != SQLITE_OK)
    {
        fprintf(stderr, "Cannot open bms database..\n", sqlite3_errmsg(db));
        return;
    }
    else
    {
        fprintf(stdout, "BMS database opened successfully..\n");
    }

    if (*result_code == SQLITE_OK)
    {
        char sql_stat[255] = "INSERT INTO customers";

        char columns[255] = "(";
        char values[255] = "VALUES (";

        int i;
        for (i = 0; i < num_elements; i+=2)
        {
            strcat(columns, cols_vals[i]);
            strcat(values, cols_vals[i + 1]);

            printf("%d\n", i);
            printf("%s\n", columns);
            printf("%s\n", values);

            if (i != (num_elements - 2))
            {
                strcat(columns, ", ");
                strcat(values, ", ");
            }
        }

        strcat(columns, ") ");
        strcat(values, ");");

        strcat(sql_stat, columns);
        strcat(sql_stat, values);

        printf("%s\n", sql_stat);

        *result_code = sqlite3_exec(db, sql_stat, record_callback, 0, &errMsg);

        if (*result_code != SQLITE_OK)
        {
            fprintf(stderr, "SQL error: %s\n", errMsg);
            sqlite3_free(errMsg);
        }
    }

    sqlite3_close(db);
}

void db_alter_customer(int customer_id, char** cols_vals, size_t num_changes, int* result_code)
{
    int i;
    for (i = 0; i < num_changes * 2; i+=2)
    {
        printf("%s, %s\n", cols_vals[i], cols_vals[i+1]);
    }
}

void    db_delete_customer(int customer_id, int* result_code)
{

}

void    db_create_account(int customer_id, char** cols_vals, size_t num_columns, int* result_code)
{

}

void    db_alter_account(int customer_id, char** cols_vals, size_t num_changes, int* result_code)
{

}

void    db_delete_account(int customer_id, int account_number, int* result_code)
{

}

void    db_create_profile(int customer_id, char* uName, char* pWord, int* result_code)
{

}

void    db_alter_profile(int customer_id, char** cols_vals, int* result_code)
{

}

float   db_query_balance(int customer_id, int account_number, int* result_code)
{

}
