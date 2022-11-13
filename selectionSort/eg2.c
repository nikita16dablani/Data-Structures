#include<stdlib.h>
#include<stdio.h>
int main()
{
int *x,e,f,g,si,y,req;
printf("Enter your requirement: ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid input\n");
return 0;
}
x=(int*)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers\n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
e=0;
while(e<req-2)
{
si=e;
f=e+1;
while(f<req-1)
{
if(x[f]<x[si])
{
si=f;
}
f++;
}
g=x[e];
x[e]=x[si];
x[si]=g;
e++;
}
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}