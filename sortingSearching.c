// Author: Jamar Plummer
// Description: Tests to see the speed of Bubble and Selection Sorting algorithms using a large list of integers.
// Note: This is definitely not the optimal implementation of both, but this is just a rough experiment out of curiosity.
// To DO: Add Insert function

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 100000; // Controls the size of the array. Modify this if the program takes too long to run.

double bubble(int arr[SIZE]);

double select(int arr[SIZE]);

// double insert(int arr[SIZE]);

int linear_search(int arr[SIZE]);

int binary_search(int arr[SIZE]);

#include <stdio.h>
#include <stdlib.h>
const int SIZE = 10;


double bubble(int arr[SIZE]){
    int swap, temp, p = 0; // P tracks number of passes
    double time1, timediff, o = 0; // O tracks number of operations

    time1 = clock(); // Stores the time when the sorting begins

    // Bubble Sorting
    for (int i = 0; i < SIZE; i++){
        p++;
        swap = 0;
        for (int j = 0; j < SIZE-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = 1;
                o++;
            }
        
        }
        if (swap == 0){
            timediff = clock(); // Stores the time when the sorting ends
            timediff = timediff - time1;
            timediff = timediff / CLOCKS_PER_SEC; // Calculates the total time taken to run

            printf("First Element: %d\tLast Element: %d\tPasses: %d\tSwap Operations (4 assignments): %.0lf\n", arr[0], arr[SIZE-1], p, o);
            break;
        }
    }
    return timediff;
}

double select(int arr[SIZE]){
    int target, trace, p = 0, o = 0; // O tracks number of operations. P tracks number of passes
    double time1, timediff;
    time1 = clock(); // Stores time when the sorting begins


    // Selection Sorting
    for (int i = 0; i < SIZE; i++){
        p++;
        trace = arr[i]; // Trace is the current position being determined
        target = i; // Target is the position of the smallest number in the remaining portion of the list

        for (int j = 0; j < SIZE - i; j++){
            if (arr[j+i] < arr[target]){
                target = j+i;
                o++;
            }
        }
        arr[i] = arr[target];
        arr[target] = trace;
        o += 2;
    }

    timediff = clock(); // Stores time when the sorting ends
    timediff = timediff - time1;
    timediff = timediff / CLOCKS_PER_SEC; // Calculates time taken to sort
    printf("First Element: %d\tLast Element: %d\tPasses: %d\tAssignment Operations: %d\n", arr[0], arr[SIZE-1], p, o);

    return timediff;
}

int binary_search(int arr[SIZE]){
    int searchVal, left = 0, right = SIZE - 1, mid, found = 0;
    printf("Sorting...\n");
    bubble(arr);
    printf("Enter search value: ");
    scanf("%d", &searchVal);
 
    while (left <= right){
        
        mid = (left + right) / 2;
        if (arr[mid] == searchVal){
            found = 1;
            printf("The value %d was found in position %d", searchVal, mid);
            break;
        } else if (arr[mid] > searchVal) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (!found){
        printf("The value %d was not found in the array.", searchVal);
    }
}

int linear_search(int arr[SIZE]){
    int searchVal, index, found = 0;
 
    for (index = 0; index < SIZE; index++){
        printf("Enter element for the array: ");
        scanf("%d", &arr[index]);
    }
    printf("Enter search value: ");
    scanf("%d", &searchVal);
    for (index = 0; index < SIZE; index++){
        if(arr[index] == searchVal){
            found = 1;
            break;
        }
    }
 
    if(!found){
        printf("\nThe value %d was not found in the array.", searchVal);
    } else{
        printf("\nThe value %d was found at position %d in the array.", searchVal, index);
    }
 
}