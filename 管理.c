#include "common.h"
#include "menu.h"
#include "add1.h"
#include "print1.h"
#include "create.h"
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <string.h>
#include "revise.h"
#include "delete.h"
#include "search.h"
#include "add.h"
#include "quicksort.h"
#include <assert.h>
char gsave, gfirst; //判断表示符
int leave = 0;      //请假标识符
int flag = 3;       //菜单标识符号
void summaryemp(Employee *pHead)
{
    int sum = 0, man = 0, woman = 0;
    int age = 60;
    int age1 = 0, age2 = 0;
    Employee *pTemp;
    pTemp = pHead->next;
    while (pTemp)
    {
        sum += pTemp->salary - pTemp->leave_earlier * 50 + pTemp->overtime * 50 - leave * 100;
        if ((strcmp(pTemp->sex, "man") == 0) || (strcmp(pTemp->sex, "男") == 0))
            man++;
        if ((strcmp(pTemp->sex, "woman") == 0) || (strcmp(pTemp->sex, "女") == 0))
            woman++;
        if (age < pTemp->age)
            age2++;
        if (pTemp->age < age)
            age1++;
        pTemp = pTemp->next;
    }
    system("clear");
    printf("\n下面是相关员工统计信息！\n");
    printf("____________________________\n");
    printf("员工总数是%d\n", count);
    printf("员工的工资总数是：%d\n", sum);
    printf("男员工的总数为%d\n", man);
    printf("女员工的总数是%d\n", woman);
    printf("小于60岁的员工总数是%d\n", age1);
    printf("大于60岁的员工总数是%d\n", age2);
    printf("离职人数:%d\n", count1);
    printf("加入人数:%d\n", count2);
    printf("___________________________\n");
    system("read -n 1");
}
void input(Employee *pHead)
{
    if (pHead == NULL)
    {
        printf("没有数据请返回!\n");
        return;
    }
    FILE *fp;
    Employee *pTemp;
    pTemp = pHead->next;
    int westos = 0; //标志
    if ((fp = fopen("employee.txt", "at+")) == NULL)
    {
        printf("打开失败！\n");
        return;
    }
    while (pTemp)
    {
        fprintf(fp, "%ld %s %s %s\n", pTemp->num, pTemp->duty, pTemp->sex, pTemp->name);
        fprintf(fp, "%d %d %s %s\n", pTemp->age, pTemp->salary, pTemp->tel_office, pTemp->office_age);
        fprintf(fp, "%s %s %d\n", pTemp->qq, pTemp->address, pTemp->attendance);
        fprintf(fp, "%d %d\n", pTemp->leave_earlier, pTemp->overtime);
        pTemp = pTemp->next;
        westos = 1;
    }
    if (westos == 1)
        printf("保存成功！\n");
    else
        printf("保存失败!\n");
    fclose(fp);
    sleep(5);
}
void Print(Employee *pHead);
Employee *output()
{
    FILE *fp;
    Employee *pHead;
    Employee *p1, *pTemp;
    Employee *q;
    p1 = pHead = (Employee *)malloc(sizeof(Employee));
    if ((fp = fopen("employee.txt", "r")) == NULL)
    {
        printf("打开失败!\n");
        return pHead;
    }
    else
        printf("打开成功！\n");
    while (!feof(fp))
    {
        pTemp = (Employee *)malloc(sizeof(Employee));
        fscanf(fp, "%ld %s %s %[^\n]s", &pTemp->num, pTemp->duty, pTemp->sex, pTemp->name);
        fscanf(fp, "%d %d %s %s", &pTemp->age, &pTemp->salary, pTemp->tel_office, pTemp->office_age);
        fscanf(fp, "%s %s %d", pTemp->qq, pTemp->address, &pTemp->attendance);
        fscanf(fp, "%d %d", &pTemp->leave_earlier, &pTemp->overtime);
        count++;
        p1->next = pTemp;
        q = p1;
        p1 = pTemp;
    }
    q->next = NULL;
    free(pTemp);
    Print(pHead);
    fclose(fp);
    return pHead;
}
void Print(Employee *pHead)
{
    if (pHead == NULL)
    {
        printf("没有数据请返回!\n");
        return;
    }

    system("clear");
    Employee *pTemp;
    pTemp = pHead->next;
    while (pTemp)
    {

        printf("-------------------------------------------------------\n");
        printf("|编号为:%ld  |", pTemp->num);
        printf("职务: %s    |", pTemp->duty);
        printf("性别: %s    |", pTemp->sex);
        printf("姓名：%s    |\n", pTemp->name);
        printf("|年龄  %d   |", pTemp->age);
        printf("工资  %d    |", pTemp->salary);
        printf("办公电话 %s |", pTemp->tel_office);
        printf("|任职时间 %s|\n", pTemp->office_age);
        printf("|QQ号 %s    |", pTemp->qq);
        printf("家庭住址 %s|", pTemp->address);
        printf("出勤次数%d |", pTemp->attendance);
        printf("早退次数%d|\n", pTemp->leave_earlier);
        printf("|加班次数%d|\n", pTemp->overtime);
        printf("--------------------------------------------------------\n");
        pTemp = pTemp->next;
    }
}
Employee *timecard(Employee *pHead)
{
    if (pHead == NULL)
    {
        printf("没有数据请返回!\n");
        return pHead;
    }
    system("clear");
    Employee *pTemp;
    pTemp = pHead->next;   //遍历指针
    char late[15];         //拉开时间
    unsigned long int num; //您的编号
    printf("1.出勤,2.请假.(如果在规定时间内提前下班为早退)\n");
    int x; //判断选项
    scanf("%d", &x);
    printf("请输入您的工号:\n");
    scanf("%ld", &num);
    getchar();
    while (pTemp)
    {
        if (pTemp->num == num)
        {
            switch (x)
            {
            case 1:
            {
                time_t timep;
                time(&timep);
                strcpy(pTemp->attendancetime, ctime(&timep));
                char times[15] = "18:00:00 2018";  //下班时间
                char atimes[15] = "08:00:00 2018"; //上班时间
                memcpy(late, pTemp->attendancetime + strlen(pTemp->attendancetime) - sizeof(late) + 1, 14);
                printf("您的出勤时间为%s\n", pTemp->attendancetime);
                pTemp->attendance++;
                if (strcmp(atimes, late) > 0)
                {
                    pTemp->attendance++;
                    printf("您签到成功！");
                }
                if (strcmp(times, late) > 0 && strcmp(atimes, late) < 0)
                {
                    pTemp->leave_earlier++;
                    printf("未到下班时间您属于早退！\n");
                }
                if (strcmp(times, late) < 0)
                {
                    pTemp->overtime++;
                    printf("您属于加班,请注意身体！\n");
                }
                break;
            }
            case 2:
            {
                printf("需要获得批准！\n");
                if (leave <= 5)
                {
                    sleep(1);
                    printf("请假成功！\n");
                    leave++;
                }
                break;
            }
            }
        }
        else
            printf("输入错误");
        pTemp = pTemp->next;
    }
    system("read -n 1");
    return pHead;
}
void QuickSort1(Employee *head, Employee *tail)
{
    if (head->next == tail || head->next->next == tail)
        return;

    Employee *mid = head->next;
    Employee *p = head;
    Employee *q = mid;
    int pivot = mid->attendance;
    Employee *t = mid->next;

    while (t != tail)
    {
        if (t->attendance > pivot)
            p = p->next = t;
        else
            q = q->next = t;
        t = t->next;
    }
    p->next = mid;
    q->next = tail;

    QuickSort1(head, mid);
    QuickSort1(mid, tail);
}

void achievement(Employee *pHead) //业绩评定管理按照出勤来排名
{
    if (pHead == NULL)
    {
        printf("没有数据请返回!\n");
        return;
    }
    QuickSort1(pHead, NULL);
    Print(pHead);
}
void report(Employee *pHead)
{
    if (pHead == NULL)
    {
        printf("没有数据请返回!\n");
        return;
    }
    Employee *pTemp;
    pTemp = pHead->next;

    summaryemp(pHead);
    printf("__________本月数据报表_____________\n");
    while (pTemp)
    {
        printf("|编号为:%ld |", pTemp->num);
        printf("姓名:%s   |", pTemp->name);
        printf("性别:%s |", pTemp->sex);
        printf(" 职务:%s |", pTemp->duty);
        printf("年龄:%d  |", pTemp->age);
        printf("工资:%d |", pTemp->salary);
        printf("办公电话:%s |", pTemp->tel_office);
        printf("家庭住址:%s |", pTemp->address);
        printf("任职时间%s |", pTemp->office_age);
        printf("|QQ号:%s | \n", pTemp->qq);
        pTemp = pTemp->next;
    }
    system("read -n 1");
}
int main()
{
    Employee *pHead;
    pHead = NULL;
    int flag = 3;
    int choice = 0;
    int i = 0;
    int m = 0;
    system("clear");
    do
    {
        menu(flag);
        int *get = (int *)malloc(SIZE);
        while (1)
        {
            get[i] = getch1();
            if (get[i] == '\n')
                break;
            if (get[i] == 0x41)
            {
                choice--;
                flag--;
                system("clear");
                menu(flag);
            }
            if (get[i] == 0x42)
            {
                choice++;
                flag++;
                system("clear");
                menu(flag);
            }
            i++;
        }
        free(get);
        if (choice == 10)
        {
            printf("正序选择1，逆序选择2\n");
            scanf("%d", &m);
            getchar();
        }
        switch (choice)
        {
        case 1:
        {
            pHead = Create(pHead);
            break;
        };
        case 2:
        {
            pHead = revise(pHead);
            system("clear");
            break;
        }
        case 3:
        {
            pHead = Delete(pHead);
            system("clear");
            break;
        }
        case 4:
        {
            serach(pHead);
            system("clear");
            break;
        }
        case 5:
        {
            Print(pHead);
            system("read -n 1");
            system("clear");
            break;
        }
        case 6:
        {
            input(pHead);
            system("clear");
            break;
        }
        case 7:
        {
            pHead = output();
            system("read -n 1");
            system("clear");
            break;
        }
        case 8:
        {
            pHead = add(pHead);
            system("clear");
            break;
        }
        case 9:
        {
            summaryemp(pHead);
            break;
        }
        case 10:
        {
            if (m == 1)
                QuickSort(pHead, NULL, 1);
            if (m == 2)
                QuickSort(pHead, NULL, 2);
            Print(pHead);
            break;
        }
        case 11:
        {
            timecard(pHead);
            system("clear");
        }
        break;
        case 12:
        {
            report(pHead);
        }
        break;
        case 13:
        {
            achievement(pHead);
        }
        break;
        case 14:
            exit(-1);
            break;
            //     menu();
        }

    } while (choice <= 13 || choice >= 1);

    return 0;
}
