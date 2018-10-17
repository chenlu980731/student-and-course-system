#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void changecourse(int p)
{
    int i,flag,n,s,k,j,w;
    float x;
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
    char c[20]={0};
    printf("请输入需要修改该课程信息的选项: \n");
    printf("1.编号\n");
    printf("2.课程名称\n");
    printf("3.课程性质 \n");
    printf("4.授课学时\n");
    printf("5.学分\n");
    printf("6.课程已选人数\n");
    printf("7.课程人数上限\n");
    printf("请输入选项: ");
    scanf("%d",&n);
    while(n>7||n<1)
    {
        printf("-----请输入正确的选项!!!-----\n\n");
        printf("请输入需要修改该课程信息的选项: \n");
        printf("1.编号\n");
        printf("2.课程名称\n");
        printf("3.课程性质 \n");
        printf("4.授课学时\n");
        printf("5.学分\n");
        printf("6.课程已选人数\n");
        printf("7.课程人数上限\n");
        printf("请输入选项: ");
        scanf("%d",&n);
    }
    for(i=0;i<size_b;i++)
    {
        flag=0;
        if(b[i].num==p)
        {
            flag=1;
            switch(n)
            {
                case 1:
                     {
                        printf("请输入修改的编号: ");
                        scanf("%d",&n);
                        b[i].num=n;
                        break;
                     }
                case 2:
                     {
                        printf("请输入修改的课程名称: ");
                        scanf("%s",c);
                        for(s=0;s<size_a;s++)
                        {
                          for(j=0;j<a[s].stu_cou_num;j++)
                             if(strcmp(b[i].name,a[s].stu_course[j])==0)
                                 strcpy(a[s].stu_course[j],c);
                        }
                        strcpy(b[i].name,c);
                        for(i=0;i<size_b;i++)
                          fprintf(fd,"%d %s %s %.1f %.1f %d %d\n",b[i].num,b[i].name,b[i].nature,b[i].hour,b[i].score,b[i].selected_num,b[i].online_num);
                        break;
                     }
                case 3:
                     {
                        printf("请输入修改的课程性质: ");
                        scanf("%s",c);
                        strcpy(b[i].nature,c);
                        break;
                     }
                case 4:
                     {
                        printf("请输入修改的授课学时: ");
                        scanf("%f",&x);
                        b[i].hour=x;
                        break;
                     }
                case 5:
                     {
                        printf("请输入修改的学分: ");
                        scanf("%f",&x);
                        for(s=0;s<size_a;s++)
                        {
                          w=b[i].score;
                          for(j=0;j<a[s].stu_cou_num;j++)
                             if(strcmp(b[i].name,a[s].stu_course[j])==0)
                             {
                                w-=x;
                                a[s].total_score-=w;
                             }
                        }
                        b[i].score=x;
                        for(i=0;i<size_b;i++)
                          fprintf(fd,"%d %s %s %.1f %.1f %d %d\n",b[i].num,b[i].name,b[i].nature,b[i].hour,b[i].score,b[i].selected_num,b[i].online_num);
                        break;
                     }
                case 6:
                     {
                        printf("请输入修改的课程已选人数: ");
                        scanf("%d",&n);
                        b[i].selected_num=n;
                        break;
                     }
                case 7:
                     {
                        printf("请输入修改的课程人数上限: ");
                        scanf("%d",&n);
                        b[i].online_num=n;
                        break;
                     }

              }
              break;
         }
      }
      if(flag==0)
        printf("don't find this student information!!");
      for(i=0;i<size_a;i++)
      {
         fprintf(fp,"%d %s ",a[i].num,a[i].name);
         for(j=0;j<a[i].stu_cou_num;j++)
            fprintf(fp,"%s ",a[i].stu_course[j]);
         fprintf(fp,"%.1f\n",a[i].total_score);
      }
      fclose(fd);
      fclose(fp);
}
