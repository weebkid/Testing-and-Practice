#include <stdio.h>

void print_result(float val);
float add();
float subtract();
float multiply();
float divide();
int menu();

void main(){
    int exit = 0;
    float result;
    while (!exit){
        int choice = menu();
        switch(choice){
            case 1:
                result = add();
                break;
            case 2:
                result = subtract();
                break;
            case 3:
                result = multiply();
                break;
            case 4:
                result = divide();
                break;
            case 5:
                print_result(result);
                break;
            case 6:
                exit = 1;
                printf("Exiting...");
                break;
            default:
                printf("\n\nInvalid Selection.\n\n");
        }
    }
}

float add(){
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    float sum = num1 + num2;

    return sum;
}

float subtract(){
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    float diff  = num1 - num2;

    return diff;
}

float multiply(){
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    float product  = num1 * num2;

    return product;
}

float divide(){

    float numerator, denominator, quotient;
    printf("Enter numerator: ");
    scanf("%f", &numerator);
    printf("Enter denominator: ");
    scanf("%f", &denominator);
    if (denominator == 0){
        printf("Can't divide by 0. Returning result of 0.\n");
        quotient = 0;
    } else{
        quotient  = numerator / denominator;
    }

    return quotient;
}

int menu(){
    int choice;
    printf("\n---\tMain Menu\t---\n");
    printf("\n1. Add 2 numbers\n2. Subtract 2 nnumbers\n3. Multiply 2 numbers\n4. Divide 2 numbers\n5. Print result\n6. Exit\n\nEnter choice: ");
    scanf("%d", &choice);
    
    return choice;
}

void print_result(float val){
    printf("Result: %f\n", val);
    
}