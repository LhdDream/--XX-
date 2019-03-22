#pragma once
#ifndef QUICKSORT_H_
#define QUICKSORT_H_
#include"common.h"
//快速排序
void QuickSort( Employee *head, Employee *tail,int x )
{
    if(head==NULL)
      {
          printf("没有数据请返回!\n");
          return ;                                                       
      }     
    if ( head->next==tail || head->next->next == tail )
		return;
	Employee * mid = head->next;
	Employee * p = head;
	Employee * q = mid;
	int pivot = mid->salary;
	Employee * t = mid->next;
	while ( t != tail ) {
	   if(x==1)
       {
        if ( t->salary < pivot )
			p = p->next = t;
		else
			q = q->next = t;
       }
       if(x==2)
       {
           if(t->salary>pivot)
               p=p->next=t;
           else
               q=q->next=t;
       }
		t = t->next;
	}
	p->next = mid;
	q->next = tail;

	QuickSort( head, mid,x );
	QuickSort( mid, tail,x );
}
//采用递归的方式进行排序
#endif
