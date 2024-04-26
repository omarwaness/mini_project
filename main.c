#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project_1.h"

int main()
{
    struct student *students;
    int c, number, order = 1;
    float avg;

    size(&number);
    order = number;
    students = (struct student*) malloc(number * sizeof(struct student));
    fill(students, number, order);

    do {
        choice( &c);
        switch (c) {
            case 0:
                break;
            case 1:
                students = (struct student*) realloc(students,  (number+1) * sizeof(struct student));
                number = add_student(students, number, order);
                order++;
                break;
            case 2:
                number = remove_student(students, number);
                break;
            case 3:
                update_student(students, number);
                break;
            case 4:
                display_students(students, number);
                break;
            case 5:
                find_id(students, number);
                break;
            case 6:
                find_level(students, number);
                break;
            case 7:
                find_average(students, number);
                break;
            case 8:
                avg = general_average(students, number);
                printf("\nThe general average is %f\n\n\n", avg);
                break;
            case 9:
                sort_students(students, number);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }while(c != 0);

    return 0;
}
