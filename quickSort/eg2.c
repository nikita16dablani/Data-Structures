#include<stdio.h>
#include<stdlib.h>
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
}
}
return f;
}
void quickSort(int *x,int lowerBound,int upperBound)
{
int *lbstack,*ubstack,top,size,pp,lb,ub;
size=(upperBound-lowerBound)+1;
lbstack=(int*)malloc(sizeof(int)*size);
ubstack=(int*)malloc(sizeof(int)*size);
top=size;
top--;
lbstack[top]=lowerBound;
ubstack[top]=upperBound;
while(top!=size)
{
lb=lbstack[top];
ub=ubstack[top];
top++;
pp=findPartitionPoint(x,lb,ub);
if(pp+1<ub)
{
top--;
lbstack[top]=pp+1;
ubstack[top]=ub;
}
if(lb<pp-1)
{
top--;
lbstack[top]=lb;
ubstack[top]=pp-1;
}
}
free(lbstack);
free(ubstack);
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