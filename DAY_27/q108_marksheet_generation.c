/*
* LOGIC: The Marksheet Generator
 * 1. Take marks for 5 subjects.
 * 2. Calculate Total and Percentage.
 * 3. Use an if-else ladder to assign a character Grade based on the percentage.
 */



#include <stdio.h>


int main() {

    char name[50];
    int roll, math, sci, eng, hindi, comp, total;
    float percentage;
    char grade;

    printf("--- Marksheet Generator ---\n");
    printf("Enter Student Name: ");
    scanf(" %[^\n]s", name);
    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter marks out of 100 for Math, Science, English, Hindi, Computer (Space separated):\n");
    scanf("%d %d %d %d %d", &math, &sci, &eng, &hindi, &comp);

    total = math + sci + eng + hindi + comp;
    percentage = (float)total / 5.0;

    if (percentage >= 90) grade = 'A';
    else if (percentage >= 80) grade = 'B';
    else if (percentage >= 70) grade = 'C';
    else if (percentage >= 60) grade = 'D';
    else grade = 'F'; // Fail

    printf("\n====================================\n");
    printf("           FINAL MARKSHEET          \n");
    printf("====================================\n");
    printf("Name: %-15s Roll: %d\n", name, roll);
    printf("------------------------------------\n");
    printf("Mathematics : %d\n", math);
    printf("Science     : %d\n", sci);
    printf("English     : %d\n", eng);
    printf("Hindi       : %d\n", hindi);
    printf("Computer    : %d\n", comp);

    printf("------------------------------------\n");
    printf("Total Marks : %d / 500\n", total);
    printf("Percentage  : %.2f%%\n", percentage);
    printf("Grade       : %c\n", grade);
    printf("====================================\n");


    return 0;
}