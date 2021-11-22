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
bool GetPop(Stack *&s1,Elemtype &e)
{
if(s1->top==-1)
        return false;
else
 e=s1->Array[s1->top];
 return true;


}
bool Judge(Elemtype str[])
{
  int i=0;
  Elemtype e;
  Stack *s1;
  Init_Stack(s1);
  for(int i=0;str[i]!='\0';i++)
    Push(s1,str[i]);
   for(int i=0;str[i]!='\0';i++)
   {
    Pop(s1,e);
    if(str[i]!=e)
    {
     printf("字符串不是回文串");
     Destory_Stack(s1);
     return false;

    }
  

   }
   printf("字符串是回文串");
   Destory_Stack(s1);
   return true;


}






int main()
{
   Elemtype str[]="dabba";
   Judge(str);



}