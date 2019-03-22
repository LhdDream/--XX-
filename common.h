#pragma once
#ifndef COMMON_H_
#define COMMON_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <termios.h>
#include <assert.h>
int getch1(void);

int getch1()
{
    int c = 0;
    int res = -1;
    struct termios org_opts, new_opts;

    res = tcgetattr(STDIN_FILENO, &org_opts);
    assert(res == 0);
    memcpy(&new_opts, &org_opts, sizeof(org_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);

    c = getchar();

    res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    assert(res == 0);

    return c;
}

typedef struct employee
{
       unsigned long int num;//员工编号
        char duty[10];//员工职务
        char name[10];//员工姓名
        char sex[10];//员工性别
         int age;//员工年龄
        int salary;//员工工资
        char tel_office[13];//员工办公电话
        char office_age[10];//员工工作的时间
        char qq[13];//QQ号码
        char address[31];//家庭住址
        int attendance;//出勤
        char attendancetime[20];//出勤时间
        int leave_earlier;//早退次数
        int overtime;//加班次数
        struct employee *next;

}Employee;
#endif//COMMON_H_
