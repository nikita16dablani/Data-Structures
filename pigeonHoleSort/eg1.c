#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
int main()
{
int x[10],y,i,size,largest,smallest,range,lb,ub,data,index;
struct node **list;
struct node *temp,*t;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
lb=0;
ub=9;
size=ub-lb+1;
largest=x[lb];
smallest=x[lb];
for(y=lb+1;y<size;y++)
{
if(largest<x[y])largest=x[y];
if(smallest>x[y])smallest=x[y];
}
range=largest-smallest+1;
list=(struct node **)malloc(sizeof(struct node *)*range);
for(y=0;y<range;y++)
{
list[y]=NULL;
}
for(y=lb;y<size;y++)
{
index=x[y]-smallest;
data=x[y];
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;	
if(list[index]==NULL)
{
temp->next=list[index];
list[index]=temp;
}
else
{
t=list[index];
while(t->next!=NULL && t->next->data<data)
{
t=t->next;
}
temp->next=t->next;
t->next=temp;
}
}
i=0;
for(y=0;y<range;y++)
{
while(list[y]!=NULL)
{
x[i]=list[y]->data;
list[y]=list[y]->next;
i++;
}
}
free(list);
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}

