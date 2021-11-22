/*
栈空条件，栈1空：top1==-1；栈2空：top2==MaxSize
栈满条件：top1==top2-1
元素x进栈操作，进栈1操作：top1++;data[top1]=x；
		  进栈2操作：top2--;data[top2]=x;
出栈x操作，出栈1操作，x=data[top1];top1--；
  	      出栈2操作，x=data[top2];top2++；
*/




#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
typedef struct Stack
{
int Array[Maxsize];
int top1; //左栈指针
int top2; //右栈指针
}Stack;
bool Init_Stack(Stack *&s1)
{
s1=(Stack*)malloc(sizeof(Stack));
s1->top1=-1;
s1->top2=Maxsize-1;

}
bool Push(Stack *&s1,int flag,int x)
{
if(s1->top1-s1->top2==1)
{
printf("当前栈已满\r\n");
return true;
}
switch (flag)
{
case 1: //操作左栈
    s1->top1++;
    s1->Array[s1->top1]=x;
    break;
case 2: //操作右栈
    s1->top2--; 
    s1->Array[s1->top2]=x;
    break;

default:
    printf("输入有误\r\n");
    break;
}
return true;
}
bool Pop(Stack *&s1,int flag,int &e)
{
    switch (flag)
    {
    case 1:
if(s1->top1==-1)
return false;
else
{
 e=s1->Array[s1->top1];
  printf("%4d",e);
 s1->top1--;
}
break;
case 2:
if(s1->top2==Maxsize-1)
        return false;
  else
  {
 e=s1->Array[s1->top2];
  printf("%4d",e);
 s1->top2++;
  }
 break;
 default:
 printf("删除失败\r\n");
 break;
    }

 return true;



}