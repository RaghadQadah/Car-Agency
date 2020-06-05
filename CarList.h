
struct cars
{
    char manufacturer [50];
    char model [50];
    int year ;
    char color[20];
    int price ;
    struct cars* next ;
};

struct cars* insert_first(struct cars*start_cars );
struct cars* insert_last(struct cars*start_cars );
struct cars* delete_first(struct cars*start_cars );
struct cars* delete_last(struct cars*start_cars );
//struct cars* update(struct  cars*start);
void UpdateCars(struct  cars*start);
struct cars* delete_value(struct cars*start_cars,char manufacturer[],char model[] );
void Find(struct  cars*start);


struct cars* start_cars;

struct cars* insert_first(struct cars*start_cars)
{
    if(!start_cars)
    {
        ("Error <you should load existing cars from file befor add new car\n ");
        return 0;
    }
    struct  cars *new_node;
    new_node = (struct  cars*)malloc(sizeof(struct  cars ));
    printf(" Enter the car information \n 1-Manufacturer \n 2-Model  \n 3-Year \n 4-color  \n 5-Price \n ");
    scanf("%s\n%s\n%d\n%s\n%d",new_node->manufacturer,new_node->model,&new_node->year,new_node->color,&new_node->price );
    new_node -> next = start_cars->next;
    start_cars->next = new_node;
    return start_cars;
}
struct cars* insert_last(struct cars*start_cars )
{
    struct  cars *new_node,*carptr;
    new_node = (struct  cars*)malloc(sizeof(struct  cars ));
    printf(" Enter the car information \n 1-Manufacturer \n 2-Model  \n 3-Year \n 4-color  \n 5-Price \n ");
    scanf("%s\n%s\n%d\n%s\n%d",new_node->manufacturer,new_node->model,&new_node->year,new_node->color,&new_node->price );
    // scanf("%s",new_node->model);
    new_node->next=NULL;
    carptr=start_cars;
    while(carptr->next!=NULL)
    {
        carptr=carptr->next;
    }
    carptr->next=new_node;
    return start_cars;
}



void UpdateCars(struct  cars*start)
{
    if(!start){
    printf("Error\n");
    return;
    }
    FILE*File;
    File=fopen("cars.dat","w");
    struct  cars *current;
    current = start->next;
    if(current!= NULL)
    {
        do
        {
            // printf("raghad");
            fprintf(File,"%s,%s,%d,%s,%d\n",current->manufacturer,current->model,current->year,current->color,current->price);
            //fprintf(File,"%s,%d,%d,%s,%s,%s,%d\n",current->manufacturer,current->id,current->phone,current->carManufacturer,current->model,current->color,current->cost);
            current = current->next;
        }
        while (current!= NULL);
        printf("\n");
    }
    fclose(File);
}




struct cars* delete_first(struct cars*start_cars )
{
    struct cars*carptr;
    carptr=start_cars;
    start_cars = start_cars -> next;
    free(carptr);
    return start_cars;

}

struct cars* delete_last(struct cars*start_cars )
{
    struct cars*carptr,*preptr;
    carptr = start_cars;
    while(carptr -> next != NULL)
    {
        preptr = carptr;
        carptr = carptr -> next;
    }
    preptr -> next = NULL;
    free(carptr);
    return start_cars;
}

void Find(struct  cars*start)
{
    struct  cars*carptr;
    carptr=start;
    char Manufacturer[30];
    char Model[30];
    printf("Enter Car Information\n");
    printf("...............................\n");
    printf("enter the Manufacturer of car  \n ");
    scanf("%s",Manufacturer);
    printf("enter the model of car  \n ");
    scanf("%s",Model);



    while(carptr!=NULL)
    {
        if((strcmp(carptr->manufacturer,Manufacturer)==0)&&(strcmp(carptr->model,Model)==0))
        break;
        carptr=carptr->next;
    }

    if(carptr==NULL)
    {
        printf("\n Car not exist\n ");
        return ;
    }
   else{
       printf("\nCar Information\n ");
       printf("Manufacturer:%s\nModel:%s\n Year:%d\nColour:%s\nPrice:%d\n\n",carptr->manufacturer,carptr->model,carptr->year,carptr->color,carptr->price);
  }

}

struct cars *delete_value(struct  cars*start,char manufacturer[],char model[])
{

    struct cars* carptr,*before;
    carptr = start;
    before = start;
    if((strcmp(carptr->manufacturer,manufacturer)==0)&&(strcmp(carptr->model,model)==0))
    {
        start = start -> next;
        free(carptr);
       // printf("deleted\n");
       return start;
    }
    else
    {
        while( carptr!=NULL)
        {


            if((strcmp(carptr->manufacturer,manufacturer)==0)&&(strcmp(carptr->model,model)==0))
            {
                before->next=carptr->next;
                free(carptr);
               // printf("\n deleted\n");
                break;
            }
            before=carptr;
            carptr=carptr->next;
        }
// iterated on all of cars s and not exist
        if(carptr==NULL)
        {
            printf(" Car not exist\n ");
        }
    }

    return start;
}

