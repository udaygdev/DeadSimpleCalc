/*
This is just a simple calculator used for my own understanding of some principles.
It has little to no safeguards in place, so overflow and wrong type of inputs will cause errors.
I might change it in the near future to account for different types or overflow. Otherwise, this is just for my own understanding.
*/

#include <stdlib.h>
#include <stdio.h>

int main(){
    int cont = 1;
    char choice;
    
    do{
        int a;
        int b;
        char op;

        printf("Type INTEGER 1: ");
        scanf("%d", &a);
        printf("\n");

        printf("Type INTEGER 2: ");
        scanf("%d", &b);
        printf("\n");

        
        printf("Type operator (+, -, *, /, %%): ");
        scanf(" %c", &op); //ignore leading space.
        printf("\n");

        switch(op){
            case '+':
                printf("%d", a+b);
                break;
            case '-':
                printf("%d", a-b);
                break;
            case '*':
                printf("%d", a*b);
                break;
            case '/':
                printf("%d", a/b);
                break;
            case '%':
                printf("%d", a%b);
                break;
            default:
                printf("Invalid Operator\n");
                break;
        }
        printf("\n");

        printf("Would you like to continue? (y/n): ");
        scanf(" %c", &choice);

        if(choice == 'Y' || choice == 'y'){
            printf("Continuing \n\n");
        }
        else{
            cont = 0;
            if(choice != 'N' && choice != 'n'){
                printf("\nInvalid entry. Terminating program\n");
            }
        }

    }while(cont);


    return 0;
}