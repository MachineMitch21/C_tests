
#include <bms/database_manager.h>

static int record_callback(void *NotUsed, int argc, char **argv, char **azColName)
{
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

char* construct_insert_sql_stmt(char* table_name, char** cols_vals, size_t num_elements, size_t sql_stmt_size)
{
    char* sql_stmt = malloc(sizeof(char) * (sql_stmt_size != NULL ? sql_stmt_size : 255));

    char table[64];

    strcpy(table, table_name);

    strcpy(sql_stmt, "INSERT INTO ");

    strcat(sql_stmt, table);

    char columns[255] = "(";
    char values[255] = "VALUES (";

    int i;
    for (i = 0; i < num_elements; i+=2)
    {
        strcat(columns, cols_vals[i]);
        strcat(values, cols_vals[i + 1]);

        if (i != (num_elements - 2))
        {
            strcat(columns, ", ");
            strcat(values, ", ");
        }
    }

    strcat(columns, ") ");
    strcat(values, ");");

    strcat(sql_stmt, columns);
    strcat(sql_stmt, values);

    return sql_stmt;
}

char* construct_update_sql_stmt(char* table_name, char** set_col_val, char** where_cols_cond_vals, size_t num_elements, size_t sql_stmt_size)
{
    char* sql_stmt = malloc(sizeof(char) * (sql_stmt_size != NULL ? sql_stmt_size : 255));

    char table[64];

    strcpy(table, table_name);

    strcpy(sql_stmt, "UPDATE ");

    strcat(sql_stmt, table);

    char setCondition[255] = " SET ";
    char whereCondition[255] = " WHERE ";

    int equ_start_loc = strlen(set_col_val[0]) + strlen(setCondition);

    strcat(setCondition, set_col_val[0]);
    memmove(&setCondition[equ_start_loc], " = ", sizeof(char) * 3);
    strcat(setCondition, set_col_val[1]);

    int i;
    for (i = 0; i < num_elements; i+=3)
    {
        strcat(whereCondition, where_cols_cond_vals[i]);
        strcat(whereCondition, where_cols_cond_vals[i + 1]);
        strcat(whereCondition, where_cols_cond_vals[i + 2]);
    }

    strcat(sql_stmt, setCondition);
    strcat(sql_stmt, whereCondition);
    strcat(sql_stmt, ";");

    return sql_stmt;
}

char* construct_delete_sql_stmt(char* table_name, char** where_cols_cond_vals, size_t num_elements, size_t sql_stmt_size)
{
    char* sql_stmt = malloc(sizeof(char) * (sql_stmt_size != NULL ? sql_stmt_size : 255));

    strcpy(sql_stmt, "DELETE FROM ");

    strcpy(sql_stmt, table_name);

    char whereCondition[255] = " WHERE ";

    int i;
    for(i = 0; i < num_elements; i+=3)
    {
        strcat(sql_stmt, where_cols_cond_vals[i]);
        strcat(sql_stmt, where_cols_cond_vals[i + 1]);
        strcat(sql_stmt, where_cols_cond_vals[i + 2]);
    }

    strcat(sql_stmt, whereCondition);
    strcat(sql_stmt, ";");

    return sql_stmt;
}

void db_create_customer(char** cols_vals, size_t num_elements, int* result_code)
{
    sqlite3* db;
    char* errMsg = NULL;

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

    if (*result_code == SQLITE_OK)
    {
        char* sql_stmt = construct_insert_sql_stmt("customers", cols_vals, num_elements, NULL);

        *result_code = sqlite3_exec(db, sql_stmt, record_callback, 0, &errMsg);

        free(sql_stmt);

        if (*result_code != SQLITE_OK)
        {
            fprintf(stderr, "SQL error: %s\n", errMsg);
            sqlite3_free(errMsg);
        }
    }

    sqlite3_close(db);
}

void db_modify_customer(int customer_id, char** cols_vals, size_t num_elements, int* result_code)
{
    sqlite3* db;
    char* errMsg = NULL;

    char* id_str = bms_itos(customer_id);

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

    if (*result_code == SQLITE_OK)
    {
        char* where_cols_cond_vals[] = {
            "CustomerID",
            " = ",
            id_str
        };

        int i;
        for (i = 0; i < num_elements; i+=2)
        {
            char* set_col_val[] = {
                cols_vals[i],
                cols_vals[i + 1]
            };

            char* sql_stmt = construct_update_sql_stmt("customers", set_col_val, where_cols_cond_vals, 3, NULL);

            *result_code = sqlite3_exec(db, sql_stmt, record_callback, 0, &errMsg);

            free(sql_stmt);
            free(id_str);

            if (*result_code != SQLITE_OK)
            {
                fprintf(stderr, "SQL error: %s\n", errMsg);
                sqlite3_free(errMsg);
            }
        }
    }

    sqlite3_close(db);
}

void    db_delete_customer(int customer_id, int* result_code)
{
    sqlite3* db;
    char* errMsg = NULL;

    char* id_str = bms_itos(customer_id);

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

    char** where_cols_cond_vals[] = {
        "CustomerID",
        "=",
        id_str
    };

    char* sql_stmt = construct_delete_sql_stmt("customers", where_cols_cond_vals, 3, NULL);

    *result_code = sqlite3_exec(db, sql_stmt, record_callback, 0, &errMsg);

    free(sql_stmt);
    free(id_str);

    if (*result_code != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void    db_create_account(int customer_id, char** cols_vals, size_t num_elements, int* result_code)
{

}

void    db_modify_account(int customer_id, char** cols_vals, size_t num_elements, int* result_code)
{

}

void    db_delete_account(int customer_id, int account_number, int* result_code)
{

}

void    db_create_profile(int customer_id, char* uName, char* pWord, int* result_code)
{

}

void    db_modify_profile(int customer_id, char** cols_vals, int* result_code)
{

}

int     db_verify_login(char* uName, char* pWord, int* result_code)
{

}

float   db_query_balance(int customer_id, int account_number, int* result_code)
{

}
