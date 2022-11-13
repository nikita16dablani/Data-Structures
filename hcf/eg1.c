#include<stdio.h>
int main()
{
int num1,num2,hcf,e;
printf("Enter first number: ");
scanf("%d",&num1);
printf("Enter second number: ");
scanf("%d",&num2);
e=1;
while(e<=num1 && e<=num2)
{
if(num1%e==0 && num2%e==0)
{
hcf=e;
}
e++;
}
printf("HCF is: %d",hcf);
return 0;
}