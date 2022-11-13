#include<stdio.h>
int main()
{
int num1,num2,hcf,e,f,remainder;
printf("Enter first number: ");
scanf("%d",&num1);
printf("Enter second number: ");
scanf("%d",&num2);
if(num1>num2)
{
e=num1;
f=num2;
}
else
{
e=num2;
f=num1;
}
remainder=1;
while(remainder>0)
{
remainder=e%f;
e=f;
f=remainder;
if(remainder==0)
{
hcf=e;
}
}
printf("HCF is %d",hcf);
return 0;
}


