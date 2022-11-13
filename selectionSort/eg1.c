#include<stdio.h>
int main()
{
int x[10],y,e,f,g,si;
for(y=0;y<=9;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
e=0;
while(e<=8)
{
si=e;
f=e+1;
while(f<=9)
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
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}