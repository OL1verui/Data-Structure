/*
  栈空条件：top=-1
  栈满条件：top=MaxSize-1
  进栈e操作：top++; 将e放在top处
  退栈操作：从top处取出元素e; top--;

*/







#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
typedef struct Stack
{
   int top;
   int Array[Maxsize];


}Stack;
bool Init_Stack(Stack *&s1)
{
s1=(Stack*)malloc(sizeof(Stack));
if(s1==NULL)
return false;
else
{
s1->top=-1;
 return true;
}
}

bool Destory_Stack(Stack *&s1)
{
 free(s1);

 return true;

}
bool StackEmpty(Stack *&s1)
{
  if(s1->top==-1)
     return true;
  else
     return false;

}
bool Push(Stack *&s1,int x)
{
if(s1->top==Maxsize-1)
        return false;
else
    s1->top++;
    s1->Array[s1->top]=x;
    return true;


}
bool Pop(Stack *&s1,int &e)
{
  if(s1->top==-1)
        return false;
  else
  {
 e=s1->Array[s1->top];
  printf("%4d",e);
 s1->top--;
  }
 return true;

}
bool GetPop(Stack *&s1,int &e)
{
if(s1->top==-1)
        return false;
else
 e=s1->Array[s1->top];
 return true;


}




int main()
{
Stack *s1;
int a=0;
Init_Stack(s1);
Push(s1,1);
Push(s1,2);
Push(s1,3);
Push(s1,4);
Push(s1,5);
Pop(s1,a);
Pop(s1,a);
Pop(s1,a);
Pop(s1,a);
Pop(s1,a);


}