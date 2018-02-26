
#include <bms/account.h>
#include <bms/list.h>
#include <string.h>

#define MAX_NAME_SIZE 64
#define MAX_ADDRESS_SIZE 256

typedef struct Customer_s Customer;

Customer*   customer_new();
void        customer_free(Customer* customer);

int         customer_setName(Customer* customer, char* name);
void        customer_setPhoneNumber(Customer* customer, long phone);
int         customer_setAddress(Customer* customer, char* address);
char*       customer_getName(Customer* customer);
long        customer_getPhoneNumber(Customer* customer);
char*       customer_getAddress(Customer* customer);
void        customer_addAccount(Customer* customer, Account* account);
void        customer_removeAccount(Customer* customer, Account* account);
