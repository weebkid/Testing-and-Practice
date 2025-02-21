#include <stdio.h>

void menu();
void print(float sum, float average, float highest, float lowest);
float average(float sum, int size);
float highest(float arr[], int size);
float lowest(float arr[], int size);
float enter_grades(float arr[], int size);

void main() {
    int choice;
    const int SIZE = 6;
    float m_arr[SIZE], m_sum, m_avg, m_highest, m_lowest;
    int steps_completed[4] = {0};
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {

            case 1:
                m_sum = enter_grades(m_arr, SIZE);
                printf("\nGrade entry complete.\n\n");
                steps_completed[1] = steps_completed[2] = steps_completed[3] = 0;
                steps_completed[0] = 1;
                break;

            case 2:
                if (steps_completed[0]){
                    m_avg = average(m_sum, SIZE);
                    printf("\nAverage has been calculated\n\n");
                    steps_completed[1] = 1;
                } else {
                    printf("\nMust populate array.\n\n");
                }

            case 3:
                if (steps_completed[0]){
                    m_highest = highest(m_arr, SIZE);
                    steps_completed[2] = 1;
                    printf("\nHighest grade has been found.\n");
                } else {
                    printf("\nMust populate array.\n\n");
                }    
                break;

            case 4:

                if (steps_completed[0]){
                    m_lowest = lowest(m_arr, SIZE);
                    steps_completed[3] = 1;

                    printf("\nLowest grade has been found.\n");
                } else {
                    printf("\nMust populate array.\n\n");
                }

                break;
            
            case 5:
                if ((steps_completed[0] && steps_completed[1] && steps_completed[2] && steps_completed[3])){
                    print(m_sum, m_avg, m_highest, m_lowest);
                } else {
                    printf("\nAll steps must be completed.\n\n");
                }
                break;

            case 6:
                printf("\nExiting...");
                break;

        }

    } while (choice != 6);

}

float enter_grades(float arr[], int size){

    float sum = 0;
    for (int i = 0; i < size; i++){
        printf("Enter grade #%d: ", i+1);
        scanf("%f", &arr[i]);
        sum += arr[i];
    }
    return sum;
}

float average(float sum, int size){
    int avg = sum / size;

    return avg;
}

float highest(float arr[], int size){
    float highest = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > highest){
            highest = arr[i];
        }

    }
    return highest;
}

float lowest(float arr[], int size){
    float lowest = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] < lowest){
            lowest = arr[i];
        }

    }
    return lowest;
}

void print(float sum, float avg, float highest, float lowest){
    printf("\nSum of student grades: %.2f\nClass Average: %.2f\nHighest Grade: %.2f\nLowest Grade: %.2f\n", sum, avg, highest, lowest);
}

void menu(){
    printf("---\tMenu\t---\n1. To enter six grades\n2. Calculate the average grade\n3. Calculate the highest grade\n4. Calculate the lowest grade\n5. Print Results\n6. Exit\n\nEnter choice: ");
}