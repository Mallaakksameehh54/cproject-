#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"


static uint8 num_of_students = 0;

static student db[10];



bool SDB_ReadEntry(uint32 id)
{
    uint8 i;
    for (i = 0; i < num_of_students; i++)
    {
        if (db[i].Student_ID == id)
        {
            printf("student ID --> %u\n", db[i].Student_ID);
            printf("student year --> %u\n", db[i].Student_year);
            printf("course-1 ID --> %u\n", db[i].Course1_ID);
            printf("course-1 grade --> %u\n", db[i].Course1_grade);
            printf("course-2 ID --> %u\n", db[i].Course2_ID);
            printf("course-2 grade --> %u\n", db[i].Course2_grade);
            printf("course-3 ID --> %u\n", db[i].Course3_ID);
            printf("course-3 grade --> %u\n", db[i].Course3_grade);

            return true;
        }
    }
    return false;
}

uint8 SDB_GetUsedSize()
{
    return num_of_students;
}


bool SDB_AddEntry()
{
    if (SDB_IsFull())
        return false;

    student new_student;

    printf("please enter the student ID: ");
    scanf("%u", &new_student.Student_ID);

    printf("please enter the student Year: ");
    scanf("%u", &new_student.Student_year);

    printf("please enter course-1 ID: ");
    scanf("%u", &new_student.Course1_ID);

    printf("please enter course-1 grade: ");
    scanf("%u", &new_student.Course1_grade);

    printf("please enter course-2 ID: ");
    scanf("%u", &new_student.Course2_ID);

    printf("please enter course-2 grade: ");
    scanf("%u", &new_student.Course2_grade);

    printf("please enter course-3 ID: ");
    scanf("%u", &new_student.Course3_ID);

    printf("please enter course-3 grade: ");
    scanf("%u", &new_student.Course3_grade);



    db[num_of_students++] = new_student;

    return true;
}

bool SDB_IsFull()
{

    return num_of_students >= 10;
}

void SDB_DeleteEntry(uint32 id)
{
    uint8 i;


    uint8 j;

    for  (i = 0; i < num_of_students; i++)
    {
        if (db[i].Student_ID == id)
        {
            for (j = i; j < num_of_students - 1; j++)
            {
                db[j] = db[j + 1];
            }
            num_of_students--;
            break;
        }
    }
}


bool SDB_IsIdExist(uint32 id)
{
    uint8 i;

    uint32 list[10];

    for (i = 0; i < num_of_students; i++)
    {
        if (db[i].Student_ID == id)
        {
            return true;
        }
    }
    return false;
}


void SDB_GetList(uint8 *count, uint32 *list)
{
    uint8 i;

    *count = num_of_students;

    for (i = 0; i < num_of_students; i++)
    {
        list[i] = db[i].Student_ID;
    }
}



