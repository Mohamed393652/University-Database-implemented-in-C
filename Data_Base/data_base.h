#ifndef _DATA_BASE
#define _DATA_BASE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "platform_type.h"

typedef struct
{
    unsigned char student_name[30];
    uint32 student_id;
    float student_gpa;
}student_t;

struct node
{
    student_t * student_info;
    struct node * next_node;
};

typedef enum
{
    NULL_pointer,
    OK,
    NOK
}status;
typedef enum
{
    NO,
    Yes,

}save_t;
void insert_node(struct node ** List,uint32 id,float gpa,unsigned char name[30],status *ret);
void disblay(struct node * List,status ret);
void delete_node(struct node ** List,uint32 target_id);
void check_id(struct node * List,uint32 target_id);
uint32 count_student(struct node * List);
void modify_gpa(struct node * List,uint32 target_id,float new_gpa);
#endif // _DATA_BASE
