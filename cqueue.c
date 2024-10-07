#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size];
int front=-1,rear=-1;
void main()
{
void insertq(int);
int deleteq();
int searchq(int);
int data,opt;
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
if(searchq(data))
printf("Founded the searched item");
else
printf("The searched item not found ");
break;
case 4:
exit(0);
}
}
while(1);
}

//insert
void insertq(int item)
{
int t=rear;
t=(t+1)%size;
if(t==front)
{
printf("Queue is full");
exit(0);
}
else
{
rear=t;
queue[rear]=item;
}
}

//delete
int deleteq()
{
if(front==rear)
{
printf("Queue is empty");
exit(0);
}
else
{
front=(front+1)%size;
return queue[front];
}
}

//search 
int searchq(int item)
{
int tfront;
if(front!=rear)
tfront=(front+1)%size;
else
tfront=(tfront+1)%size;
while(tfront!=rear && queue[tfront]!=item)
tfront=(tfront+1)%size;
if(queue[tfront]==item)
return 1;
else
return 0;
}


