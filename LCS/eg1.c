#include<stdio.h>
#include<math.h>
int main()
{
int x[4]={65,66,67,68};
int lenX=4;
int Xep,e,j,num1,upperBoundX;
upperBoundX=lenX-1;
Xep=pow(2,lenX)-1;
num1=1;
while(num1<=Xep)
{
for(e=upperBoundX;e>=0;e--)
{
j=num1>>e;
if(j&1)printf("%c ",x[3-e]);
}
printf("\n");
num1++;
}
return 0;
}