/*
10/13/2024
Luke Reicherter
KU ID: 3135060
EECS 348: Lab 05
Lab Session: Thursday 11:00 AM
Description: This program will take in an input file with twelve income values and generate a
detailed report of those values.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MonthInfo {
    //This structure is used to store the income an corresponding month in one place
    float income;
    char month[10];
};

float avg_sales(struct MonthInfo *MonthInfoArray, int a, int b) {
    //This function uses the MonthInfoArray to generate the average income over a set index a through b
    float avg = 0;
    for (int i = a; i < b; i++) {
        avg += MonthInfoArray[i].income;
    }
    return (avg/(b-a));
}

struct MonthInfo max_sales(struct MonthInfo *MonthInfoArray) {
    //This function returns the structure that stores the month and income of the max sale month
    struct MonthInfo max = MonthInfoArray[0];
    for (int i = 1; i < 12; i++) {
        if (max.income < MonthInfoArray[i].income) {
            max = MonthInfoArray[i];
        }
    }
    return max;
}

struct MonthInfo min_sales(struct MonthInfo *MonthInfoArray) {
    //This function returns the structure that stores the month and income of the min sale month
    struct MonthInfo min = MonthInfoArray[0];
    for (int i = 1; i < 12; i++) {
        if (min.income > MonthInfoArray[i].income) {
            min = MonthInfoArray[i];
        }
    }
    return min;
}

void insertion_sort(struct MonthInfo *MonthInfoArray, int n) {
    //This function uses insertion sort to sort the list of sturctures from lowest to highest
    for (int i = 1; i < n; i++) {
        struct MonthInfo temp = MonthInfoArray[i];
        int j = i - 1;
        while (j >= 0 && MonthInfoArray[j].income > temp.income) {
            MonthInfoArray[j + 1] = MonthInfoArray[j];
            j = j - 1;
        }
        MonthInfoArray[j + 1] = temp;
    }
}

int main() {
    /*This is the main function that obtains the input from the file and prints all output. First an 
    array of floats is created. This will store the floats from the input file*/
    float sal_array[12];
    FILE* sal_fig;
    sal_fig = fopen("salesfigures.txt", "r");
    if (sal_fig == NULL) {
        //This code checks to see if the file could be obtained, and ends the code if not
        printf("Sales figures could not be obtained, make sure to name the file properly\n");
        return 0;
    }
    int count = 0;
    while (count < 12 && fscanf(sal_fig, "%f", &sal_array[count]) == 1) {
        //This while statement collects the numbers from the input file and stores it in an array
        count++;
    }
    printf("Monthly Sales Report for 2024\n\nMonth\t\tSales\n");
    //The values that were stored in the previous array are then used to create a stucture with month and income info
    struct MonthInfo m1;
    m1.income = sal_array[0];
    strcpy(m1.month, "January");
    struct MonthInfo m2;
    m2.income = sal_array[1];
    strcpy(m2.month, "February");
    struct MonthInfo m3;
    m3.income = sal_array[2];
    strcpy(m3.month, "March");
    struct MonthInfo m4;
    m4.income = sal_array[3];
    strcpy(m4.month, "April");
    struct MonthInfo m5;
    m5.income = sal_array[4];
    strcpy(m5.month, "May");
    struct MonthInfo m6;
    m6.income = sal_array[5];
    strcpy(m6.month, "June");
    struct MonthInfo m7;
    m7.income = sal_array[6];
    strcpy(m7.month, "July");
    struct MonthInfo m8;
    m8.income = sal_array[7];
    strcpy(m8.month, "August");
    struct MonthInfo m9;
    m9.income = sal_array[8];
    strcpy(m9.month, "September");
    struct MonthInfo m10;
    m10.income = sal_array[9];
    strcpy(m10.month, "October");
    struct MonthInfo m11;
    m11.income = sal_array[10];
    strcpy(m11.month, "November");
    struct MonthInfo m12;
    m12.income = sal_array[11];
    strcpy(m12.month, "December");
    //All structures are then put into an array
    struct MonthInfo MonthInfoArray[12] = {m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12};
    //The for loop below prints the month and income info in order, making sure to properly format the output
    for (int i = 0; i < 12; i++) {
        if (i == 1 || i == 8 || i == 10 || i == 11) {
            printf("%s\t$%.2f\n", MonthInfoArray[i].month, MonthInfoArray[i].income);
        }
        else {
            printf("%s\t\t$%.2f\n", MonthInfoArray[i].month, MonthInfoArray[i].income);
        }
    }

    printf("\nSales summary report:\n\n");
    //The sales summary report uses the min_sales, max_sales, and avg_sales function to calc the needed values
    struct MonthInfo minimum_sales = min_sales(MonthInfoArray);
    printf("Minimum Sales:\t$%.2f  (%s)\n", minimum_sales.income, minimum_sales.month);
    struct MonthInfo maximum_sales = max_sales(MonthInfoArray);
    printf("Maximum Sales:\t$%.2f  (%s)\n", maximum_sales.income, maximum_sales.month);
    float average_sales = avg_sales(MonthInfoArray, 0, 12);
    printf("Average Sales:\t$%.2f\n\n", average_sales);
    printf("Six-Month moving average report:\n\n");
    //The six-month moving average report uses the avg_sales function with specific indexs to generate the moving report
    printf("January-June\t$%.2f\n", avg_sales(MonthInfoArray,0,6));
    printf("February-July\t$%.2f\n", avg_sales(MonthInfoArray,1,7));
    printf("March-August\t$%.2f\n", avg_sales(MonthInfoArray,2,8));
    printf("April-September\t$%.2f\n", avg_sales(MonthInfoArray,3,9));
    printf("May-October\t$%.2f\n", avg_sales(MonthInfoArray,4,10));
    printf("June-November\t$%.2f\n", avg_sales(MonthInfoArray,5,11));
    printf("July-December\t$%.2f\n\n", avg_sales(MonthInfoArray,6,12));
    printf("Sales report (highest to lowest):\n\nMonth\t\tSales\n");
    //Insertion sort is called and fully transforms the array into lowest to highest income

    for (int i = 11; i > -1; i--) {
        //This for loop prints the array in reverse order, making it highest to lowest
        if (strcmp(MonthInfoArray[i].month, "February") == 0 || strcmp(MonthInfoArray[i].month, "September") == 0 ||
        strcmp(MonthInfoArray[i].month, "November") == 0 || strcmp(MonthInfoArray[i].month, "December") == 0) {
            printf("%s\t$%.2f\n", MonthInfoArray[i].month, MonthInfoArray[i].income);
        }
        else {
            printf("%s\t\t$%.2f\n", MonthInfoArray[i].month, MonthInfoArray[i].income);
        }
    }
    fclose(sal_fig);
    return 0;
}