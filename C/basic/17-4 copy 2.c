#include <stdio.h>

struct student
{
    int num;
    double grade;
};
typedef struct student Student;

void print_data(Student *ps);

int main()
{
    Student s1={315, 3.2};

    print_data(&s1);

    return 0;
}

void print_data(Student *ps)
{
    printf("학번: %d 학점: %lf", ps->num, ps->grade);
}