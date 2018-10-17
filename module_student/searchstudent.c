#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void searchstudent(char stu[N])
{
    int m=0,i=0,j,k;
    if(stu[i]>='0'&&stu[i]<='9')
    {
       while(stu[i]>='0'&&stu[i]<='9')
       {
          m=m*10+stu[i]-'0';
          i++;
       }
       for(i=0;i<size_a;i++)
          if(a[i].num==m)
          {
             j=i;
             break;
          }
       if(i>=size_a)
       {
          j=-1;
          printf("!!!没有你所查找的学生信息!!!");
       }
    }
    else
    {
       for(i=0;i<size_a;i++)
          if(strcmp(stu,a[i].name)==0)
          {
              j=i;
              break;
          }
       if(i>=size_a)
       {
           j=-1;
          printf("!!!没有你所查找的学生信息!!!");
       }
    }
    if(j!=-1)
    {
        printf("%d %s ",a[j].num,a[j].name);
        k=a[j].stu_cou_num;
        for(i=0;i<k;i++)
        {
           printf("%s ",a[j].stu_course[i]);
        }
        printf("%.1f\n",a[j].total_score);
    }
}



