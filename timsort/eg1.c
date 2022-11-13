#include<stdio.h>
#include<stdlib.h>
int minimum(int a, int b)  
{  
if(a<b) return a;   
else return b;   
}  
void insertionSort(int *x,int lb,int ub)
{
int y,z,num,size,ep;
size=ub-lb+1;
ep=size-1;
for(y=1;y<=ep;y++)
{
for(num=x[y],z=y-1;z>=0&&x[z]>num;z--)x[z+1]=x[z];
x[z+1]=num;
}
}

void merge(int *x,int lb1,int ub1,int lb2,int ub2)
{
int size1,size2,size3;
int *tmp;
int i1,i2,i3;
size1=(ub1-lb1)+1;
size2=(ub2-lb2)+1;
size3=size1+size2;
tmp=(int *)malloc(sizeof(int)*size3);
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
x[i1]=tmp[i3];
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
x[i2]=tmp[i3];
i2++;
i3++;
}
free(tmp);
}

void timSort(int *x,int lb,int ub)
{
int i,size,mid;  
size=ub-lb+1;
for(i=0;i<size;i+=62)  
{
insertionSort(x,i,minimum((i+61),(size-1)));  
}    
for(i=62;i<size;i=2*62)  
{  
for(lb=0;lb<size;lb+=2*i)  
{  
mid=lb+i-1;  
ub=minimum((lb+2*i-1),(size-1));  
merge(x,lb,mid,mid+1,ub);  
}  
}  
}
int main()
{
int x[100],y;

for(y=0;y<100;y++)
{
x[y]=rand();
}
timSort(x,0,100);
for(y=0;y<100;y++)
{
printf("%d\n",x[y]);
}
return 0;
} 