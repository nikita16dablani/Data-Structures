#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[7],y,flag,lb,ub,g,e,f;
for(y=0;y<=6;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
lb=0;
ub=6;
flag=1;
while(flag==1)
{
flag=0;
e=lb;
f=e+1;
while(f<=ub)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
flag=1;
}
e++;
f++;
}
if(flag==0) break;
flag=0;
ub--;
e=ub-1;
f=ub;
while(e>=lb)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
flag=1;
}
e--;
f--;
}
lb++;
}
for(y=0;y<=6;y++)
{
printf("%d\n",x[y]);
}
return 0;
} 