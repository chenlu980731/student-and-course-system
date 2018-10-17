#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void keyboard_cou_init()
{
    int i;
    FILE *fp;
    if((fp=fopen("/home/cl/myproject/init_infor/course.txt","w"))==NULL)
    {
        printf("can not open student.txt");
        exit(1);
    }
    printf("请输入初始化的课程数: ");
    scanf("%d",&size_b);
    for(i=0;i<size_b;i++)
    {
        printf("请输入第%d科课程的编号: ",i+1);
        scanf("%d",&b[i].num);
        fprintf(fp,"%d ",b[i].num);
        printf("请输入第%d科课程的名字: ",i+1);
        scanf("%s",b[i].name);
        fprintf(fp,"%s ",b[i].name);
        printf("请输入第%d科课程的性质: ",i+1);
        scanf("%s",b[i].nature);
        fprintf(fp,"%s ",b[i].nature);
        printf("请输入第%d科课程的授课学时: ",i+1);
        scanf("%f",&b[i].hour);
        fprintf(fp,"%.1f ",b[i].hour);
        printf("请输入第%d科课程的学分: ",i+1);
        scanf("%f",&b[i].score);
        fprintf(fp,"%.1f ",b[i].score);
        printf("请输入第%d科课程的已选人数: ",i+1);
        scanf("%d",&b[i].selected_num);
        fprintf(fp,"%d ",b[i].selected_num);
        printf("请输入第%d科课程的人数上限: ",i+1);
        scanf("%d",&b[i].online_num);
        fprintf(fp,"%d\n",b[i].online_num);
    }
    fclose(fp);
}

