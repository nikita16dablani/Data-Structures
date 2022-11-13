#include<stdio.h>
int hcf_(int p,int q)
{
if(q==0)return p;
return hcf_(q,p%q);
}
int main()
{
int num1,num2,hcf,e,f;
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
hcf=hcf_(num1,num2);
lcm=(num1*num2)/hcf;
printf("HCF is %d",hcf);
return 0;
}


