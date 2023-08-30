#include"func.h"


void init_Stack(Stack *Ps){
    Ps->top = NULL ;
}

int main_menu(){
    int x ;
    printf("\n ************************************\n");
    printf("1- New Student\n");
    printf("2- Delete Student!\n");
    printf("3- Student Details!\n");
    printf("4- Student List!\n");
    printf("5- Student Edit \n");
    printf("6- Rank Student \n");
    printf("Please Choose Number From 1 : 6 \n");
    printf("************************************\n");
    scanf("%d" ,&x);
    return x;
}
void get_info(StackNode *Pn){
    int x ;
    int a =0;
    int flag = 1;
    fflush(stdin);
    printf("Please Enter the Student Name : ");
    gets(Pn->name);
    printf("The Student Birth Date :  ");
    gets(Pn->birthDate);
    printf("The Student Address :  ");
    gets(Pn->address);
    fflush(stdin);
    printf("The Student phone : ");
    gets(Pn->phone);

    /* checking if student have the same id of another student  */

    while(flag){
        printf("The Student ID : ") ;
        scanf( "%d" , &x);
        a = Find_Student(x);
        if (a == -1){
            Pn->ID = x ;
            flag =0;
        }
        else{
            printf("Invalid ID! \n") ;
        }
    }
    printf("Computer Science score : ") ;
    scanf( "%f" , &(Pn->score));
}

void New_Student(Stack *Ps){
    StackNode *Pn = (StackNode *) malloc(sizeof(StackNode));
    if(Pn == NULL){
        printf("Invalid Memory space!");
        return ;
    }
    Pn->Next = Ps->top;
    Ps->top =Pn;
    get_info(Pn);
    arr[index] = Pn;
    index++ ;
}

void Delete_Student(Stack *Ps){
    int x ;
    printf("Please Enter His ID : ");
    scanf("%d",&x) ;
    x = Find_Student(x); //passing ID to that function to get user index of aray arr[]
    if( x == index-1 ){
        StackNode *Ptr = Ps->top;
        Ps->top =Ps->top->Next;
        index-- ;
        arr[index] = NULL;
        free(Ptr);
        printf("Student account has been deleted \n");
    }
    else if(x == 0){
        arr[x+1]->Next = NULL;
        free(arr[0]);
        printf("Student account has been deleted \n");
    }
    else{
        arr[x+1]->Next = arr[x-1];
        arr[x] = NULL;
        free(arr[x]);
        printf("Student account has been deleted \n");
    }
}

char Empty_Stack(Stack *Ps){
    return Ps->top == NULL;

}

void Student_info(int x){
    if(arr[x] == NULL){
        printf("No Student With this ID \n");
        return ;
    }
    printf(" Name      : %s \n" , arr[x]->name);
    printf(" birthDate : %s \n" , arr[x]->birthDate);
    printf(" address   : %s \n" , arr[x]->address);
    printf(" phone     : %s \n" , arr[x]->phone);
    printf(" ID        : %d \n" , arr[x]->ID);
    printf(" Sc course : %f \n" , arr[x]->score);
    printf("************************************\n");
}

void Student_Details(){
    int x ;
    printf("Please Enter His ID : ");
    scanf("%d",&x) ;
    x = Find_Student(x);
    Student_info(x);
}

void Student_list(){
    for(int x=0 ; x <index ; x++)
        Student_info(x);
}


int Find_Student(int id){
    for(int x=0 ; x<index; x++)
    {
        if(arr[x]->ID == id)
            return x;
    }
    return -1;
}

void Student_Edit(){
    int x ;
    int a;
    int flag = 1;
    printf("Please Enter His ID : ");
    scanf("%d",&x) ;
    x = Find_Student(x);//passing ID to that function to get user index of aray arr[]
    if (x == -1){
        printf("No Student With This ID! \n");
        return ;
    }
    while(flag)
    {
        printf("Choose What To Edit : \n");
        printf("1 - Name  \t 2 - birth Date \t 3 - Address \n");
        printf("4 - Phone \t 5 - Computer Science Score   \n");
        scanf( "%d", &a);
        switch (a)
            {
                case 1 :
                    fflush(stdin);
                    printf("Please Enter the Student Name : ");
                    gets(arr[x]->name);
                    break;
                case 2 :
                    fflush(stdin);
                    printf("The Student Birth Date :  ");
                    gets(arr[x]->birthDate);
                    break;
                case 3 :
                    fflush(stdin);
                    printf("The Student Address :  ");
                    gets(arr[x]->address);
                    break;
                case 4 :
                    fflush(stdin);
                    printf("The Student phone : ");
                    gets(arr[x]->phone);
                    break;
                case 5 :
                    printf("Computer Science score : ");
                    scanf( "%f", &arr[x]->score);
                    break;
                default:
                    break;
            }
        Student_info(x);
        printf(" Press 0 TO Exit  \n") ;
        printf(" Press 1 To Continue Editing\n");
        scanf("%d" , &flag);
    }
}
void Rank_Student(){
    int a = 0 ,b = 0 , c = 0 ;
    int x , y , z ;
    for(int i=0 ; i<index; i++)
    {
        if(arr[i]!= NULL)
        {
            if(arr[i]->score > a){
                c = b;
                b = a;
                a = arr[i]->score;
                z = y;
                y = x;
                x = i;
            }
            else if (arr[i]->score > b){
                c = b;
                b = arr[i]->score;
                z = y;
                y = i;
            }
            else if (arr[i]->score > c){
                c = arr[i]->score;
                z = i;
            }
        }
    }
    printf("************************************\n");
    printf("First Student is %s with score %d  \n", arr[x]->name , a);
    if (b != 0 )
        printf("Second Student is %s with score %d \n", arr[y]->name , b);
    if (c != 0 )
        printf("Third Student is %s with score %d  \n", arr[z]->name , c);
    printf("************************************\n");
}
