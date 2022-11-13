#include<stdio.h>
#include<stdlib.h>
void stoogeSort(int *x,int lb,int ub)
{
int g,size,i;
size=ub-lb+1;
if(x[lb]>x[ub])
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
}
if(size>2)
{
i=size/3;
stoogeSort(x,lb,ub-i);
stoogeSort(x,lb+i,ub);
stoogeSort(x,lb,ub-i);
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
stoogeSort(x,0,i-1);
for(y=0;y<i;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
} 