#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void deletecourse(int n)
{
    int i,j,k,s;
    FILE *fp,*fd;
    if((fp=fopen("/home/cl/myproject/init_infor/student.txt","w"))==NULL)
    {
        printf("can not open student.txt");
        exit(1);
    }
    if((fd=fopen("/home/cl/myproject/init_infor/course.txt","w"))==NULL)
    {
        printf("can not open course.txt");
        exit(1);
    }
     for(i=0;i<size_b;i++)
     {
          if(b[i].num==n)
          {
            for(s=0;s<size_a;s++)
              for(k=0;k<a[s].stu_cou_num;k++)
              {
                  if(strcmp(a[s].stu_course[k],b[i].name)==0)
                  {
                      for(j=k;j<a[s].stu_cou_num;j++)
                        strcpy(a[s].stu_course[j],a[s].stu_course[j+1]);
                      a[s].total_score-=b[i].score;
                      a[s].stu_cou_num--;
                  }
              }
              for(j=i;j<size_b-1;j++)
                  b[j]=b[j+1];
              size_b--;
              break;
          }
     }
     for(i=0;i<size_a;i++)
     {
         fprintf(fp,"%d %s ",a[i].num,a[i].name);
         for(j=0;j<a[i].stu_cou_num;j++)
            fprintf(fp,"%s ",a[i].stu_course[j]);
         fprintf(fp,"%.1f\n",a[i].total_score);
     }
     for(i=0;i<size_b;i++)
        fprintf(fd,"%d %s %s %.1f %.1f %d %d\n",b[i].num,b[i].name,b[i].nature,b[i].hour,b[i].score,b[i].selected_num,b[i].online_num);
     fclose(fp);
     fclose(fd);
}





