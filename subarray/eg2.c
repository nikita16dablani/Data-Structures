#include<stdio.h>
int main()
{
int lmax,gmax,i,y,x[6];
for(y=0;y<=5;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
i=1;
lmax=x[0];
gmax=x[0];
while(i<=5)
{
y=lmax+x[i];
if(x[i]>y)
{
lmax=x[i];
}
else
{
lmax=y;
}
if(lmax>gmax)
{
gmax=lmax;
}
else
{
gmax=gmax;
}
i++;
}
printf("Largest is %d",gmax);
return 0;
}