//
// Created by o9s9w on 2/19/2024.
//

#ifndef MINI_PROJECT_PROJECT_1_H
#define MINI_PROJECT_PROJECT_1_H

#endif //MINI_PROJECT_PROJECT_1_H

// structure representing each student.
struct student {
    int identifier;
    char name[30];
    int study_level;
    float average;
};


int identifier(struct student *S, int i, int year, int order) {
    char s[5], s1[5], s2[5], con1[5]="00", con2[5]="0";
    int result;
    year = year % 100;
    sprintf(s, "%d", year);
    if (order < 10) {
        strcat(s, con1);
        sprintf(s2, "%d", i);
        strcat(s, s2);
        result = atoi(s);
        return (result);
    }
    else if (order < 100) {
        strcat(s, con2);
        sprintf(s2, "%d", i);
        strcat(s, s2);
        result = atoi(s);
        return (result);
    }
    else {
        sprintf(s2, "%d", i);
        strcat(s, s2);
        result = atoi(s);
        return (result);
    }
}

// secondary functions for primary functions.
void fill(struct student *S, int n, int o) {
    int i, year;
    for (i = 0; i < n; i++) {
        printf("\n- Student number %d\n", i + 1);
        printf("  Enter the student's year of registration: ");
        scanf("%d", &year);
        ((S+i)->identifier) = identifier(S, i, year, o);
        printf(" Enter the student's name: ");
        scanf("%s", (S+i)->name);
        do {
            printf(" Enter the student's study level 1-5: ");
            scanf("%d", &(S+i)->study_level);
        } while ((S+i)->study_level > 5 || (S+i)->study_level < 1);
        printf(" Enter the student's average: ");
        scanf("%f", &(S+i)->average);
    }
}

int find(struct student *S, int n, int ID) {
    int i;
    for (i = 0; i < n; i++) {
        if (ID == (S+i)->identifier) {
            return i;
        }
    }
    return -1;
}

void size(int *n) {
  printf("Number of students: ");
  scanf("%d", n);
}

void choice(int *choice) {
    printf("\nPlease specify the operation to be preformed\n\n");
    printf("0. Exite the application\n1. Add a student\n2. Remove a student\n3. Update a student\n");
    printf("4. Display the list of students\n5. Find a student by ID\n6. Find sutfents by level\n");
    printf("7. Find students by average\n8. Calculate the general average by level\n9. Sort students\n");
    printf("Enter your choice:");
    scanf("%d", choice);
}

void display_one(struct student *S, int i) {
    printf("\n- Student number %d\n", i + 1);
    printf("  Student's identifier: %d\n", (S+i)->identifier);
    printf(" Student's name: %s\n", (S+i)->name);
    printf(" Student's study level: %d\n", (S+i)->study_level);
    printf(" Enter the student's average: %f\n", (S+i)->average);
}

void sort(struct student *S, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((S+i)->average > (S+j)->average) {
                struct student temp = *(S+i);
                *(S+i) = *(S+j);
                *(S+j) = temp;
            }
        }
    }
}



// primary functions for main.
int add_student(struct student *S, int n, int o){
    int i = o, year;
    if (n == 100) {
        return printf("\nCANT ADD A STUDENT THE STRUCTURE IS FULL\n\n\n");
    }
    else {
        printf("\n- New student: \n");
        printf("  Enter the student's year of registration: ");
        scanf("%d", &year);
        ((S + n)->identifier) = identifier(S, i, year, o);
        printf(" Enter the student's name: ");
        scanf("%s", (S + n)->name);
        do {
            printf(" Enter the student's study level 1-5: ");
            scanf("%d", &(S + n)->study_level);
        } while ((S + n)->study_level > 5 || (S + n)->study_level < 1);
        printf(" Enter the student's average: ");
        scanf("%f", &(S + n)->average);
        printf("\n\n\n");
        return n + 1;
    }
}

int remove_student(struct student *S, int n) {
    int ID, x, i;
    printf("\nPlease enter the Id of the student you wants to remove: ");
    scanf("%d", &ID);
    x = find(S, n, ID);
    if (x == -1){
        printf("Student not found\n");
    }
    else {
        for (i = x; i < n - 1; i++) {
            *(S+i) = *(S+i+1);
        }
    }
    printf("\n\n\n");
    return n-1;
}

void update_student(struct student *S, int n) {
    int ID, x;
    printf("Please enter the Id of the student you want to update: ");
    scanf("%d", &ID);
    x = find(S, n, ID);
    if (x == -1){
        printf("Student not found\n");
    }
    else {
        printf("Update name: ");
        scanf("%s", (S+x)->name);
        do {
            printf("Update study level 1-5: ");
            scanf("%d", &(S+x)->study_level);
        } while ((S+x)->study_level > 5 || (S+x)->study_level < 1);
        printf("Update average: ");
        scanf("%f", &(S+x)->average);
    }
    printf("\n\n\n");
}

void display_students(struct student *S, int n) {
    int i;
    printf("\n");
    for (i = 0; i < n; i++) {
        display_one(S, i);
    }
    printf("\n\n\n");
}

void find_id(struct student *S, int n) {
    int ID, i;
    printf("\nPlease enter the Id of the student you want to find: ");
    scanf("%d", &ID);
    i = find(S, n, ID);
    display_one(S, i);
    printf("\n\n\n");
}

void find_level(struct student *S, int n) {
    int level, i;
    printf("\nPlease enter the level of the student you want to find: ");
    scanf("%d", &level);
    for (i = 0; i < n; i++) {
        if ((S+i)->study_level == level) {
            display_one(S, i);
        }
    }
    printf("\n\n\n");
}

void find_average(struct student *S, int n) {
    int i;
    float average;
    printf("\nPlease enter the average you want to search for: ");
    scanf("%f", &average);
    for (i = 0; i < n; i++) {
        if ((S+i)->average == average) {
            display_one(S, i);
        }
    }
    printf("\n\n\n");
}

int general_average(struct student *S, int n) {
    float sum;
    int i;
    for (i = 0; i < n; i++) {
        sum += (S+i)->average;
    }
    return sum/n;
}

void sort_students(struct student *S, int n) {
    int i, j;
    sort (S, n);
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((S+i)->study_level > (S+j)->study_level) {
                struct student temp = *(S+i);
                *(S+i) = *(S+j);
                *(S+j) = temp;
            }
        }
    }
    printf("\n\n\n");
}


