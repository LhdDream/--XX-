#pragma once
#ifndef PRINT_H_
#define PRINT_H_
#include"common.h"
void print1(Employee *pTemp)//单次一次性输出结构体内容
{
               printf("-------------------------------------------------------\n");
             printf("|编号为:%ld  |",pTemp->num);
             printf("职务: %s    |",pTemp->duty);
             printf("性别: %s    |",pTemp->sex);
             printf("姓名：%s    |\n",pTemp->name);
             printf("|年龄  %d   |",pTemp->age);
             printf("工资  %d    |",pTemp->salary);
             printf("办公电话 %s |",pTemp->tel_office);
             printf("|任职时间 %s|\n",pTemp->office_age);
             printf("|QQ号 %s    |",pTemp->qq);
             printf("家庭住址 %s|",pTemp->address);
             printf("出勤次数%d |",pTemp->attendance);
             printf("出勤时间%s|\n",pTemp->attendancetime);
             printf("早退次数%d|",pTemp->leave_earlier);
             printf("加班次数%d|\n",pTemp->overtime);
             printf("--------------------------------------------------------\n");
}

#endif//PRINT1.h
