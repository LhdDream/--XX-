#pragma once
#ifndef SEARCH_H_
#define SEARCH_H_
#include"common.h"
#include"create.h"
#include"revise.h"
#include"print1.h"
#include<unistd.h>
#include<termios.h>
#include<time.h>
#include<string.h>
void serachmenu(int flag5)//第一次查询菜单
{
     int i=0;
    char map[9][100]={
    "\033[34m                               \n",
    "\033[34m      1.输入员工编号查询       \n",
    "\033[33m      2.输入员工职务查询       \n",
    "\033[33m      3.输入员工姓名查询       \n",
    "\033[35m      4.输入员工性别查询       \n",
    "\033[35m      5.输入员工电话查询       \n",
    "\033[34m      6.输入员工工资查询       \n",
    "\033[34m      7.输入员工工作时长查询   \n",
    "              8.返回上层         \033[37m\n",
   };
    for(i=0;i<9;i++)
    {
        if(flag5==i)
            printf("-->");//箭头标志
        else
            printf("  ");//空格标志
        printf("%s",map[i]);
    }
}
void serachmenu1(int flag6)//组合查询的菜单
{
    int i=0;
    char map[5][100]={
    "\033[33m                             \n",
    "\033[34m     1.输入员工职务查询      \n",
    "\033[33m     2.输入员工姓名查询      \n",
    "\033[35m     3.输入员工工作时长查询  \n",
    "             4.返回上层      \033[37m\n",
    };
    for(i=0;i<5;i++)
    {
        if(flag6==i)
            printf("-->");//箭头标志
        else
            printf("  ");//格式对齐
        printf("%s",map[i]);
    }
}

void serach(Employee *pHead)
{
    system("clear");
        if(pHead==NULL)
      {
          printf("没有数据请返回!\n");
          return ;
      }
    Employee *pTemp;//遍历指针
  unsigned long  int num;//员工的编号查询
    char duty[10];//员工职务查询
    char name[10];//员工姓名查询
    char sex[10];//员工性别查询
    char tel_office[13];//员工的电话查询
    int salary;//输入员工的工资查询
    char office_age[3];//输入员工工作的时间
    int x=0;//判断根据什么来查询
    int flag=0;//判断找到情况
    int m=0;//判断是不是需要组合查询
    int l=0;//判断组合查询情况
    int flag5=0;//判断箭头
    int flag6=0;//判断箭头
    int i=0;
    serachmenu(flag5);
      int *get=(int *)malloc(SIZE);//申请内存
          while(1)
         {
           get[i]=getch1();//利用getch函数来记录键盘读入
             if(get[i]=='\n') {
                break;
             }
           if (get[i]==0x41)
           {   flag5--;
               x--;
                system("clear");
                serachmenu(flag5);
           }
           if (get[i]==0x42)
           {
              x++;
              flag5++;
              system("clear");
               serachmenu(flag5);
            }
           i++;
         }
   switch(x)
    {   case 1: printf("请输入查询的员工编号\n");
                scanf("%ld",&num);
                break;
        case 2:printf("请输入查询的员工职务\n");
               scanf("%s",duty);
               break;
        case 3:printf("请输入查询的员工姓名\n");
               scanf("%[^\n]s",name);
               break;
        case 4:printf("请输入查询的员工性别\n");
               scanf("%s",sex);
               break;
        case 5:printf("请输入查询的员工电话\n");
               scanf("%s",tel_office);
               break;
        case 6:printf("请输入查询的员工工资\n");
               scanf("%d",&salary);
               break;
        case 7:printf("请输入查询的员工工作时长\n");
               scanf("%s",office_age);
               break;
        case 8:return ;
    }
   pTemp=pHead->next;
   setbuf(stdin,NULL);
   while(pTemp)//遍历指针
   {
  // 将函数匹配若能够匹配上则输出
   if((x==1&&(pTemp->num==num))||(x==5&&(strcmp(pTemp->tel_office,tel_office)==0)))
          {
                 print1(pTemp);//print1为print1.h的函数直接输入所有内容
                 flag=1;
          }
       if((x==2&&(strcmp(pTemp->duty,duty)==0))||(x==4&&(strcmp(pTemp->sex,sex)==0)))
       {
           print1(pTemp);
           m=1;//判断组合查询
         flag=1;//找到标志
       }
       if(x==3&&(strcmp(pTemp->name,name)==0))
      {
             print1(pTemp);
             flag=1;//找到标志
          }
       if((x==6&&(pTemp->salary==salary))||(x==7&&(strcmp(pTemp->tel_office,tel_office)==0)))
          {
              print1(pTemp);
              m=1;//判断组合查询
              flag=1;
          }
       pTemp=pTemp->next;
   }
   getchar();
  if(m==1)
  {
      system("clear");
      serachmenu1(flag6);
          while(1)
         {
             get[i]=getch1();
             if(get[i]=='\n') {
                break;
             }
           if (get[i]==0x41)
           {   flag6--;
               l--;
                system("clear");
                serachmenu1(flag6);
           }
           if (get[i]==0x42)
           {
              l++;
              flag6++;
              system("clear");
               serachmenu1(flag6);
            }
           i++;
         }
          free(get);
       switch(l)
       {
            case 1:printf("请输入你要查询的员工职务\n");
                   scanf("%s",duty);
                   break;
            case 2:printf("请输入你要查询的员工姓名\n");
                  getchar();
                   scanf("%[^\n]s",name);
                   break;
            case 3:printf("请输入你要查询的员工工作时长\n");
                   scanf("%s",tel_office);
                   break;
            case 4:serach(pHead);
       }
       getchar();
       pTemp=pHead->next;
       while(pTemp)
       {
          if((l==1&&(strcmp(pTemp->duty,duty)==0))||(l==2&&strcmp(pTemp->name,name)==0))
          {
              print1(pTemp);
          }
          if(l==3&&(strcmp(pTemp->tel_office,tel_office)==0))
          {
              print1(pTemp);
          }
          pTemp=pTemp->next;
       }
       getchar();
  }
   if(flag==0)
        {
             printf("查无此人");
        }
}
#endif
