#include<stdio.h>
int main()
{
int x[10],y,i,z,num;
for(i=0;i<=9;i++)
{
printf("Enter a number: ");
scanf("%d",&x[i]);
}
y=1;
while(y<=9)
{
num=x[y];
z=y-1;
while(z>=0 && x[z]>num)
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
y++;
}
for(i=0;i<=9;i++)
{
printf("%d\n",x[i]);
}
return 0;
}