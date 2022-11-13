#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
long size,i;
FILE *file;
size=50;
srand(time(0));
file=fopen("data.d","wb");
while(ftell(file)<size)
{
i=rand();
printf("%ld\n",i);
fwrite(&i,sizeof(long),1,file);
}
fclose(file);
return 0;
}