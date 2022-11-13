#include<stdio.h>
#include<math.h>
int main()
{
int y[3]={66,90,68};
int lenY=3;
int Yep,e,j,num2,upperBoundY;
upperBoundY=lenY-1;
Yep=pow(2,lenY)-1;
num2=1;
while(num2<=Yep)
{
for(e=upperBoundY;e>=0;e--)
{
j=num2>>e;
if(j&1)printf("%c ",y[upperBoundY-e]);
}
printf("\n");
num2++;
}
return 0;
}