#include<stdlib.h>
#include<stdio.h>
void bubbleSort(int *x,int size)
{
int e,m,f,g;
m=size-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(*(x+f)<*(x+e))
{
g=*(x+e);
*(x+e)=*(x+f);
*(x+f)=g;
}
e++;
f++;
}
m--;
}
}
int main()
{
int *x;
int y,j;
printf("Enter your requirement: ");
scanf("%d",&j);
if(j<=0)
{
printf("Invalid requirement\n");
return 0;
}
x=(int*)malloc(sizeof(int)*j);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers\n",j);
return 0;
}
for(y=0;y<j;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
bubbleSort(x,j);
for(y=0;y<j;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}