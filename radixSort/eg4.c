#include<stdio.h>
#include<stdlib.h>
typedef struct _queue_node
{
int num;
struct _queue_node *next;
}QueueNode;
typedef struct _queue
{
QueueNode *start;
QueueNode *end;
int size;
}Queue;
void initQueue(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
}
int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}
void addToQueue(Queue *queue,int num)
{
QueueNode *t;
t=(QueueNode*)malloc(sizeof(QueueNode));
t->num=num;
t->next=NULL;
if(queue->start==NULL)
{
queue->start=t;
queue->end=t;
}
else
{
queue->end->next=t;
queue->end=t;
}
queue->size++;
}
int removeFromQueue(Queue *queue)
{
int num;
QueueNode *t;
num=queue->start->num;
t=queue->start;
queue->start=queue->start->next;
if(queue->start==NULL)queue->end=NULL;
free(t);
queue->size--;
return num;
}
void clearQueue(Queue *queue)
{
QueueNode *t;
while(queue->start!=NULL)
{
t=queue->start;
queue->start=queue->start->next;
queue->size--;
free(t);
}
queue->end=NULL;
queue->size=0;
}
void radixSort(int *ptr,int lb,int ub)
{
int largest,size,dc,e,f,i,k,y,num,p;
Queue queues[10];
for(y=0;y<=9;y++) initQueue(&queues[y]);
for(y=lb-1,i=lb;i<=ub;i++)
{
if(ptr[i]<0)
{
y++;
if(y==i)
{
 ptr[y]*=-1;
}
else
{
num=ptr[y];
ptr[y]=(-1)*ptr[i];
ptr[i]=num;
}
}
}
for(p=0;p<=9;p++)printf("Hi i m arr %d\n",ptr[p]);
printf("*********************************************************");
if(y>lb) radixSort(ptr,lb,y);
for(e=lb,f=y;e<=f;e++,f--)
{
num=(-1)*ptr[e];
ptr[e]=(-1)*ptr[f];
ptr[f]=num;
}
if(y==ub) return;
lb=y+1;
largest=ptr[lb];
for(i=lb+1;i<=ub;i++) if(ptr[i]>largest) largest=ptr[i];
dc=1;
if(num<0) num*=-1;
while(num>9)
{
dc++;
num/=10;
}


e=10;
f=1;
k=1;
while(k<=dc)
{
y=lb;
while(y<=ub)
{
num=ptr[y];
i=(num%e)/f;
addToQueue(&queues[i],num);
y++;
}
i=lb;
y=0;
while(y<=9)
{
while(!isQueueEmpty(&queues[y]))
{
num=removeFromQueue(&queues[y]);
ptr[i]=num;
i++;
}
y++;
}
e*=10;
f*=10;
k++;
}
}
int main()
{
int x[10],y;
for(y=0;y<=9;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
radixSort(x,0,9);
for(y=0;y<=9;y++)printf("%d\n",x[y]);
return 0;
}