#include<stdlib.h>
#include<stdio.h>
int main()
{
int *x,y,i,z,num,req;
printf("Enter your requirement: ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int*)malloc(sizeof(int)*req);
for(i=0;i<req;i++)
{
printf("Enter a number: ");
scanf("%d",&x[i]);
}
y=1;
while(y<=req-1)
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
for(i=0;i<req;i++)
{
printf("%d\n",x[i]);
}
return 0;
}