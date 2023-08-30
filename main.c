/**********************************

Author : Mostafa Hessin Ahmed Qenawy

brief : School Managment System

Date  : 03/08/2023

************************************/


#include"func.h"

int main()
{
    index = 0 ;
    int flag  = 1 ;
    Stack s;
    init_Stack(&s);
    printf("\t\t Welcome To Our School Management System!\n");
    while(flag)
    {
        int x = main_menu();
        switch (x)
        {
            case 1 :
                New_Student(&s);
                break;
            case 2 :
                if(Empty_Stack(&s)){
                    printf("Stack Empty\n");
                    break;
                }
                Delete_Student(&s);
                break;
            case 3 :
                Student_Details();
                break;
            case 4 :
                Student_list();
                break;
            case 5 :
                Student_Edit();
                break;
            case 6 :
                Rank_Student();
                break;
            default:
                flag = 0;
                break;
        }
        printf("************************************\n");
        printf("0 - Exit  \n") ;
        printf("1 - Continue\n");
        scanf("%d" , &flag);
    }
}
