#pragma  once
#ifndef _REVISA_H_
#define  _REVISA_H
#include"common.h"
#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<time.h>
#include<string.h>
#include"menu.h"
#define     SIZE    200
//定义按键们的宏
#define  UP   "\033[A"
#define  DOWN   "\033[B"
void revisemenu(int flag5)
{
     int i;
    char map[5][100]={
         "\033[34m                                      \n",
         "\033[35m      需要根据员工编号来修改的话      \n",
         "\033[34m      需要根据员工职务来修改的话      \n",
         "\033[34m      需要根据员工姓名来修改的话      \n",  
         "              返回上层                \033[37m\n", 
     };
    for(i=0;i<5;i++)
    {
        if(flag5==i)
            printf("-->");
        else
            printf("  ");
        printf("%s",map[i]);
    }
}
void revisemenu1(int flag6)
{
   int i;
   char map[12][100]={
             "\033[34m      1.员工编号             \n",
             "\033[34m      2.员工姓名             \n",
             "\033[33m      3.员工性别             \n",
             "\033[33m      4.员工职务             \n",
             "\033[35m      5.员工年龄             \n",
             "\033[35m      6.员工工资             \n",
             "\033[31m      7.员工办公电话         \n",
             "\033[31m      8.家庭地址             \n",
             "\033[34m      9.任职时间时长         \n",
             "\033[34m      10.QQ                  \n",
             "\033[33m      11.出勤记录            \n",
             "\033[33m      12.返回上层        \033[37m\n",
           };
   for(i=0;i<12;i++)
   {
      if(flag6==i)
          printf("-->");
      else
          printf("  ");
      printf("%s",map[i]);
   }
}
Employee *revise(Employee *pHead)//对员工信息进行修改
{
     system("clear");
         if(pHead==NULL)
      {
          printf("没有数据请返回!\n");
         return pHead;
      }     
      Employee *pTemp;//通过此指针进行遍历
    unsigned long int num;//员工编号，根据员工编号
      char duty[10];//员工的职务
      char name[10];//员工姓名，
      int x=0;//判断根据什么来查询
      int flag5=0;//判断箭头上下
      int i=0;
      int l=1;
      int flag6=0;
      int flag=0;
      pTemp=pHead->next;
           revisemenu(flag5);
      int *get=(int *)malloc(SIZE);
          while(1)
         {
             get[i]=getch1();
             if(get[i]=='\n')
                 break;
           if (get[i]==0x41)
           {   flag5--;
               x--;
                system("clear");
                revisemenu(flag5);
           }
           if (get[i]==0x42)
           {
              x++;
              flag5++;
              system("clear");
               revisemenu(flag5);   
            }
           i++;
         }
     switch(x)
      {
            case 1: {printf("请输入要修改的员工编号\n");
                    scanf("%ld",&num);
                    break;
                    }
            case 2:{printf("请输入要修改的员工职务\n");
                   scanf("%s",duty);
                   break;}
            case 3:{
                    printf("请输入要修改的员工姓名\n");
                  // getchar();
                    scanf("%[^\n]s",name);
                    break;
                   } 
            case 4: return pHead;
      }

     getchar();
      while(pTemp)
      {
         if((x==1&&(pTemp->num==num))||(x==2&&(strcmp(duty,pTemp->duty)==0))||(x==3&&(strcmp(name,pTemp->name)==0)))
         {
           system("clear");
             revisemenu1(flag6);
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
                revisemenu1(flag6);
           }
           if (get[i]==0x42)
           {
              l++;
              flag6++;
              system("clear");
               revisemenu1(flag6);
            }
           i++;
         }
          free(get);
            switch(l)
            {
            case 1: {
                        printf("请输入员工编号:");
                    scanf("%ld",&pTemp->num);//员工的编号
                   flag=1;
                    break;
                    }
            case 2: {   printf("请输入员工的姓名\n");
                        scanf("%[^\n]s",pTemp->name);//员工姓名
                        flag=1;
                      break;
                    }
                    
            case 3: {
                        printf("请输入员工的性别\n");
                    scanf("%s",pTemp->sex);//员工性别
                    flag=1;
                    break;
                    }
            case 4: {
                        printf("请输入员工的职务\n");
                      scanf("%s",pTemp->duty);
                      flag=1;
                      break;
                    }
            case 5: {   printf("请输入员工的年龄\n");
                       scanf("%d",&pTemp->age);
                       flag=1;
                       break;
                    }
            case 6: {   printf("请输入员工的工资\n");
                       scanf("%d",&pTemp->salary);
                       flag=1;
                       break;
                    }
            case 7: {   printf("请输入员工的办公电话\n");
                       scanf("%s",pTemp->tel_office);
                       flag=1;
                       break;
                    }
            case 8:  { printf("请输入员工的家庭住址\n");
                      scanf("%s",pTemp->address);
                      flag=1;
                      break;
                     }
            case 9:  {  printf("请输入员工在公司任职多长时间\n");
                       scanf("%s",pTemp->office_age);
                       flag=1;
                       break;
                     }
            case 10:  {  printf("\n请输入员工的QQ号\n");
                      scanf("%s",pTemp->qq);
                      flag=1;
                        break;
                      }
            case 11:  { printf("\n请输入员工的出勤\n");
                       scanf("%d",&pTemp->attendance);
                       flag=1;
                       break;
                         }
            case 12:   revise(pHead);
            }
         }
         if(flag==1)
             break;
         pTemp=pTemp->next;
      }
      getchar();
      if(flag==1)
          printf("修改成功,请返回！");
      else
          printf("查无此人，请返回！");
      return pHead;
}
#endif
