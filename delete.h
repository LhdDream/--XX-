#pragma once
#ifndef _DELETE_H_
#define _DELETE_H_
#include"common.h"
#include"revise.h"
#include"create.h"
#include<unistd.h>
#include<termios.h>
#include<time.h>
#include<string.h>

void deletemenu(int flag2)
{
    int i=0;

    char map[5][100]={
        "\033[34m                                     \n",
        "      需要根据员工编号来删除的      \n",
        "\033[34m      需要根据员工职务来删除的      \n",
        "\033[35m      需要根据员工姓名来删除的      \n",
        "              返回主菜单                \033[37m\n",
     };
    for(i=0;i<5;i++)
    {
        if(flag2==i)
            printf("-->");
        else
            printf("  ");
        printf("%s",map[i]);
    }
}
Employee *Delete(Employee *pHead)
{
  system("clear");
   if(pHead==NULL)
    {
        printf("没有数据请返回!\n");
        return pHead;
    }       
    Employee *pTemp,*q;
  unsigned long    int num;//员工编号，根据员工编号
      char duty[10];//员工的职务
      char name[10];//员工姓名，
      int x=0;//判断根据什么来查询
      int flag=0;//判断是不是找到
      int flag2=0;//判断上下
      int i=0;
      int b=0;
      char c;//判断是不是需要确认删除
      pTemp=pHead;
      q=pHead;;//q结点始终需要位于pTemp结点之前
                    deletemenu(flag2);
      int *get=(int *)malloc(SIZE);
          while(1)
         {
             get[i]=getch1();
             if(get[i]=='\n') 
             {
                break;
             }
           if (get[i]==0x41)
           {   flag2--;
               x--;
                system("clear");
                deletemenu(flag2);
           }
           if (get[i]==0x42)
           {
              x++;
              flag2++;
              system("clear");
               deletemenu(flag2);
            }
           i++;
         }
       free(get);
      switch(x)
      {
            case 1: {
                    printf("请输入要删除的员工编号\n");
                    scanf("%ld",&num);
                    break;
                    }
            case 2:{
                    printf("请输入要删除的员工职务\n");
                   scanf("%s",duty);
                   break;
                   }
            case 3:{
                       printf("请输入要删除的员工姓名\n");
                   getchar();
                   scanf("%[^\n]s",name);
                   break;
                 }
            case 4: return pHead;
      }
      do
      {
        q=pTemp;
        pTemp=pTemp->next;
          if(((x==1)&&(pTemp->num==num))||((x==2)&&(strcmp(duty,pTemp->duty)==0))||((x==3)&&(strcmp(name,pTemp->name)==0)))
          {
             flag=1;
              break;
          }
      }while(pTemp);
      if(flag==1)
      {
            printf("确认需要删除吗?(y/n)");
            getchar();
              scanf("%c",&c);
              if(c!='y')
              {
                 getchar();
                   deletemenu(flag2);
              }
              else
              {
                 q->next=pTemp->next;
                 free(pTemp);
                 count--;
                 count2++;
                 b=1;
                 getchar();
               }
      }
      else
      {
          printf("查无此人,删除失败!");
      }
      if(b==1)
          printf("删除成功！");
      else
          printf("按任意键返回");
   return pHead;//返回头指针
}
#endif
