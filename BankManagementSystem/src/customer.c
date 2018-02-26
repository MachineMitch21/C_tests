#include <bms/customer.h>

struct Customer_s {
    char*   _name;
    long    _phoneNumber;
    char*   _address;
    List*   _accounts;
};

Customer*  customer_new()
{
    Customer* customer      = (Customer*) malloc(sizeof(Customer));
    customer->_name         = (char*) malloc(sizeof(char) * MAX_NAME_SIZE);
    customer->_address      = (char*) malloc(sizeof(char) * MAX_ADDRESS_SIZE);
    customer->_accounts     = list_new();
    return customer;
}

void  customer_free(Customer* customer)
{
    free(customer->_name);
    free(customer->_address);
    free_list(customer->_accounts);
    free(customer);
}

int  customer_setName(Customer* customer, char* name)
{
    if (strlen(name) > MAX_NAME_SIZE)
    {
        printf("Customer names must not be longer than %d characters\n", MAX_NAME_SIZE);
        return -1;
    }
    else
    {
        strcpy(customer->_name, name);
    }
}

void  customer_setPhoneNumber(Customer* customer, long phone)
{
    customer->_phoneNumber = phone;
}

int  customer_setAddress(Customer* customer, char* address)
{
    if (strlen(address) > MAX_ADDRESS_SIZE)
    {
        printf("Customer addresses must not be longer than %d characters\n", MAX_ADDRESS_SIZE);
        return -1;
    }
    else
    {
        strcpy(customer->_address, address);
    }
}

char*        customer_getName(Customer* customer)
{
    return customer->_name;
}

long         customer_getPhoneNumber(Customer* customer)
{
    return customer->_phoneNumber;
}

char*        customer_getAddress(Customer* customer)
{
    return customer->_address;
}

void  customer_addAccount(Customer* customer, Account* account)
{
    list_push_back(customer->_accounts, (void*)account);

    if (list_last_error(customer->_accounts) == LIST_OKAY)
    {
        printf("New account added successfully for %s\n", customer->_name);
    }
    else
    {
        printf("Account could not be added to %s's accounts\n", customer->_name);
    }
}

void customer_removeAccount(Customer* customer, Account* account)
{
    List* accountList = customer->_accounts;
    int size = list_size(accountList);

    for (int i = 0; i < size; i++)
    {
        Node* node = list_get_element(accountList, i);

        Account* currentAccount = (Account*) node_data(node);
        if (account == currentAccount)
        {
            list_remove_i(accountList, i);
        }
    }
}
