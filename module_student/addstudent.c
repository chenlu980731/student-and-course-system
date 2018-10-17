#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
void addstudent(int n)
{
    int i,j,k,s,m;
    k=size_a;
    FILE *fp,*fd;
    if((fp=fopen("/home/cl/myproject/init_infor/student.txt","a+"))==NULL)
    {
        printf("can not open student.txt");
        exit(1);
    }
    if((fd=fopen("/home/cl/myproject/init_infor/course.txt","w"))==NULL)
    {
        printf("can not open course.txt");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        m=0;
        printf("请输入第%d位学生学号: ",i+1);
        scanf("%d",&a[k+i].num);
        fprintf(fp,"%d ",a[k+i].num);
        fprintf(fs,"%d ",a[k+i].num);
        printf("请输入第%d位学生的姓名：",i+1);
        scanf("%s",a[k+i].name);
        fprintf(fp,"%s ",a[k+i].name);
        fprintf(fs,"%s ",a[k+i].name);
        printf("请输入第%d位选的课程数: ",i+1);
        scanf("%d",&a[k+i].stu_cou_num);
        a[k+i].total_score=0;
        for(j=0;j<a[k+i].stu_cou_num;j++)
        {
            printf("请输入第%d位学生选的第%d门课程: ",i+1,j+1);
            scanf("%s",a[k+i].stu_course[j]);
            for(s=0;s<size_b;s++)
                if(strcmp(b[s].name,a[k+i].stu_course[j])==0)
                {
                    if(b[s].selected_num==b[s].online_num)
                    {
                        m++;
                        printf("课程人数已经到达上限，无法进行添加!!!\n");
                    }
                    else
                    {
                        b[s].selected_num++;
                        fprintf(fp,"%s ",a[k+i].stu_course[j]);
                        fprintf(fs,"%s ",a[k+i].stu_course[j]);
                        a[k+i].total_score+=b[s].score;
                    }
                    break;
                }
            if(s>=size_b)
            {
                 printf("课程系统中没有选的这门课!!!\n");
            }
        }
        fprintf(fp,"%.1f\n",a[k+i].total_score);
        fprintf(fs,"%.1f  ",a[k+i].total_score);
        a[k+i].stu_cou_num-=m;
    }
    fprintf(fs,"%s","\n");
    for(s=0;s<size_b;s++)
        fprintf(fd,"%d %s %s %.1f %.1f %d %d\n",b[s].num,b[s].name,b[s].nature,b[s].hour,b[s].score,b[s].selected_num,b[s].online_num);
    size_a+=n;
    fclose(fp);
    fclose(fd);
}