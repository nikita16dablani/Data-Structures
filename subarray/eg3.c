#include<stdio.h>
int main()
{
int x[6],largest,sum,e,f,y;
for(y=0;y<=5;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
largest=x[0];
e=0;
while(e<=5)
{
f=e+1;
sum=x[e];
while(f<=5)
{
sum=sum+x[f];
if(sum>largest)largest=sum;
f++;
}
e++;
}
printf("Largest sum is : %d",largest);
return 0;
}