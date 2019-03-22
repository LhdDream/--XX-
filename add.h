#pragma once
#ifndef ADD_H_
#define ADD_H_
#include"common.h"
#include"create.h"
#include"revise.h"
#include"add1.h"
#include<unistd.h>
#include<termios.h>
#include<time.h>
#include<string.h>
void addmenu(int flag1)
{
  int i=0;
    char map[7][100]={
    "                        \n",
    "\033[33m        根据员工编号插入\n",
    "\033[34m        根据员工职务插入\n",
    "\033[33m        根据年龄插入\n",
    "\033[35m        实行头插法\n",
    "\033[33m        实行尾插法\n",
    "                返回上一层  \033[37m\n",
  };
    for(i=0;i<7;i++)
    {
        if(flag1==i)
            printf("-->");
        else
            printf("  ");
        printf("%s",map[i]);
    }
}
Employee *add(Employee *pHead)
{
   system("clear");
       if(pHead==NULL)
      {
          printf("没有数据请返回!\n");
          return pHead;
      }     
    unsigned long int num;//根据员工编号插入
    char duty[10];//根据员工职务插入
     int age;//根据员工年龄插入
    int x=0;//判断采用那种方式插入
    int flag1=0,flag2=0;//表示判断添加成功没成功
    int i=0;
    Employee *pTemp,*q,*news;
    pTemp=pHead->next;
    q=pHead;
     addmenu(flag1);
      int *get=(int *)malloc(SIZE);
           setbuf(stdin,NULL);
          while(1)
         {
             get[i]=getch1();
             if(get[i]=='\n') {
                break;
             }
           if (get[i]==0x41)
           {   flag1--;
               x--;
                system("clear");
                addmenu(flag1);
           }
           if (get[i]==0x42)
           {
              x++;
              flag1++;
              system("clear");
               addmenu(flag1);
            }
           i++;
         }
          free(get);
   switch(x)
    {
    case 1:printf("请输入你想要添加的员工编号\n");
           scanf("%ld",&num);
           break;
    case 2:printf("请输入你想要添加的员工职务\n");
           scanf("%s",duty);
           break;
    case 3:printf("请输入你想要添加的员工年龄\n");
           scanf("%d",&age);
           break;
    }
    while(pTemp)
    {
          if(x==1)
          {

              if(num<=pTemp->num)
                 {

               news=(Employee *)malloc(sizeof(Employee));
                     news->next=pTemp;
                          q->next=news;
                          news=add1(news);
                          flag2=1;
                          count++;
                          count1++;
                          break;
                 }
                 if(num>pTemp->num)
                 {

                   news=(Employee *)malloc(sizeof(Employee));
                     pTemp->next=news;
                    news->next=NULL;
                     news=add1(news);
                     flag2=1;
                     count++;
                     count1++;
                     break;
                 }
          }
          if(x==2)
          {
                      if((strcmp(duty,pTemp->duty)==0))
                      {
                          news=(Employee *)malloc(sizeof(Employee));
                          news->next=pTemp;
                          q->next=news;
                           news=add1(news);
                          flag2=1;
                          count++;
                          count1++;
                      }
          }
          if(x==3)
          {
              if((age>=q->age)||(age<=pTemp->age))
              {
                  news=(Employee *)malloc(sizeof(Employee));
                  news->next=pTemp;
                  q->next=news;
                   news=add1(news);
                  flag2=1;
                  count++;
                  count1++;
              }
        }
          q=pTemp;
         pTemp=pTemp->next;
    }
          if(x==4)
          {
              news=(Employee *)malloc(sizeof(Employee));
              news->next=pHead->next;
              pHead->next=news;
               news=add1(news);
              flag2=1;
              count++;
              count1++;
          }


    if(x==5)
    {
        news=(Employee *)malloc(sizeof(Employee));
        q->next=news;
        news->next=NULL;
         news=add1(news);
        flag2=1;
        count++;
        count1++;
    }
    if(x==6)
    {
        return pHead;
    }
    getchar();
    if(flag2==1)
        printf("添加成功！请返回");
    else
        printf("添加失败！请返回");
   return pHead;
}
#endif
