#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct bankAccount
{
    char name [100];
    int accountNumber;
    int branchSortCode;
    float balance;
} BankAccount;

BankAccount assignData(int,int,float,char *);
void printAccountInfo(BankAccount);
void checkOverdrawn(BankAccount *,int);

int main(void)
{
    BankAccount accountArray[5];
    int noOfAccounts = 5;
    accountArray[0] = assignData(12461167,110291,-50.00,"Louis Bishop");
    accountArray[1] = assignData(12461168,110291,60.00,"Jack Jacobsen");
    accountArray[2] = assignData(12461169,110291,70.00,"Evan Maduri");
    accountArray[3] = assignData(12461170,110291,80.00,"Luca McAtarsney");
    accountArray[4] = assignData(12461171,110291,90.00,"George Hester");

    printAccountInfo(accountArray[0]);
    printAccountInfo(accountArray[1]);
    printAccountInfo(accountArray[2]);
    printAccountInfo(accountArray[3]);
    printAccountInfo(accountArray[4]);
    checkOverdrawn(accountArray,noOfAccounts);
}

BankAccount assignData(int accountNumber, int branchSortCode, float balance, char name[100])
{
    BankAccount bankAccount;
    bankAccount.accountNumber = accountNumber;
    bankAccount.branchSortCode = branchSortCode;
    bankAccount.balance = balance;
    strncpy(bankAccount.name, name, 100);
    return bankAccount;
}

void printAccountInfo(BankAccount accountToPrint)
{
    printf("Account Holder Name: %s\n", accountToPrint.name);
    printf("Account Number: %d\n", accountToPrint.accountNumber);
    printf("Branch Sort Code: %d\n", accountToPrint.branchSortCode);
    printf("Balance: %.2f\n", accountToPrint.balance);
}

void checkOverdrawn(BankAccount *accountArray, int numberOfAccounts)
{
    printf("Checking for overdrawn accounts...\n");
    int i;
    for(i = 0; i < numberOfAccounts; i++)
    {
        if(accountArray[i].balance < 0)
        {
            printf("Account number %d is overdrawn. Balance: %.2f\n", accountArray[i].accountNumber, accountArray[i].balance);
        }
    }
}