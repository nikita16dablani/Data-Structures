#include<stdio.h>
int main()
{
int x[10],lb,ub,y  ;
int size,i,num,z,si,ei,mid;
for(y=0;y<=9;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
size=ub-lb+1;
lb=0;
ub=9;
for(i=lb+1;i<size;i++)
{
num=x[i];
z=i-1;
si=lb;
ei=z;
while(si<=ei)
{
mid=si+((ei-si)/2);
if(num==x[mid])
{ 
si=mid;
break;
}
if(num<x[mid]) 
{
ei=mid-1;
}
else 
{
si=mid+1;
}
}
while(z>=si)
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}