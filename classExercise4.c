// Author: Jamar Plummer
// Description: A classwork exercise. Create a program using functions that 1. Finds and returns the smallest of 3 numbers entered by the user 2. Finds and returns the average of the 3 numbers
 
#include <stdio.h>
#include <stdlib.h>
 
const int SIZE = 3;
 
int smallest ( int arr[SIZE]);
float average (int arr[SIZE]);
 
void main()
{
    int m_arr[SIZE], pop, choice;
 
    do {
        printf("\n---\tMenu\t---\n\n1. Enter numbers\n2. Find the smallest number\n3. Find the average\n4. Exit\n\nEnter Selection: ");
        scanf("%d", &choice);
        switch (choice) {
 
        case 1:
            for (int i = 0; i < SIZE; i++){
                printf("Enter element %d: ", i+1);
                scanf("%d", &m_arr[i]);
            }
 
            pop = 1;
            break;
 
        case 2:
            if (pop) {
                printf("\nSmallest number: %d", smallest(m_arr));
            }
 
            else printf("\nEnter numbers first (Option 1).\n");
            break;
 
        case 3:
            if (pop) {
                printf("\nAverage: %.2f\n", average(m_arr));
            }
 
            else printf("\nEnter numbers first (Option 1).\n");
            break;
 
        case 4:
            printf("\nExiting...\n");
            break;
 
        default:
            printf("\nInvalid Option.\n");
        }
 
 
    } while (choice != 4);
}
 
int smallest( int arr[SIZE]){
 
    int small = arr[0];
 
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < small) small = arr[i];
    }
 
    return small;
}
 
float average(int arr[SIZE]){
 
    float avg = 0.0;
 
    for (int i = 0; i < SIZE; i++){
        avg += arr[i];
    }
 
    avg = (float) avg / SIZE;
 
    return avg;
}