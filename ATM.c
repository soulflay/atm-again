#include <stdio.h>

int balance = 10000;
int another_transaction;

void Title(){
printf("KREEDO MICROFINANCE BANK\n");
printf("**** ATM Machine ****\n");
printf("**************************************\n*************************************\n\n");
printf("WELCOME TO KMB");
}

void language(){
    int lang_choice;
    printf("\nEnter your prefered language: \n");
    printf("1. English  2. Yoruba  \n\n3. Igbo\t  4. Hausa\n> ");
    scanf("%d", &lang_choice);
    if (lang_choice != 1){
        printf("This language is not yet available");
        printf("\nPlease bear with us, English would automatically be selected for you");
    
    }
}

  
void Transaction(){
    int pin = 1234;
    int tmppin;
    printf("\nEnter your Pin:-> ");
    scanf("%d", &tmppin);
    if (pin != tmppin){
    printf("\nInvalid Pin");
    printf("\n:\nPress 1 to proceed..., Press 2 to exit.\n\n");
    scanf("%d", &another_transaction);

            if (another_transaction == 1){
                Transaction();
            }
            else if(another_transaction == 2){
                printf("Thank you for Banking with us, You may take your card");
            }
            else{
                printf("Invalid input");
            }
        }
    

    int choice;

    printf("What transaction would you like to perform");
    printf("\n1:- Withdrawals\n");
    printf("\n2:- Deposit\n");
    printf("\n3:- Balance\n");
    printf("\n4:- Cash transfer\n> ");
    scanf("%d" ,&choice);

    switch (choice){
        case 1:
        int amt_towithdraw;
        int svs_curr;
        printf("\n1.Savings \n2.Current\n> ");
        scanf("%d", &svs_curr);
        if (svs_curr != 1 && svs_curr != 2){
            printf("Invalid option");
            Transaction();
        }
        printf("how much do you wish to withdraw\nEnter amount:- NGN ");
        scanf("%d", &amt_towithdraw);

        if (amt_towithdraw > balance){
            printf("\nInsufficient Funds...\n\n\n***********************\n***********************\n");
            printf("\n\nWould you like to perform another transaction? ");
            printf("\nPress 1 to proceed..., Press 2 to exit.\n> ");
            scanf("%d", &another_transaction);

            if (another_transaction == 1){
                Transaction();
            }
            else if(another_transaction == 2){
                printf("Thank you for Banking with us, You may take your card");
            }
            else{
                printf("Invalid input");
            }
        }
        else {
            //this means there's something in the account
            //so withdraw and update the balance variable
            balance = balance - amt_towithdraw;
            printf("\n........................................................");
            printf("\n........................................................");
            printf("\nYou have withdrawn NGN%d from your available balance\nTake your cash\n\nyour Current balance is NGN%d\nWould you like to perform another transaction:" ,amt_towithdraw, balance);
            printf("\nPress 1 to proceed..., Press 2 to exit.\n\n");
            scanf("%d", &another_transaction);

            if (another_transaction == 1){
                Transaction();
            }
            else if(another_transaction == 2){
                printf("Thank you for Banking with us, You may take your card");
            }
            else{
                printf("Invalid input");
            }
            

        }

        break;

        case 2:
        //deposit
        
        int amt_toDeposit; 
        printf("\n1.Savings \n2.Current\n> ");
        scanf("%d", &svs_curr);
        if (svs_curr != 1 && svs_curr != 2){
            printf("Invalid option");
            Transaction();
        }
        printf("Please enter amount to deposit: NGN"); 
        scanf("%d", &amt_toDeposit); 
        // now that you have deposited something, update the balance variable
        
        balance =amt_toDeposit + balance; 
        
        printf("\nThank you for depositing, New balance: NGN%d\n\n", balance); 
        printf("\nWould you like to perform another transaction:\nPress 1 to proceed..., Press 2 to exit.\n");
        scanf("%d", &another_transaction);

            if (another_transaction == 1){
                Transaction();
            }
            else if(another_transaction == 2){
                printf("\n\nThank you for Banking with us, You may take your card");
            }
            else{
                printf("\n\nInvalid input");
            }
            
        break;

        case 3:
        //to check balance
        printf("Your Balance: NGN%d\n\n", balance);
        printf("\nWould you like to perform another transaction:\nPress 1 to proceed..., Press 2 to exit.\n\n");
        scanf("%d", &another_transaction);

            if (another_transaction == 1){
                Transaction();
            }
            else if(another_transaction == 2){
                printf("Thank you for Banking with us, You may take your card");
            }
            else{
                printf("Invalid input");
            }
        break;
        
        case 4:
        //cash transfer
        int bank_choice, trans_amt; long long receipient;
        printf("\n1.Savings \n2.Current\n> ");
        scanf("%d", &svs_curr);
        if (svs_curr != 1 && svs_curr != 2){
            printf("Invalid option");
            Transaction();
        }
        printf("\nEnter amount:- NGN");
        scanf("%d", &trans_amt);
        printf("Enter receipient's Account number, Surname or Phone number below\n");
        scanf("%lld", &receipient);
        printf("\n%lld belongs to a valid customer", receipient);
        
        printf("\n\nPlease select the bank you wish to transfer into\n");
        printf("1.Zenith Bank\n2.Access Bank Plc\n3.Fidelity Bank\n4.First City Monument Bank(FCMB)\n5.First Bank of Nigeria\n6.Gtbank\n7.Union Bank\n8.sterling Bank\n\n:-> ");
        scanf("%d", &bank_choice);

        
       if (trans_amt > balance){
           printf("\n\nInsufficient balance to perform your transaction");
       }
       else{
           int new_bal;
           new_bal = balance - trans_amt;
           printf("\nYour transfer of NGN %d to %lld was successful!\n\nNew balance:- NGN%d", trans_amt, receipient, new_bal);
       }
        printf("\n\nWould you like to perform another transaction? ");
        printf("\nPress 1 to proceed..., Press 2 to exit.\n> ");
        scanf("%d", &another_transaction);
        if (another_transaction == 1){
            Transaction();
        }
        else if(another_transaction == 2){
            printf("Thank you for Banking with us, You may take your card");
        }
        else{
            printf("Invalid input");
        }

        break;
    }
}




 int main(){
     Title();
     language();
     Transaction();
}

