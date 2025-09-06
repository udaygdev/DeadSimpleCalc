/* Note from Sep 4:
This is just a simple calculator used for my own understanding of some principles.
It has little to no safeguards in place, so overflow and wrong type of inputs will cause errors.
I might change it in the near future to account for different types or overflow. Otherwise, this is just for my own understanding.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int checkValidity(char *ptr, int len){ //used to check if input is integer only.

    for(int i = 0; i < len-1; i++){
        //if decimal or invalid integer return 0 
        if( ((ptr[i] == '.') || atoi(&ptr[i]) == 0 )){
            return 0;
        }
    }
    return 1;
}


int main(){
    int cont = 1;
    char choice;
    int a;
    int b;
    char op;
    char buff[100];


    do{
        printf("Type INTEGER 1: ");
        char *stream = fgets(buff, sizeof(buff), stdin);

        if(checkValidity(stream, strlen(buff)) == 0){
            printf("Incorrect Type. Expected Integer. Terminating Program");
            break;
        }
        
        a = atoi(stream);

        printf("\n");

        printf("Type INTEGER 2: ");
        stream = fgets(buff, sizeof(buff), stdin);
        if(checkValidity(stream, strlen(buff)) == 0){
            printf("Incorrect Type. Expected Integer. Terminating Program");
            break;
        }

        b = atoi(stream);

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
        getchar();
    }while(cont);


    return 0;
}