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

double insert(int arr[SIZE]);

double linear_search(int arr[SIZE]);

double binary_search(int arr[SIZE]);

#include <stdio.h>
#include <stdlib.h>

int main(){
    int base_arr[SIZE]; // The base array used
    int mod_arr[SIZE]; // A copy of the base array to be modified
    int exit = 0, option;
    char sec_option;
    srand(time(NULL)); // Uses the current time to create a random seed for the rand() function


    // Populates the base array with random integers
    for (int i = 0; i < SIZE; i++){
        base_arr[i] = rand();
    }

    while (!exit){
        printf("\n---\tTesting Menu\t---\n");
        printf("\n1: Bubble Sort\n2: Selection Sort\n3: Insertion Sort\n4: Binary Search\n5: Linear Search\n6: Exit\n\nEnter Option: ");
        scanf("%d", &option);
        memcpy(mod_arr, base_arr, sizeof(base_arr)); // Copies the base array to mod_array

        switch (option){
            case 1:
                printf("\nMaximum passes? (y/n): ");
                scanf(" %c", &sec_option);
                if (sec_option == 'y'){
                    mod_arr[SIZE-1] = -1;
                } else if (sec_option != 'n') {
                    printf("\nInvalid selection. Continuing without maximum passes...\n");
                }

                printf("\nTime taken for bubble sort %d elements: %lf\n", SIZE, bubble(mod_arr));
                break;

            case 2:
                printf("\nTime taken to selection sort %d elements: %lf\n", SIZE, select(mod_arr));
                break;
            case 3:
                printf("\nTime taken to insertion sort %d elements %lf\n", SIZE, insert(mod_arr));
                break;
            case 4:
                printf("\nTime taken to binary search (and selection sort) %d elements: %lf\n", SIZE, binary_search(mod_arr));
                break;
            case 5:
                printf("\nTime taken to linear search %d elements: %lf\n", SIZE, linear_search(mod_arr));
                break;
            case 6:
                printf("\nExiting....\n");
                exit = 1;
                break;
            
            default:
                printf("\nInvalid option.\n");
        }
    }
    // // Testing Begins

    // // Begin Testing the Bubble Sort
    // printf("Testing: Bubble Sort\n\n");

    // // General Array Test
    // memcpy(mod_arr, base_arr, sizeof(base_arr)); // Copies the base array to mod_array
    // printf("Time taken to sort an arbitrary array of %d numbers: %lfs\n", SIZE, bubble(mod_arr));


    // // Maximum Passes Test
    // memcpy(mod_arr, base_arr, sizeof(base_arr)); // Resets mod_array
    // mod_arr[SIZE-1] = -2;
    
    // printf("Time taken to sort arbitrary array of %d numbers with maximum passes: %lfs\n", SIZE, bubble(mod_arr));


    // // Begin testing the Selection Sort
    // printf("\nTesting: Selection Sort\n\n");

    // memcpy(mod_arr, base_arr, sizeof(base_arr)); // Resets mod_arary
    // printf("Time taken to sort an arbitrary array of %d numbers: %lfs\n", SIZE, select(mod_arr));

    // // Begin testing the Insertion Sort
    // printf("\nTesting: Insertion Sort\n\n");

    // memcpy(mod_arr, base_arr, sizeof(base_arr)); // Resets mod_arary
    // printf("Time taken to sort an arbitrary array of %d numbers: %lfs\n", SIZE, insert(mod_arr));

    // // Begin testing the Binary Search
    // printf("\nTesting: Binary Search\n\n");

    // memcpy(mod_arr, base_arr, sizeof(base_arr)); // Resets mod_arary
    // printf("Time taken to search an arbitrary array of %d numbers: %lfs\n", SIZE, select(mod_arr));

    return 0;
}

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

double insert(int arr[SIZE]){
    double time1 = clock(), timediff; // Stopwatch starts

    for (int i = 1; i < 10; ++i){
        int key = arr[i];
        int j = i - 1;

        while ( j >= 0 && arr[j] > key){
            printf("arr[i] = %d\narr[j] = %d\narr[j+1] = %d\n\n", arr[i], arr[j], arr[j+1]);
            arr[j + 1] = arr[j];
            
            j = j - 1;
        }
        arr[j + 1] = key;
        
    }

    timediff = (clock() - time1) / CLOCKS_PER_SEC; // Stopwatch finishes
    for (int x = 0; x < 100; x++){
        printf("%d ", arr[x]);
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

double binary_search(int arr[SIZE]){
    int searchVal, left = 0, right = SIZE - 1, mid, found = 0;
    double time1, timediff;

    select(arr);
    printf("Enter search value: ");
    scanf("%d", &searchVal);
   time1 = clock();

    while (left <= right){
        
        mid = (left + right) / 2;
        if (arr[mid] == searchVal){
            found = 1;
            printf("\nThe value %d was found in position %d", searchVal, mid);
            break;
        } else if (arr[mid] > searchVal) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (!found){
        printf("\nThe value %d was not found in the array.", searchVal);
    }

   timediff = clock();
   timediff = (timediff - time1) / CLOCKS_PER_SEC;

    return timediff;
}

double linear_search(int arr[SIZE]) {
    int searchVal, index, found = 0;
    double time1, timediff;

    printf("Enter search value: ");
    scanf("%d", &searchVal);
    time1 = clock();

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

    timediff = (time1 - clock()) / CLOCKS_PER_SEC;

    return timediff;
 
}