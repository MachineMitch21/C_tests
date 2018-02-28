
#ifndef __DATABASE_MANAGER_H__
#define __DATABASE_MANAGER_H__

#include <sqlite3/sqlite3.h>
#include <stdio.h>

void db_print_sqlite3_version();

void db_create_customer(const char* name, const char* phone_number, const char* Address);

void db_alter_customer(int customer_id, char** cols_vals, size_t num_changes, int* result_code);


#endif // __DATABASE_MANAGER_H__
