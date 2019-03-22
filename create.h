#pragma  once
#ifndef CREATE_H_
#define CREATE_H_
#include"common.h"
#include<stdlib.h>
int count=0;//总用户
int count1=0;//加入
int count2=0;//离职
Employee * Create(Employee *pHead)//对员工信息进行初始化
{
   system("clear");
    Employee *p1,*p2;
    char x;
    p1=pHead=(Employee *)malloc(sizeof(Employee));//创建一个头指针
    while(1)
    {
            p2=(Employee *)malloc(sizeof(Employee));
            p2->attendance=0;//出勤初始化
            p2->leave_earlier=0;//早退次数初始化
            printf("请输入员工编号\n");
            scanf("%ld",&p2->num);//
            printf("请输入员工的姓名\n");
            getchar();
            scanf("%[^\n]s",p2->name);
            printf("请输入员工的性别\n");
            scanf("%s",p2->sex);
            printf("请输入员工的职务\n");
            scanf("%s",p2->duty);
           
            printf("请输入员工的工资\n");
            scanf("%d",&p2->salary);
            printf("请输入员工的年龄\n");
            getchar();//清除缓冲区
            scanf("%d",&p2->age);
           while(1) 
           { if(p2->age<18)
            {
                printf("年龄输入错误！请重新输入！\n");
                scanf("%d",&p2->age);
            }
            if(p2->age>18)
                break;
           }

            printf("请输入员工的办公电话\n");
            scanf("%s",p2->tel_office);
            printf("请输入员工的家庭住址\n");
            scanf("%s",p2->address);
            printf("请输入员工在公司任职多长时间\n");
            scanf("%s",p2->office_age);
            if(atoi(p2->office_age)>p2->age)
            {
                printf("输入错误！重新输入！");
                scanf("%s",p2->office_age);
            }
            printf("请输入员工的QQ号\n");
            scanf("%s",p2->qq);
            p1->next=p2;//尾插法
            p1=p2;//尾插法
            count++;//统计员工个树
            printf("\n是不是需要继续输入(y/n) ");
            setbuf(stdin,NULL);//清除缓冲区
            scanf("%c",&x);
            system("clear");//清除屏幕
            if(x!='y')
            {
               printf("\n输入完毕，按任意返回\n");
               getchar();
                break;
            }
    }
    p2->next=NULL;
    system("clear");
    return pHead;
}
#endif
