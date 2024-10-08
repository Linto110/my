#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size];
int front,rear;
void main()
{
void insertq(int);
int deleteq();
int searchq(int);
int data,opt,ans,tfront;
do
{
printf("\n1.Insert\n");
printf("2.Delete\n");
printf("3.Search\n");
printf("4.Exit\n");
printf("Enter your option :");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("Enter data :");
scanf("%d",&data);
insertq(data);
break;
case 2:
data=deleteq();
printf("Deleted item is %d",data);
break;
case 3:
printf("Enter item to be searched ");
scanf("%d",&data);
ans=searchq(data);
if(ans==1)
printf("Found the searched item");
else
printf("The searched item not found ");
break;
case 4:
exit(0);
}
}
while(1);
}
void insertq(int item)
{
if(rear==size-1)
printf("queue is empty");
else
queue[++rear]=item;
}
int deleteq()
{
if(front==rear)
{
printf("Queue is empty\n");
exit(0);
}
else
return queue[++front];
}
int searchq(int item)
{
int tfront=front+1;
while(tfront!=rear && queue[tfront]!=item)
++tfront;
if(queue[tfront]==item)
return 1;
else
return 0;
}
