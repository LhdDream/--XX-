#pragma  once
#ifndef  ADD1_H_
#define ADD1_H_
#include"common.h"
Employee* add1(Employee *p2)
{
    p2->attendance=30;//出勤初始化
            printf("请输入员工编号\n");
            scanf("%ld",&p2->num);//员工的编号
            printf("请输入员工的姓名\n");
            getchar();
            scanf("%[^\n]s",p2->name);
            printf("请输入员工的性别\n");
            scanf("%s",p2->sex);
            printf("请输入员工的职务\n");
            scanf("%s",p2->duty);
            printf("请输入员工的年龄\n");
            getchar();
            scanf("%d",&p2->age);
            printf("请输入员工的工资\n");
            scanf("%d",&p2->salary);
            printf("请输入员工的办公电话\n");
            scanf("%s",p2->tel_office);
            printf("请输入员工的家庭住址\n");
            scanf("%s",p2->address);
            printf("请输入员工在公司任职多长时间\n");
            scanf("%s",p2->office_age);
            printf("\n请输入员工的QQ号\n");
            scanf("%s",p2->qq);
                return p2;
}
#endif
