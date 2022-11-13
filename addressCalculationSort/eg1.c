#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node **buckets;
int hashFunction(int num,int count)
{
int i=1;
while(i<count)
{
num=num/10;
i++;
}
return num;
}
void insertIntoBucket(int data,int address)
{
struct node *temp,*t;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
if(buckets[address]==NULL || data<buckets[address]->data)
{
temp->next=buckets[address];
buckets[address]=temp;
return;
}
else
{
t=buckets[address];
while(t->next!=NULL && t->next->data<data)
{
t=t->next;
}
temp->next=t->next;
t->next=temp;
}
}
void addressCalculationSort(int *x,int lb,int ub)
{
int y,size,largest,countOfLargest,num,address,i;
size=ub-lb+1;
buckets=(struct node **)malloc(sizeof(struct node *)*size);
for(y=lb;y<size;y++)
{
buckets[y]=NULL;
}
largest=x[lb];
for(y=lb+1;y<size;y++)
{
if(largest<x[y])largest=x[y];
}
countOfLargest=1;
num=largest;
while(num>9)
{
countOfLargest++;
num=num/10;
}
hashFunction(num,countOfLargest);
for(y=lb;y<size;y++)
{
num=x[y];
address=hashFunction(num,countOfLargest);
insertIntoBucket(num,address);
}
//copy back
i=0;
for(y=0;y<size;y++)
{
while(buckets[y]!=NULL)
{
x[i]=buckets[y]->data;
buckets[y]=buckets[y]->next;
i++;
}
}
free(buckets);
}


int main()
{
int *x,y,i;
printf("Enter requirement : ");
scanf("%d",&i);
if(i<0)
{
printf("Invalid requirement");
return 0;
}
x=(int *)malloc(sizeof(int)*i);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers",i);
return 0;
}
for(y=0;y<i;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
addressCalculationSort(x,0,i-1);
for(y=0;y<i;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}
