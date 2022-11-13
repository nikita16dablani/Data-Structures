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
int main()
{
int x[10],y,e,f,i,num,largest,dc,k,lb,ub,flag;
Queue queues[10];
for(i=0;i<=9;i++) initQueue(&queues[i]);
for(y=0;y<=9;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
flag=0;
for(y=0-1,i=0;i<=9;i++)
{
if(x[i]<0)
{
flag=1;
y++;
if(y==i)
{
x[y]*=-1;
}
else
{
num=x[y];
x[y]=(-1)*x[i];
x[i]=num;
}
}
}
if(y>0)
{
ub=y;
lb=0;
largest=x[lb];
for(y=1;y<=ub;y++)
{
if(x[y]>largest)largest=x[y];
}
dc=1;
num=largest;
while(num>9)
{
num=num/10;
dc++;
}
e=10;
f=1;
k=1;
while(k<=dc)
{
//spread out 10 queues acc to digit at kth place
y=lb;
while(y<=ub)
{
num=x[y];
i=(num%e)/f;
addToQueue(&queues[i],num);
y++;
}
//collect all numbers from 10 queues and keep it in array
i=0;
y=0;
while(y<=ub)
{
while(!isQueueEmpty(&queues[y]))
{
num=removeFromQueue(&queues[y]);
x[i]=num++;
i++;
}
y++;
}
e=e*10;
f=f*10;
k++;
}
}
for(e=lb,f=ub;e<=f;e++,f--)
{
num=(-1)*x[e];
x[e]=(-1)*x[f];
x[f]=num;
}
if(flag==0)
{
lb=0;
}
if(flag==1)
{
lb=ub+1;
}
largest=x[lb];
for(y=lb+1;y<=9;y++)
{
if(x[y]>largest)largest=x[y];
}
dc=1;
num=largest;
while(num>9)
{
num=num/10;
dc++;
}
e=10;
f=1;
k=1;
while(k<=dc)
{
//spread out 10 queues acc to digit at kth place
y=lb;
i=0;
while(y<=9)
{
num=x[y];
i=(num%e)/f;
addToQueue(&queues[i],num);
y++;
}
//collect all numbers from 10 queues and keep it in array
i=lb;
y=0;
while(y<=9)
{
while(!isQueueEmpty(&queues[y]))
{
num=removeFromQueue(&queues[y]);
x[i]=num++;
i++;
}
y++;
}
e=e*10;
f=f*10;
k++;
}
for(y=0;y<=9;y++)printf("%d\n",x[y]);
return 0;
}