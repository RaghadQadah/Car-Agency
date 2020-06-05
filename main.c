/*
Raghad Qadah 1170142
Car Agency Project
*/



#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "CarList.h"//library implementing a linked list
#include "queue.h"//library implementing a queue
#include "Stack.h"//library implementing a stack

struct cars* readFromCarsFiles(struct  cars*start);
void  readOrders(struct Queue*q);
void  displayCars();
void  displayQueue(struct QNode*q);
void SaveSales(struct Stack* top);
struct Stack* readSales(struct Stack*top);
void ServeOrders(struct  cars*,struct Queue*q,int day,int month,int year);
void UpdateOrders(struct QNode*start);
void readDate();
struct cars*carptr;
struct  Queue* customerptr;
struct Queue *unservedQ;
struct Queue *OrderQ;
int main()
{


    unservedQ=createQueue();
    top=readSales(top);//read pld sales
    while(1)
    {
        printf("\n\t\t\t\t ...Car Agency...\n");
        printf("1-Load Cars and Orders\n2-Show car inventory\n3-Serve orders\n4-show Unserved orders\n5-Show last sold car\n6-Add new Order\n7-Add new Car\n8-Update orders and car information\n9-Exist\n");
        printf("\n\nEnter your opreation\n");
        int x ;
        scanf("%d",&x);
        switch(x)
        {
        //Load Cars and Orders
        case 1:
            system("clear");
            start_cars =(struct  cars*)malloc(sizeof(struct  cars ));
            start_cars= readFromCarsFiles(start_cars );
            OrderQ=createQueue();
            readOrders(OrderQ);
            printf("Load the list of cars And load the Customer orders \n ");
            printf("\nenter 1 to return to the Menu\n");
            int x;
            scanf("%d",&x);
            if(x==1);
            system("clear");
           break;
           //Show car inventory
        case 2:
            system("clear");
            displayCars();
            printf("\nenter 1 to return to the Menu\n");
            int y;
            scanf("%d",&y);
            if(y==1);
            system("clear");
            break;
        //Serve orders
        case 3:
            system("clear");
           // ServeOrders(start_cars,OrderQ,9,9,1999);
            readDate();
            printf("\nenter 1 to return to the Menu\n");
            int z;
            scanf("%d",&z);
            if(z==1);
            system("clear");
            break;
            //show Unserved orders
        case 4:
            system("clear");
            displayQueue(unservedQ->Front);
            printf("\nenter 1 to return to the Menu\n");
            int a;
            scanf("%d",&a);
            if(a==1);
            system("clear");
            break;
           // Show last sold car
        case 5:
            system("clear");
            Top();
            printf("\nenter 1 to return to the Menu\n");
            int b;
            scanf("%d",&b);
            if(b==1);
            system("clear");
            break;
            //Add new Order
        case 6:
            system("clear");
             if(!OrderQ||!start_cars){
            printf("Error<Cars and Orders not loaded>\n");
            printf("\nenter 1 to return to the Menu\n");
            int l;
            scanf("%d",&l);
            if(l==1);
            system("clear");
            break;
            return;
            }
            char Name[30];
            int Id;
            int Phone;
            char CarManufacturer[40];
            char Model[30];
            char color[30];
            printf("Enter\n1-Name\n2-Id\n3-Phone\n4-CarManufacturer\n5-Model\n6-Color\n");
            scanf("%s\n%d\n%d\n%s\n%s\n%s",Name,&Id,&Phone,CarManufacturer,Model,color);
            Enqueue(OrderQ,Name,Id,Phone,CarManufacturer,Model,color);

            printf("\nenter 1 to return to the Menu\n");
            int c;
            scanf("%d",&c);
            if(c==1);
            system("clear");
            break;
          //  Add new Car
        case 7:
            system("clear");
            if(!OrderQ||!start_cars){
            printf("Error<Cars and Orders not loaded>\n");
            printf("\nenter 1 to return to the Menu\n");
            int u;
            scanf("%d",&u);
            if(u==1);
            system("clear");
            break;
            }
            start_cars= insert_first(start_cars );
            printf("\nenter 1 to return to the Menu\n");
            int w;
            scanf("%d",&w);
            if(w==1);
            system("clear");
            break;
          //  Update orders and car information
        case 8:
            system("clear");
            if(!OrderQ||!start_cars){
            printf("Error<Cars and Orders not loaded>\n");
             printf("\nenter 1 to return to the Menu\n");
            int i;
            scanf("%d",&i);
            if(i==1);
            system("clear");
            break;
            return;
            }
            UpdateOrders(OrderQ->Front);
            UpdateCars(start_cars);
            printf("Updated\n");
            printf("\nenter 1 to return to the Menu\n");
            int d;
            scanf("%d",&d);
            if(d==1);
            system("clear");
            break;
         // exit
        case 9:
            return 0;
            break;
        default:
            system("clear");
            printf("wrong input\n");
            printf("enter 1 to return to the Menu\n");
            int f;
            scanf("%d",&f);
            if(f==1);
            system("clear");

        }


    }

    return 0;
}

struct cars* readFromCarsFiles(struct  cars*start)//read cars from file and stor in linked list
{

    struct  cars *new_node,*carptr;
    carptr=start;
    char*p;
    int i=0;
    char words[5][30];
    char str[1000];
    FILE*carsFile;
    carsFile=fopen("cars.dat", "r");
    if(carsFile==NULL)
    {
        printf(" cars file not found ");
        return;
    }

    while (fgets(str, sizeof(str), carsFile) != NULL)
    {
        i=0;
        p=strtok(str,",");
        while(p!=NULL)
        {
            strcpy(words[i],p);
            i++;
            p=strtok(NULL,",");
        }
        new_node = (struct  cars*)malloc(sizeof(struct  cars));
        strcpy(new_node->manufacturer,words[0]);
        strcpy(new_node->model,words[1]);
        new_node->year=atoi(words[2]);
        strcpy(new_node->color,words[3]);
        new_node->price=atoi(words[4]);

        while(carptr->next!=NULL)
        {
            carptr=carptr->next;
        }
        carptr->next=new_node;
        new_node -> next = NULL;

    }
    fclose(carsFile);
    return start;
}

void readOrders(struct Queue*q)//load the Customer orders, which will be served in a queue
{

    struct Queue*new_node,*customerptr;

    char*p;
    int i=0;
    char words[5][30];
    char str[1000];
    FILE*customerFile;
    customerFile=fopen("orders.dat", "r");
    if(customerFile==NULL)
    {
        printf(" orders file not found ");
        return;
    }
    while (fgets(str, sizeof(str), customerFile) != NULL)
    {
        i=0;
        p=strtok(str,",");
        while(p!=NULL)
        {
            strcpy(words[i],p);
            i++;
            p=strtok(NULL,",");
        }
        struct QNode*new_node;
        new_node=newNode(words[0],atoi(words[1]),atoi(words[2]),words[3],words[4],words[5]);
        if(q->Rear==NULL)
        {
            q->Front=new_node;
            q->Rear=new_node;
        }
        else
        {
            q->Rear->next=new_node;
            q->Rear=new_node;

        }
    }

    fclose(customerFile);
}

void  displayCars()//print the car inventory (the existing cars).
{
    if(!start_cars)
    {
        printf("Error<No loaded car>\n");
        return;
    }
    if(start_cars->next==NULL)
    {
        printf("No Cars\n ");
        return;
    }
    carptr=start_cars->next;
    printf(".......Cars.......\n");
    while(carptr!=NULL)
    {
        printf("\nManufacturer:%s\nModel:%s\n Year:%d\nColour:%s\nPrice:%d\n\n",carptr->manufacturer,carptr->model,carptr->year,carptr->color,carptr->price);
        carptr=carptr->next;
    }
}

void  displayQueue(struct QNode*start)//display the list of orders
{
    if(!start)
    {
        printf("error <serve order not startred>\n");
        return;
    }
    struct QNode*ptr=start;
    printf(".....Orders.........\n");
    while(ptr!=NULL)
    {
        printf("\nname: %s\nId:%d\nPhone: %d\nCarManfucterer: %s\nModel: %s\ncolor: %s\n",ptr->name,ptr->id,ptr->phone,ptr->carManufacturer,ptr->model,ptr->color);
        ptr=ptr->next;
    }
}

void ServeOrders(struct  cars*start_car,struct Queue*q,int day,int month,int year)
{
    if(!q)
    {
        printf("Erorr<No loaded orders\n");
        return;
    }
    if(!start_car->next)
    {
        printf("No Cars\n");
        return;
    }

    unservedQ = createQueue();
    struct CustomerOrders*temp;
    struct  cars*car_ptr;
    struct QNode*order_ptr;

    car_ptr=start_car;
    order_ptr=q->Front;
    if(q->Front==NULL&&q->Rear==NULL)
    {
        printf("No Orders\n");
        return;
    }

    while(order_ptr!=NULL)
    {
        car_ptr=start_car;
        while(car_ptr!=NULL)
        {
            if((strcmp(car_ptr->manufacturer,order_ptr->carManufacturer)==0)&&(strcmp(car_ptr->model,order_ptr->model)==0))
                break;
            car_ptr=car_ptr->next;
        }

        if(car_ptr!=NULL)
        {
            push(order_ptr->name,order_ptr->id,order_ptr->phone,car_ptr->manufacturer,car_ptr->model,car_ptr->color,car_ptr->price,day,month,year);
            start_car=delete_value(start_car,car_ptr->manufacturer,car_ptr->model);
            Dequeue(q);
          //  printf("1\n");
        }
        else
        {
            //  temp=getFront();
            // printf("%s\t",temp->name);
          //  printf("2\n");
            Enqueue(unservedQ,order_ptr->name,order_ptr->id,order_ptr->phone,order_ptr->carManufacturer,order_ptr->model,order_ptr->color);
            Dequeue(q);
            //  Enqueue(unservedFront,unservedRear,temp->name,temp->id,temp->phone,temp->carManufacturer,temp->model,temp->color);
        }
        order_ptr=order_ptr->next;
        // printf("%s\t",order_ptr->name);
    //    printf("3\n");
    }
 //   printf("4\n");
    SaveSales( top);
  //  printf("5\n");
    OrderQ=unservedQ;
   //  printf("6\n");
   // UpdateOrders(OrderQ->Front);
    // printf("7\n");
   //  UpdateCars(start_car);
    // printf("8\n");

}

void SaveSales(struct Stack* top)
{
    FILE*SalesFile;
    SalesFile=fopen("sales","w");


    struct Stack *current;
    current = top;
    if(current!= NULL)
    {
        do
        {

            fprintf(SalesFile,"%s,%d,%d,%s,%s,%s,%d,%d/%d/%d\n",current->name,current->id,current->phone,current->carManufacturer,current->model,current->color,current->cost,current->date.day,current->date.month,current->date.year);
            current = current->next;
        }
        while (current!= NULL);
        printf("\n");
    }
    fclose(SalesFile);
}

struct Stack* readSales(struct Stack*top)
{

    char*p;
    char*q;
    int i=0;
    int j=0;
    char words[5][30];
    char str[1000];
    FILE*File;
    File=fopen("sales","r");
    if(File==NULL)
    {
        printf(" Sales file not found ");
        return;
    }

    while (fgets(str, sizeof(str), File) != NULL)
    {
        i=0;
        p=strtok(str,",");
        while(p!=NULL)
        {
            strcpy(words[i],p);
            i++;
            p=strtok(NULL,",");
        }
        if (top == NULL)
        {
            top =(struct Stack*)malloc(sizeof(struct Stack));
            top->next = NULL;
            strcpy(top->name,words[0]);
            top->id=atoi(words[1]);
            top->phone=atoi(words[2]);
            strcpy(top->carManufacturer,words[3]);
            strcpy(top->model,words[4]);
            strcpy(top->color,words[5]);
            top->cost=atoi(words[6]);
         //   printf("%s\n",words[7]);
            top->date.day=atoi(strtok(words[7],"/"));
            top->date.month=atoi(strtok(NULL,"/"));
            top->date.year=atoi(strtok(NULL," "));
        }
        else
        {
            struct Stack*temp;
            temp =(struct Stack*)malloc(sizeof(struct Stack));
            temp->next = top;
            strcpy(temp->name,words[0]);
            temp->id=atoi(words[1]);
            temp->phone=atoi(words[2]);
            strcpy(temp->carManufacturer,words[3]);
            strcpy(temp->model,words[4]);
            strcpy(temp->color,words[5]);
            temp->cost=atoi(words[6]);
            temp->date.day=atoi(strtok(words[7],"/"));
            temp->date.month=atoi(strtok(NULL,"/"));
            temp->date.day=atoi(strtok(NULL," "));
            top = temp;
        }

    }
    struct Stack*ptr,*prevptr,*nextptr;
    ptr=top;
    prevptr =NULL;
    nextptr=NULL;
    while(ptr!=NULL)
    {
        nextptr = ptr->next;
        ptr->next =prevptr;
        prevptr=ptr;
        ptr = nextptr;
    }
    top=prevptr;
    fclose(File);
    return top;
}



void UpdateOrders(struct QNode*start)//update the input files  the orders that have been served.
{
    if(!start){
    printf("Error\n");
    return;
    }
    FILE*File;
    File=fopen("orders.dat","w");

    struct QNode*ptr=start;
    while(ptr!=NULL)
    {
        fprintf(File,"%s,%d,%d,%s,%s,%s",ptr->name,ptr->id,ptr->phone,ptr->carManufacturer,ptr->model,ptr->color);
        ptr=ptr->next;
    }

    fclose(File);
}

void readDate()//read date of serving
{

    int day;
    int month;
    int year;
    char a,b;
    printf("Enter the date of serving\n");
    scanf("%d%c%d%c%d",&day,&a,&month,&b,&year);
    if((day>0&&day<=31)&&(month>0&&month<=12)&&(year>=2019))
    {
       ServeOrders(start_cars,OrderQ,day,month,year);//if valid date start serve
    }
    else{
        printf("invalid date\n");
        readDate();//if invalid date call function again
    }

}






