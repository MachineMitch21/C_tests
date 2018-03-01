
#ifndef __DATABASE_MANAGER_H__
#define __DATABASE_MANAGER_H__

#include <sqlite3/sqlite3.h>
#include <stdio.h>

void    db_print_sqlite3_version();

void    db_open(sqlite3* db, int* result_code);
void    db_close(sqlite3* db);

void    db_create_customer(char** cols_vals, size_t num_columns, int* result_code);
void    db_alter_customer(int customer_id, char** cols_vals, size_t num_changes, int* result_code);
void    db_delete_customer(int customer_id, int* result_code);
void    db_create_account(int customer_id, char** cols_vals, size_t num_columns, int* result_code);
void    db_alter_account(int customer_id, char** cols_vals, size_t num_changes, int* result_code);
void    db_delete_account(int customer_id, int account_number, int* result_code);
void    db_create_profile(int customer_id, char* uName, char* pWord, int* result_code);
void    db_alter_profile(int customer_id, char** cols_vals, int* result_code);
float   db_query_balance(int customer_id, int account_number, int* result_code);


#endif // __DATABASE_MANAGER_H__
