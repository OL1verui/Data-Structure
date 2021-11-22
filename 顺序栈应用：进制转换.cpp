#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
typedef struct Stack
{
   int top;
   int Array[Maxsize-1];


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

bool Trans(int n)
{
  Stack *s1;
  int e;
  Init_Stack(s1);
  while(n>0)
  {
   Push(s1,n%2);
   n=n/2;
  }
  while(!StackEmpty(s1))
  {
   Pop(s1,e);
   printf("%d",e);
  }
  printf("\n");
  Destory_Stack(s1);
  return true;
}
int main()
{
Trans(100);
return 0;

}