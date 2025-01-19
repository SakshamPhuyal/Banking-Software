#include <stdio.h>
#include <stdbool.h>

int main() {
    long int amnt = 1000000, tra, top, acc;
    int choice, pw, passwordAttempts = 0;
    long long phn;
    char tr = 'y';
    bool again = true;
    char name[20];
    
    printf("\nWelcome to our Mobile Banking Service !\n");
    printf("\nSaksham's bank gladly welcomes you.\n");
    printf("\nPlease enter your name: ");
    scanf("%s", name);
    printf("Please enter your 4-digit pin: ");
    scanf("%d", &pw);

    if (pw != 0 && pw >= 1000 && pw <= 9999) {
        printf("\t\t\tWelcome to Saksham's Mobile Banking, Mr. %s\n", name);

        while (again) {
            printf("\n1. Balance Check\n");
            printf("2. Mobile Topup\n");
            printf("3. Balance Transfer\n");
            printf("4. Exit\n");
            printf("****************\n\n");
            printf("Please select an option: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("\nThe balance in your account is Rs. %ld.\n", amnt);
                    break;
                
                case 2:
                    printf("Enter your phone number: ");
                    scanf("%lld", &phn);
                    
                    if (phn >= 1000000000 && phn <= 9999999999) {
                        printf("\nInsert the amount you want to top-up: ");
                        scanf("%ld", &top);
                        
                        if (top > (amnt - 500)) {
                            printf("\nYou have insufficient balance!\n");
                        } else {
                            amnt = amnt - top;
                            printf("\nThe balance top-up is successfully completed!\n");
                            printf("The remaining balance is Rs. %ld.\n", amnt);
                        }
                    } else {
                        printf("Invalid Phone number!\n");
                    }
                    break;
                
                case 3:
                    printf("Enter the account number [10-digits]: ");
                    scanf("%ld", &acc);
                    
                    if (acc >= 1000000000 && acc <= 9999999999) {
                        printf("\nEnter the amount to be transferred: ");
                        scanf("%ld", &tra);
                        
                        if (tra > amnt) {
                            printf("Insufficient balance!\n");
                        } else {
                            amnt = amnt - tra;
                            printf("\nThe transaction is successful!\n");
                            printf("Your new balance is Rs. %ld.\n", amnt);
                        }
                    } else {
                        printf("The account number you've entered is incorrect!\n");
                    }
                    break;
                
                case 4:
                    printf("\nThank You!\n");
                    return 0;
                
                default:
                    printf("\nInvalid Option!!\n");
            }

            printf("\nWould you like to perform another transaction (y/n): ");
            scanf(" %c", &tr);
            if (tr == 'n' || tr == 'N') {
                again = false;
                printf("\nThank you! SRS bank is always at your service.\n");
            }
        }
    } else {
        printf("Invalid pin. Exiting...\n");
    }

    return 0;
}
