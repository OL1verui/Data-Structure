#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
#define Elemtype char
typedef struct Stack
{
   int top;
   Elemtype Array[Maxsize-1];


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
bool Push(Stack *&s1,Elemtype x)
{
if(s1->top==Maxsize-1)
        return false;
else
    s1->top++;
    s1->Array[s1->top]=x;
    return true;


}
bool Pop(Stack *&s1,Elemtype &e)
{
  if(s1->top==-1)
        return false;
  else
  {
 e=s1->Array[s1->top];
 s1->top--;
  }
 return true;

}
int GetPop(Stack *&s1,Elemtype &e)
{
if(s1->top==-1)
        return false;
else
 e=s1->Array[s1->top];
 return e;


}
bool brackets(Elemtype str[])
{
int i=0;
Elemtype e;
Stack *s1;
Init_Stack(s1);
for(int i=0;str[i]!='\0';i++)
{
     //如果为左括号 入栈
     if(str[i]=='(')
     Push(s1,str[i]);
     //如果为右括号  判断栈是否为空 如果不为空出栈
     else 
     {
     if( StackEmpty(s1)||GetPop(s1,e)=='(')
     {
        printf("括号不匹配！\r\n");
        return false;
     }
    else
    Pop(s1,e);

     }
    
 
}
printf("括号匹配\r\n");
return true;




}
int main()
{
Elemtype str[]="((())";
brackets(str);

}