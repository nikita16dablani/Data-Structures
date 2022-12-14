#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
void printAllCombinations(char*,int,int);
void _printAllCombinations(char *seed,char *set,int setSize,int maxLength)
{
int i,seedLength;
char *str;
if(maxLength==0)
{
count++;
printf("%s\n",seed);
return;
}
seedLength=strlen(seed);
str=(char*)malloc(sizeof(char)*(seedLength+2));
strcpy(str,seed);
for(i=0;i<setSize;i++)
{
str[seedLength]=set[i];
str[seedLength+1]='\0';
_printAllCombinations(str,set,setSize,maxLength-1);
}
free(str);
}
void printAllCombinations(char *set,int setSize,int maxLength)
{
_printAllCombinations("",set,setSize,maxLength);
}
int main()
{
char charSet[10]={'0','1','2','3','4','5','6','7','8','9'};
printAllCombinations(charSet,10,3);
printf("Number of combinations: %d\n",count);
return 0;
}