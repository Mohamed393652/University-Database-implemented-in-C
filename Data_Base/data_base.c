#include "data_base.h"
void insert_node(struct node ** List,uint32 id,float gpa,unsigned char name[30],status *ret)
{
    struct node * tempnode = NULL;
    struct node * lastnode = NULL;
    tempnode = (struct node *)malloc(sizeof(struct node));
    if(tempnode != NULL)
    {
        tempnode->student_info = (student_t *)malloc(sizeof(student_t));
        if (tempnode->student_info == NULL) {
            free(tempnode);
            *ret = NULL_pointer;
            return;
        }

        tempnode->next_node = NULL;
        strcpy(tempnode->student_info->student_name,name);
        tempnode->student_info->student_id = id;
        tempnode->student_info->student_gpa = gpa;
        if(NULL == *List)
        {
            *List = tempnode;
        }
        else
        {
          lastnode = * List;
        while(lastnode->next_node != NULL)
        {
            lastnode = lastnode->next_node;
        }
        lastnode->next_node = tempnode;
        }
        *ret = OK;
    }
    else
    {
       *ret = NOK;
    }
}

void disblay(struct node * List,status ret)
{
    uint32 counter = 1;
    struct node * tempnode = List;
    if(NULL == List)
    {
        ret = NULL_pointer;
    }
    else
    {
        while(tempnode != NULL)
        {
            printf("%i: => %s        => %i       => %f\n",counter,tempnode->student_info->student_name,tempnode->student_info->student_id,tempnode->student_info->student_gpa);
            counter++;
            tempnode = tempnode->next_node;
        }

    }
}

void delete_node(struct node ** List,uint32 target_id)
{

    if(*List == NULL)
    {
        printf("List Is Empty \n");
        return;
    }
    struct node * tempnode = *List;
    struct node * lastnode = NULL;
    if(tempnode->student_info->student_id == target_id)
    {
        *List = tempnode->next_node;
        free(tempnode);
        return;
    }
    while(tempnode != NULL && tempnode->student_info->student_id != target_id)
    {
        lastnode = tempnode;
        tempnode = tempnode->next_node;

    }
    if (tempnode == NULL) {
        printf("Node with ID %u not found in the list.\n", target_id);
        return;
    }
    lastnode->next_node = tempnode->next_node;

    free(tempnode);
}
void check_id(struct node * List,uint32 target_id)
{
    struct node * tempnode = List;
    while(tempnode != NULL )
    {
        if(tempnode->student_info->student_id == target_id)
        {
            printf("Id Found \n");
            printf("=============================================\n");
            printf("Student Name:%s\n",tempnode->student_info->student_name);
            printf("Student Gpa:%0.2f\n",tempnode->student_info->student_gpa);
            printf("=============================================\n");
            return;
        }
        else{}

        tempnode = tempnode->next_node;
    }
    if(tempnode == NULL)
    {
        printf("Id Not Found\n");
    }

}

uint32 count_student(struct node * List)
{
    uint32 counter = 0;
    struct node *tempnode = List;
    while(tempnode != NULL)
    {
        counter++;
        tempnode = tempnode->next_node;
    }
    return counter;
}
void modify_gpa(struct node * List,uint32 target_id,float new_gpa)
{
    struct node * tempnode = List;
    while(tempnode != NULL && tempnode->student_info->student_id != target_id)


        {
            tempnode = tempnode->next_node;
        }

    if(tempnode == NULL)
    {
        printf("Id Not Found\n");
    }
    else{
        tempnode->student_info->student_gpa = new_gpa;
    }
}
void print_intro() {
    printf("=====================================\n");
    printf(" Welcome to the Student Database \n");
    printf("=====================================\n");
    printf("Developed by: Mohamed Tamer\n");
    printf("Version: 1.0\n\n");

    printf("Loading the system");

    loading_animation(3);
    printf("\n\nSystem Ready!\n\n");

    printf("Instructions:\n");
    printf("Enter student details when prompted.\n");
    printf("Make sure to enter valid IDs and GPAs.\n");
    printf("The system will store and manage student records.\n");
    printf("\nLet's get started!\n\n");
    sleep(3.5);
    system("cls");
}
void loading_animation(int seconds) {
    char spinner[] = "|/-\\";
    int i = 0;
    for (int t = 0; t < seconds * 10; t++) {  // Multiply for a smoother effect
        printf("%c\b", spinner[i]);  // Print a spinning effect
        fflush(stdout);
        usleep(100000);  // Sleep for 100ms for smooth animation
        i = (i + 1) % 4;  // Cycle through spinner characters
    }
}

void save_func(struct node * List)
{
    FILE *file;
    uint32 count =0;
    file = fopen("data.txt", "w");
        struct node * tempnode = List;
        if (file == NULL)
        {
        printf("Error opening file!\n");
      //  return 1;
        }
        uint32 counter = 0;
        count = count_student( List);
        for(counter =0;counter<count;counter++)
        {
            fprintf(file," Id [%i] - Name [%s] - Gpa [%f]\n",tempnode->student_info->student_id,tempnode->student_info->student_name,tempnode->student_info->student_gpa);
            tempnode = tempnode->next_node;
        }

        fclose(file);

        printf("File updated successfully!\n");
}
