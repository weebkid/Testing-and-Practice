//Author: Jamar Plummer
//Description: A classwork activity. Create a menu driven program with sorting and searching functions.
#include <stdio.h>

int main(){
    int size, choice, sorted, exit = 0, grade = 0;

    printf("Enter the size of the class: ");
    scanf("%d", &size);
    int arr[size];
    while (!exit){
        printf("\n---\tMain Menu\t---\n\n1. Add a Grade\n2. Sort by bubble\n3. Search for test grades\n4. Exit\n\nEnter Operation: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if (grade < size){
                    printf("Enter grade: ");
                    scanf("%d", &arr[grade]);
                    grade++;
                    sorted = 0;
                }else{
                    printf("\nAll grades have been added.\n");
                }
                break;
            case 2:
                    int swap, temp; // P tracks number of passe
                
                    // Bubble Sorting
                    for (int i = 0; i < grade; i++){
                        swap = 0;
                        for (int j = 0; j < grade-1; j++){
                            if (arr[j] > arr[j+1]){
                                temp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                                swap = 1;
                            }
                        
                        }
                        if (swap == 0){
                            sorted = 1;
                            
                            printf("\nSorting complete!\n");
                            printf("Sorted array: [");
                            for (int i = 0; i < grade; i++){
                                printf(" %d", arr[i]);
                            }
                            printf(" ]");
                            break;
                        }
                    }
                break;

            case 3:
                if (sorted){
                    int searchVal, left = 0, right = grade - 1, mid, found = 0;
                    printf("Enter search value: ");
                    scanf("%d", &searchVal);
                
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
                    break;
                } else {
                    printf("\nMust sort before searching for grades.\n");
                }
                break;
            
            case 4:
                exit =  1;
                printf("\nExiting...\n");
        }

    }
}
