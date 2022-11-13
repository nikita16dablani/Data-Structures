#include<stdio.h>
int main()
{
int x[10],g,j,i;
for(i=0;i<=9;i++)
{
printf("Enter a number: ");
scanf("%d",&x[i]);
}
j=0;
while(j<=9)
{
if(j==0)j++;
if(x[j]<x[j-1])
{
g=x[j];
x[j]=x[j-1];
x[j-1]=g;
j--;
}
else
{
j++;
}
}
for(i=0;i<=9;i++)
{
printf("%d\n",x[i]);
}
return 0;
}