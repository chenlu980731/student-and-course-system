#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void addcourse(int n)
{
    int i;
    FILE *fp;
    if((fp=fopen("/home/cl/myproject/init_infor/course.txt","a+"))==NULL)
    {
        printf("can not open student.txt");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        printf("请输入新增的第%d科课程的编号: ",i+1);
        scanf("%d",&b[size_b+i].num);
        fprintf(fp,"%d ",b[size_b+i].num);
        fprintf(fs,"%d ",b[size_b+i].num);
        printf("请输入新增的第%d科课程的名字: ",i+1);
        scanf("%s",b[size_b+i].name);
        fprintf(fp,"%s ",b[size_b+i].name);
        fprintf(fs,"%s ",b[size_b+i].name);
        printf("请输入新增的第%d科课程的性质: ",i+1);
        scanf("%s",b[size_b+i].nature);
        fprintf(fp,"%s ",b[size_b+i].nature);
        fprintf(fs,"%s ",b[size_b+i].nature);
        printf("请输入新增的第%d科课程的授课学时: ",i+1);
        scanf("%f",&b[size_b+i].hour);
        fprintf(fp,"%.1f ",b[size_b+i].hour);
        fprintf(fs,"%.1f ",b[size_b+i].hour);
        printf("请输入新增的第%d科课程的学分: ",i+1);
        scanf("%f",&b[size_b+i].score);
        fprintf(fp,"%.1f ",b[size_b+i].score);
        fprintf(fs,"%.1f ",b[size_b+i].score);
        printf("请输入新增的第%d科课程的已选人数: ",i+1);
        scanf("%d",&b[size_b+i].selected_num);
        fprintf(fp,"%d ",b[size_b+i].selected_num);
        fprintf(fs,"%d ",b[size_b+i].selected_num);
        printf("请输入新增的第%d科课程的人数上限: ",i+1);
        scanf("%d",&b[size_b+i].online_num);
        fprintf(fp,"%d\n",b[size_b+i].online_num);
        fprintf(fs,"%d  ",b[size_b+i].online_num);
    }
    fprintf(fs,"%s","\n");
    size_b+=n;
    fclose(fp);
}


