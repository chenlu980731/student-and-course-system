#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void file_stu_init()
{
    FILE *fp;
    char c;
    int i=0,j,k=0;
    if((fp=fopen("/home/cl/myproject/init_infor/student.txt","r"))==NULL)
    {
        printf("can not open student.txt");
        exit(1);
    }
    while(!feof(fp))
    {
        j=0;
        a[i].stu_cou_num=0;
        fscanf(fp,"%d %s ",&a[i].num,a[i].name);
        c=fgetc(fp);
        while((c<'0'|| c>'9'))
         {
               if(c==' ')
               {
                  a[i].stu_course[j][k]='\0';
                  k=0;
                  j++;
               }
              else
                  a[i].stu_course[j][k++]=c;
              c=fgetc(fp);
         }
         a[i].stu_cou_num=j;
         fseek(fp,-1,1);
         fscanf(fp,"%f ",&a[i].total_score);
         i++;
    }
    size_a=i;
    fclose(fp);
}
