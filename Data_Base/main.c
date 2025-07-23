#include <stdio.h>
#include <stdlib.h>
#include "data_base.h"
struct node * linked_list = NULL;
unsigned char sname[30];
uint32 ID = 0;
float Gpa = 0;
status Ret = NOK;
uint32 count = 0;
uint32 choice = 0;
uint32 target_id = 0;
float new_gpa = 0;

int main()
{
    print_intro();
    while(1)
    {
        printf("************************************************\n");
        printf("\n===== Student Management System =====\n");
        printf("1 => To Add New Student \n");
        printf("2 => To Delete Student \n");
        printf("3 => To Check Id Or Show Data For Specific Id\n");
        printf("4 => To Count Students \n");
        printf("5 => To Modify Student Gpa\n");
        printf("6 => TO Display Students List\n");
        printf("7 => TO Save Program\n");
        printf("8 => TO End Program\n");
        printf("************************************************\n");
        printf("Enter Your Choice :\n");
        scanf("%i", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        printf("Enter Student Name :\n");
        scanf(" %[^\n]s", sname);
        printf("Enter Student ID :\n");
        scanf("%i", &ID);
        printf("Enter Student Gpa :\n");
        scanf("%f", &Gpa);
        insert_node(&linked_list,ID,Gpa,sname,&Ret);
        system("cls");
    break;
    case 2:
        system("cls");
        printf("Enter Id Of The Student\n");
        scanf("%i", &target_id);
        delete_node(&linked_list,target_id);
        system("cls");
    break;
    case 3:
        printf("Enter Id Of The Student\n");
        scanf("%i", &target_id);
        check_id(linked_list,target_id);
    break;
    case 4:
        system("cls");
        count = count_student(linked_list);
        printf("Number Of Students Is %i\n",count);
    break;
    case 5:
        system("cls");
        printf("Enter Id Of The Student\n");
        scanf("%i", &target_id);
        printf("Enter New Gpa \n");
        scanf("%f", &new_gpa);
        modify_gpa(linked_list,target_id,new_gpa);
        system("cls");
    break;
    case 6:
        system("cls");
        disblay(linked_list,Ret);
    break;

    case 7:
        save_func(linked_list);
    break;
    case 8:
        system("cls");
        uint32 choice = 0;
        printf("Do You Want To Save Your Data Base?");
        printf("0 For No ,1 For Yes\n");
        scanf("%i", &choice);

            switch (choice)
            {
            case 0:
                printf("Ending Program...\n");
                sleep(1.5);
                system("cls");
            break;
            case 1:
                save_func(linked_list);
            break;
            default:
                printf("Invalid Choice !!\n");
            }


        return 0;

    default:
        printf("Invalid Choice !!\n");
    }
    }
    return 0;
}
