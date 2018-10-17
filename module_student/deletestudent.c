#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void deletestudent(int n)
{

    int i,j,s;
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
     for(i=0;i<size_a;i++)
     {
          if(a[i].num==n)
          {
            for(j=0;j<a[i].stu_cou_num;j++)
            {
                 for(s=0;s<size_b;s++)
                    if(strcmp(b[s].name,a[i].stu_course[j])==0)
                    {
                        b[s].selected_num--;
                        break;
                    }
            }
            for(j=i;j<size_a-1;j++)
              a[j]=a[j+1];
            size_a--;
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
     for(s=0;s<size_b;s++)
         fprintf(fd,"%d %s %s %.1f %.1f %d %d\n",b[s].num,b[s].name,b[s].nature,b[s].hour,b[s].score,b[s].selected_num,b[s].online_num);
    fclose(fp);
    fclose(fd);
}





