#include<string.h>
#include<stdlib.h>
#include<stdio.h>
void selectionSort(void *ptr,int cs,int es,int (*p2f)(void*,void*))
{
int w,e,f,si,oep,iep;
void *a,*b,*c;
c=(void*)malloc(es);
e=0;
oep=cs-2;
iep=cs-1;
while(e<=oep)
{
si=e;
f=e+1;
while(f<=iep)
{
a=ptr+(f*es);
b=ptr+(si*es);
w=p2f(a,b);
if(w<0)
{
si=f;
}
f++;
}
a=ptr+(e*es);
b=ptr+(si*es);
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
e++;
}
free(c);
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
int *x,y,req;
printf("Enter your requirement: ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid input\n");
return 0;
}
x=(int*)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory for %d numbers\n",req);
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
selectionSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++)
{
printf("%d\n",x[y]);
}
return 0;
}