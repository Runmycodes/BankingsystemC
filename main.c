#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int var;
typedef double vad;

void check(vad balance)
{
    printf("\nYour current balance is: %.4lf", balance);
}
double deposit(vad balance)
{
    printf("\nHow much would you like to deposit?\n");
    vad amount;
    scanf("%lf", &amount);

    while(amount < 0.0){
        printf("Such a value cannot be deposited to your account. Please enter again:\n");
        scanf("%lf", &amount);
    }

    printf("Your new balance is: %.4lf", amount+balance);

    return amount + balance;
}
double withdraw(vad balance)
{
    vad amount;
    if(balance == 0.0){
        printf("\nSorry, You cannot withdraw with 0 balance!\n");
        return balance;
    }
    else{
        printf("\nHow much do you want to withdraw?\n");
        scanf("%lf", &amount);
        while(amount > balance || amount < 0.0){
            printf("Such an amount cannot be withdrawn! Please enter again:\n");
            scanf("%lf", &amount);
        }
        printf("Your new amount is: %.4lf", balance - amount);
        return balance - amount;
    }
}
double fdr(vad balance)
{
    vad amount;
    if(balance == 0.0){
        printf("Sorry, You cannot deposit to fdr with 0 balance!\n");
        return balance;
    }
    else if(balance > 0){
        printf("\nHow much do you want to deposit to your fdr?\n");
        scanf("%lf", &amount);
        while(amount < 0.0 || amount > balance){
            printf("Such a value cannot be deposited to your fdr. Please enter again:\n");
            scanf("%lf", &amount);
        }
        printf("%.4lf has been added to your fdr!\n", amount);
        return amount;
    }
}

int main()
{
    printf("WELCOME TO ESHIN'S BIG BANK!\n");
    printf("We offer an interest rate of 8.9 on fixed deposits, every 3 months.");

    vad balance = 0.0;
    vad fixeddepo = 0.0;

    while(true){
        printf("\n\nWhat do you wish to do?\n");
        printf("1. Check balance\n2. Deposit cash\n3. Withdraw cash\n4. Add to FDR from bank account\n5. View FDR status\n6. Exit\n\n");
        var choice;
        scanf("%d", &choice);

        while(choice > 6 || choice < 1){
            printf("Your input isn't from 1-6! Choose again!\n");
            scanf("%d", &choice);
        }

        if(choice == 1){
            check(balance);
        }
        else if(choice == 2){
            balance = deposit(balance);
        }
        else if(choice == 3){
            balance = withdraw(balance);
        }
        else if(choice == 4){
            fixeddepo += fdr(balance);
            balance -= fixeddepo;
        }
        else if(choice == 5){
            printf("\nCurrently you have %.4lf in your fdr!\n", fixeddepo);
        }
        else if(choice == 6){
            printf("Take care! Make sure to return again, we can't wait for your money!\n");
            break;
        }
    }
    return 0;
}
