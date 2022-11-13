#include<stdio.h>
#include<stdlib.h>
int main()
{
int x[10],y,largest,size,num,n;
int *arr;
for(y=0;y<=9;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
largest=x[0];
for(y=1;y<=9;y++)
{
if(x[y]>largest)
{
largest=x[y];
}
}
size=largest+1;
arr=(int *)malloc(sizeof(int)*size);
if(arr==NULL)
{
printf("Unable to allocate memory for %d numbers",size);
return 0;
}
for(y=0;y<size;y++)
{
arr[y]=0;
}
for(y=0;y<=9;y++)
{
num=x[y];
arr[num]++;
}
n=0;
for(y=0;y<size;y++)
{
num=arr[y];
while(num>0)
{
x[n]=y;
n++;
num--;
}
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}