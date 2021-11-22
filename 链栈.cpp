/*
链栈：以头结点作为栈顶
栈空条件：s->next=NULL
 栈满条件：不考虑
 进栈e操作：将存放e的结点插入到头结点之后
 退栈操作：取出头结点之后结点的元素并删除之






*/




#include<stdio.h>
#include<stdlib.h>
typedef struct LinkStack
{
  int data;
  struct  LinkStack* pnext;
  

}Stack;
bool Init_Stack(Stack *&s1)
{
s1=(Stack*)malloc(sizeof(Stack));
if(s1==NULL)  
  return false;
  else
  {
  s1->pnext=NULL;
  return true;
  }
}
bool Destory_Stack(Stack *&s1)
{
 Stack *p=s1->pnext,*pre=s1;
 while(p!=NULL)
 {
  free(pre);
  pre=p;
  p=p->pnext;

 }
return true;

}
bool IsEmpty_Stack(Stack *&s1)
{
return (s1->pnext=NULL);
}
bool Push(Stack *&s1,int x)//头插
{
 Stack *p=s1;
 p=(Stack*)malloc(sizeof(Stack));
 p->data=x;
 p->pnext=s1->pnext;
 s1->pnext=p;
 return true;



}
bool Pop(Stack *&s1,int &e)
{
 Stack*p=s1->pnext;
 if(p==NULL)
 return false;
 e=p->data;
 s1->pnext=p->pnext;
 free(p);
return true;

}
bool GetTop(Stack *&s1,int &e)
{
if(s1->pnext==NULL)
 return false;
 return s1->pnext->data;
 return true;

}