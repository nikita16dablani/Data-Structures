#include<stdio.h>
#include<stdlib.h>
void binaryInsertionSort(int *x,int lb,int ub)
{
int size,i,num,z,si,ei,mid;
size=ub-lb+1;
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
binaryInsertionSort(x,0,i-1);
for(y=0;y<i;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
} 