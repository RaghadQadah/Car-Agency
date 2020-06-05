
struct QNode
{
    char name [50];
    int id;
    int phone  ;
    char carManufacturer[20];
    char model [50];
    char color[20];
    struct QNode* next ;
};
struct Queue
{
    struct QNode *Front, *Rear;
};


void Enqueue(struct Queue*q,char Name[],int Id,int Phone,char CarManufacturer[],char Model[],char Color[]);
void Dequeue(struct Queue*q);
void getFront(struct Queue*q);
struct Queue *createQueue();
struct QNode* newNode(char Name [],int Id,int Phone,char CarManufacturer[],char Model [],char Color[]);


void Enqueue(struct Queue*q,char Name[],int Id,int Phone,char CarManufacturer[],char Model[],char Color[])
{
    struct QNode*new_node;
    new_node=newNode(Name,Id,Phone,CarManufacturer,Model,Color);
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


void Dequeue(struct Queue*q)
{
    struct QNode* temp;
    temp = q->Front;
    if (q->Front == NULL)
    {
        printf("Underflow\n");
        return;
    }
    if (temp->next != NULL)
    {
        temp = temp->next;
        free(q->Front);
        q->Front = temp;
    }
    else
    {

        free(q->Front);
        q->Front = NULL;
        q->Rear = NULL;
    }
}
void getFront(struct Queue*q)
{
    if ((q->Front != NULL) && (q->Rear != NULL))
    {
        printf("\nname:%s\nId:%d\nPhone:%d\nCarManfucterer:%s\nModel:%s\ncolor:%s\n\n",q->Front->name,q->Front->id,q->Front->phone,q->Front->carManufacturer,q->Front->model,q->Front->color);

    }
    else
    {
        printf("Error >> empty queue\n");

    }

}
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->Front =NULL;
    q->Rear = NULL;
    return q;
}

struct QNode* newNode(char Name [],int Id,int Phone,char CarManufacturer[],char Model [],char Color[])
{
    struct QNode*new_node = (struct QNode*)malloc(sizeof(struct QNode));
    strcpy(new_node->name,Name);
    new_node->id=Id;
    new_node->phone=Phone;
    strcpy(new_node->carManufacturer,CarManufacturer);
    strcpy(new_node->model,Model);
    strcpy(new_node->color,Color);
    new_node->next = NULL;
    return new_node;
}







