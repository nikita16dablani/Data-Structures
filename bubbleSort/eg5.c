#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void bubbleSort(void *ptr,int cs,int es,int(*p2f)(void*,void*))
{
int e,f,m,w;
void *a,*b,*c;
c=(void *)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
e++;
f++;
}
m--;
}
}
int myComparator(void *left,void *right)
{
int *i,*j;
i=(int*)left;
j=(int*)right;
return (*i)-(*j);
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
bubbleSort(x,j,sizeof(int),myComparator);
for(y=0;y<j;y++)
{
printf("%d\n",x[y]);
}
free(x);
return 0;
}