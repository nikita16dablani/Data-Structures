#include<stdio.h>
#include<stdlib.h>
int main()
{
int *x,e,f,g,y,req,iep,oep;
printf("Enter your requirement: ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
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
oep=req-2;
iep=req-1;
for(e=0;e<oep;e++)
{
for(f=e+1;f<iep;f++)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
}
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}