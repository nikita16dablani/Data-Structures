#include<stdio.h>
int main()
{
int x[10],i,swapCount,e,f,g;
for(i=0;i<=9;i++)
{
printf("Enter a Number: ");
scanf("%d",&x[i]);
}
while(1)
{
swapCount=0;
e=1;
f=e+1;
while(e<=7)
{
if(x[f]<x[e])
{
swapCount=1;
g=x[e];
x[e]=x[f];
x[f]=g;
}
e=e+2;
f=f+2;
}
e=0;
f=e+1;
while(e<=8)
{
if(x[f]<x[e])
{
swapCount=1;
g=x[e];
x[e]=x[f];
x[f]=g;
}
e=e+2;
f=f+2;
}
if(swapCount==0)
{
break;
}
}
for(i=0;i<=9;i++)
{
printf("%d\n",x[i]);
}
return 0;
}