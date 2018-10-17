#include <stdio.h>
#include <stdlib.h>
#include "main.h"
void keyboard_stu_init()
{
    int i,j=0;
    FILE *fp;
    if((fp=fopen("/home/cl/myproject/init_infor/student.txt","w"))==NULL)
    {
        printf("can not open student.txt");
        exit(1);
    }
    printf("请输入初始化的学生人数: ");
    scanf("%d",&size_a);
    for(i=0;i<size_a;i++)
    {
        printf("请输入第%d学生的学号: ",i+1);
        scanf("%d",&a[i].num);
        fprintf(fp,"%d ",a[i].num);
        printf("请输入第%d学生的姓名: ",i+1);
        scanf("%s",a[i].name);
        fprintf(fp,"%s ",a[i].name);
        printf("请输入选的课程数: ");
        scanf("%d",&a[i].stu_cou_num);
        printf("请输入学生选的课程: ");
        for(j=0;j<a[i].stu_cou_num;j++)
        {
            scanf("%s",a[i].stu_course[j]);
            fprintf(fp,"%s ",a[i].stu_course[j]);
        }
        printf("请输入学生已选课程总计学分: ");
        scanf("%f",&a[i].total_score);
        fprintf(fp,"%.1f\n",a[i].total_score);
    }
    fclose(fp);
}
