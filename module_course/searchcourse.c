#include <stdio.h>
#include <string.h>
#include "main.h"

void searchcourse(char cou[N])
{

    int m=0,i=0,j,k;
    if(cou[i]>='0'&&cou[i]<='9')
    {
       while(cou[i]>='0'&&cou[i]<='9')
       {
          m=m*10+cou[i]-'0';
          i++;
       }
       for(i=0;i<size_b;i++)
          if(b[i].num==m)
          {
             j=i;
             break;
          }
       if(i>=size_b)
       {
          j=-1;
          printf("Don't have this course information!");
       }
    }
    else
    {
       for(i=0;i<size_b;i++)
          if(strcmp(cou,b[i].name)==0)
          {
              j=i;
              break;
          }
       if(i>=size_b)
       {
           j=-1;
           printf("Don't have this course information!");
       }
    }
    if(j!=-1)
        printf("%d %s %s %.1f %.1f %d %d\n",b[i].num,b[i].name,b[i].nature,b[i].hour,b[i].score,b[i].selected_num,b[i].online_num);
}



