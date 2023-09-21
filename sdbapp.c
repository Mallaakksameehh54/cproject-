#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"

void SDB_action(uint8 choice)
{
    unsigned int id;
    uint8 i,count;
    uint32 *list[10];


    switch (choice)
    {
        case 1:
        if (SDB_AddEntry())
            printf("your data added in right way\n");
        break;

        case 2:
        printf("the size of database --> %u\n", SDB_GetUsedSize());
        break;

        case 3:

        printf("Enter Student ID to read: ");
        scanf("%u", &id);

        if (!SDB_ReadEntry(id))
            {
            printf("sorry the student not found\n");
            }
        break;

        case 4:
            SDB_GetList(&count, list);
            printf("the number of student IDs --> \n");
            for (i = 0; i < count; i++)
                {
                printf("%u\n", list[i]);
            }
            break;

        case 5:
        printf("Enter student ID: ");
        scanf("%u", &id);
        if (SDB_IsIdExist(id))
            printf("Student ID exists.\n");
        else
            printf("Student ID does not exist.\n");
        break;

        case 6:
        printf("*Do you want to delete data?*\n");
        printf("to confirm enter the student ID\n");
        scanf("%u", &id);
        SDB_DeleteEntry(id);
        printf("now student data deleted\n");
        break;

        case 7:
        if (SDB_IsFull())
            printf("your database is full now\n");
        else
            printf("your database is not full now\n");
        break;

        default:
        printf("sorry ..invalid choice\n");
        break;


    }

}



void SDB_APP()
{
    uint8 choice;


 while (1)
    {
      printf("Enter the task that you want to perform\n");

      printf("1. Add a new Student Detail\n");
      printf("2. To get the storage of database\n");
      printf("3. Find the details of a Student using ID-Number\n");
      printf("4. Find Total number of Students\n");
      printf("5. To check is ID is existed or not\n");
      printf("6. Delete the details of an Student \n");
      printf("7. To check is database is full or not \n");
      printf("8. for exit please press(zero)\n");



        scanf("%u", &choice);

        if(choice == 0)
            break;



SDB_action(choice);
    }
}

