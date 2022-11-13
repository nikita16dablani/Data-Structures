#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void insertionSort(void *ptr,int cs,int es,int (*p2f)(void*,void*))
{
int y,z,w;
void *a,*b,*num;
y=1;
while(y<=cs-1)
{

a=ptr+(y*es);
memcpy(num,(const void*)a,es);
z=y-1;
b=ptr+(z*es);
w=p2f(b,num);
while(z>=0 && w>0)
{
a=ptr+((z+1)*es);
b=ptr+(z*es);
memcpy(a,(const void*)b,es);
z--;
}
a=ptr+((z+1)*es);
b=ptr+(num*es);
memcpy(a,(const void*)b,es);
y++;
}
}
int myComparator(void* left,void* right)
{
int *i,*j;
i=(int*)left;
j=(int*)right;
return (*i)-(*j);
}
int main()
{
int *x,i,req;
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
insertionSort(x,req,sizeof(int),myComparator);
for(i=0;i<req;i++)
{
printf("%d\n",x[i]);
}
return 0;
}