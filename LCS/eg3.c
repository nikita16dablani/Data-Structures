#include<stdio.h>
#include<math.h>
int main()
{
int x[4]={65,66,67,68};
int tmp1[4];
int tmp1i;
int lenX=4;
int Xep,e,j,num1,upperBoundX;

int y[3]={66,90,68};
int tmp2[3];
int tmp2i;
int lenY=3;
int Yep,num2,upperBoundY;

upperBoundX=lenX-1;
Xep=pow(2,lenX)-1;

upperBoundY=lenY-1;
Yep=pow(2,lenY)-1;

num1=1;
while(num1<=Xep)
{
tmp1i=0;
for(e=upperBoundX;e>=0;e--)
{
j=num1>>e;
if(j&1)
{
tmp1[tmp1i]=x[upperBoundX-e];
tmp1i++;
}
}
//for testing
//for(e=0;e<tmp1i;e++)printf("%c ",tmp1[e]);
//printf("\n");
//one subsequence of x array is in tmp1array
//logic to search the tmp1 in all possible sub sequences of y array starts here
num2=1;
while(num2<=Yep)
{
tmp2i=0;
for(e=upperBoundY;e>=0;e++)
{
j=num2>>e;
if(j&1)
{
tmp2[tmp2i]=y[upperBoundY-e];
tmp2i++;
}
}
//a subsequence of y array is ready in tmp2,we need to compare it tmp1
if(tmp1i==tmp2i)
{
for(e=0;e<tmp1i;e++)
{
if(tmp1[e]!=tmp2[e])break;
}
if(e==tmp1i)
{
for(e=0;e<tmp1i;e++)printf("%c ",tmp1[e]);
printf("\n");
break;
}
}
num2++;
}
//logic to search the tmp1 in all possible sub sequences of y array ends here
num1++;
}
return 0;
}