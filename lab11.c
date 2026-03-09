#include <stdio.h>
#define NO_SCORE 5
#define NO_STD 10

typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;

void readStudentData(Student *);
void findTotalScore(Student *);
float findAverage(Student);
void findLessThanTen(Student);

void main() {
    Student std[NO_STD];
    float avg;
    int i;

    for(i=0; i<NO_STD; i++) {
        printf("\nStudent %d\n", i+1);
        readStudentData(&std[i]);
    }

    FILE *fp = fopen(".\\lab11\\no2\\std10.dat", "w");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    for(i=0; i<NO_STD; i++) {
        int j;
        fprintf(fp, "%s %s", std[i].name, std[i].surname);
        for(j=0; j<NO_SCORE; j++)
            fprintf(fp, " %d", std[i].score[j]);
        fprintf(fp, "\n");
    }
    fclose(fp);

    fp = fopen(".\\lab11\\no2\\std10.dat", "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    for(i=0; i<NO_STD; i++) {
        int j;
        fscanf(fp, "%s %s", std[i].name, std[i].surname);
        for(j=0; j<NO_SCORE; j++)
            fscanf(fp, "%d", &std[i].score[j]);
    }
    fclose(fp);

    for(i=0; i<NO_STD; i++) {
        findTotalScore(&std[i]);
        avg = findAverage(std[i]);
        printf("\n\tAverage score is %.2f", avg);

        findLessThanTen(std[i]);
    }
}

void readStudentData(Student *pStd) {
    int i;
    printf("Enter student data\n");
    printf("\tName : ");
    scanf("%s", pStd->name);
    printf("\tSurname : ");
    scanf("%s", pStd->surname);
    for (i=0; i<NO_SCORE; i++) {
        printf("\tScore %d : ", i+1);
        scanf("%d", &pStd->score[i]);
    }
}
void findTotalScore(Student *pStd) {
    int i;
    printf("\n\nPrint student data");
    printf("\n\t%s %s got score ", pStd->name, pStd->surname);
    pStd->total = 0.0;
    for (i=0; i<NO_SCORE; i++) {
        printf("%6d", pStd->score[i]);
        pStd->total += pStd->score[i];
    }
    printf("\n\tTotal score is %.2f", pStd->total);
}
float findAverage(Student s) {
    return(s.total/NO_SCORE);
}
void findLessThanTen(Student s) {
    int i, count=0;
    printf("\n\nScore less than 10");
    for (i=0; i<NO_SCORE; i++) {
        if (s.score[i] < 10) {
            printf("\n\tTest no.%d - %d", i+1, s.score[i]);
            count++;
        }
    }
    if (count==0)
        printf(" -> None");
}
