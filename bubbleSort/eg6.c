#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void bubbleSort(void* ptr,int cs,int es,int (*p2f)(void*,void*))
{
int e,f,w,m;
void *a,*b,*c;
c=(void*)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
}
e++;
f++;
}
m--;
}
free(c);
}
struct student
{
int rollNumber;
char name[21];
};
int studentComparator(void* left,void* right)
{
struct student *s1,*s2;
s1=(struct student*)left;
s2=(struct student*)right;
return s1->rollNumber-s2->rollNumber;
}
int main()
{
int req;
struct student *s,*j;
int y;
printf("Enter your requirement: ");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
s=(struct student*)malloc(sizeof(struct student)*req);
j=s;
for(y=0;y<req;y++)
{
printf("Enter roll number: ");
scanf("%d",&(j->rollNumber));
printf("Enter name: ");
scanf("%s",j->name);
j++;
}
bubbleSort(s,req,sizeof(struct student),studentComparator);
for(y=0;y<req;y++)
{
printf("Roll Number: %d,Name: %s\n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}