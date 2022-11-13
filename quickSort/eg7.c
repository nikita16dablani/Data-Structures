#include<stdio.h>
#include<stdlib.h>
void quickSort(int *,int ,int );
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb])e++;
while(x[f]>x[lb])f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
break;
}
}
return f;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
int pp;
if(upperBound<=lowerBound)return;
pp=findPartitionPoint(x,lowerBound,upperBound);
quickSort(x,lowerBound,pp-1);
quickSort(x,pp+1,upperBound);
}
int main()
{
int req,y,*x;
printf("Enter your requirement: ");
scanf("%d",&req);
if(req<0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int*)malloc(sizeof(int)*req);
for(y=0;y<req;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
quickSort(x,0,req-1);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}