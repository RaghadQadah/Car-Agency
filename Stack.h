struct node_time
{
    int day ;
    int month;
    int year ;
};

struct Stack
{
    char name [50];
    int id;
    int phone  ;
    char carManufacturer[20];
    char model [50];
    char color[20];
    int cost;
    struct node_time date;
    struct Stack* next ;
};

void push(char name [],int id,int phone,char carManufacturer[],char model [],char color[],int cost,int day,int month,int year);
void Pop();
void Top();
struct Stack* top=NULL;



void push(char Name [],int Id,int Phone,char CarManufacturer[],char Model [],char Color[],int Cost,int day,int month,int year)
{

    if (top == NULL)
    {
        top =(struct Stack*)malloc(sizeof(struct Stack));
        top->next = NULL;
        strcpy(top->name,Name);
        top->id=Id;
        top->phone=Phone;
        strcpy(top->carManufacturer,CarManufacturer);
        strcpy(top->model,Model);
        strcpy(top->color,Color);
        top->cost=Cost;
        top->date.day=day;
        top->date.month=month;
        top->date.year=year;
    }
    else
    {
        struct Stack*temp;
        temp =(struct Stack*)malloc(sizeof(struct Stack));
        temp->next = top;
        strcpy(temp->name,Name);
        temp->id=Id;
        temp->phone=Phone;
        strcpy(temp->carManufacturer,CarManufacturer);
        strcpy(temp->model,Model);
        strcpy(temp->color,Color);
        temp->cost=Cost;
        temp->date.day=day;
        temp->date.month=month;
        temp->date.year=year;
        top = temp;
    }
}


void Pop()
{
    struct Stack*temp;
    temp = top;

    if (temp == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
    {
        temp = temp->next;
        free(top);
        top = temp;
    }
}

void Top()
{

    if(top!=NULL)
    {
        printf("........Last sold Car...........\n ");
        printf("\nname:%s\nId:%d\nPhone:%d\nCarManfucterer:%s\nModel:%s\ncolor:%s\ncost:%d\ndate:%d/%d/%d\n",top->name,top->id,top->phone,top->carManufacturer,top->model,top->color,top->cost,top->date.day,top->date.month,top->date.year);
    }
    else
    {
        printf("No sold Cars\n");
    }
}
















