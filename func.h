#include<stdlib.h>
#include<stdio.h>
#define STACK_LINK_H_INCLUDED
#define  MaxStudent   50

int index;

typedef struct {
    char name[20];
    char birthDate[10];
    char address[30];
    char phone[15];
    int ID;
    float score;
    struct StackNode *Next;
}StackNode;

StackNode *arr[MaxStudent];

typedef struct {
    StackNode *top ;
}Stack;

// Initializing the stack
void init_Stack(Stack *Ps);

// Main Menu that appear to the user
int main_menu();

//function that take student information from the user
void get_info(StackNode *Pn);

// function used to add student to the list
void New_Student(Stack *Ps);

// function used to Delete student from the list
void Delete_Student(Stack *Ps);

/*
   this function is checking if the stack is empty (no Stacknode created ) or not
   return 0 or 1
*/
 char Empty_Stack(Stack *Ps);

/*
   function that take id from the user and search for his index in the array
   return his index
*/
int  Find_Student(int id);


/*
   This function take the index of specific student in the array
   and print information of that student
*/
void Student_info(int x);

// function that take id from the user and print all details of that student
void Student_Details();

// this function print all student details
void Student_list();

// This function edit any information about any student in the list
void Student_Edit();

// This function print 3 students with highest computer science score
void Rank_Student();

