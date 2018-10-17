#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void changestudent(int p)
{
    int k,i,n,j,s,x,temp,flag,flag2;
    float m;
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
    printf("请输入需要修改该学生信息的选项: \n");
    printf("1.学号\n");
    printf("2.姓名\n");
    printf("3.选课列表\n");
    printf("请输入选项: ");
    scanf("%d",&n);
    while(n>4||n<1)
    {
          printf("-----请输入正确的选项!!!-----\n\n");
          printf("请输入需要修改该学生信息的选项: \n");
          printf("1.学号\n");
          printf("2.姓名\n");
          printf("3.选课列表\n");
          printf("请输入选项: ");
          scanf("%d",&n);
    }
    for(i=0;i<size_a;i++)
    {
        flag=0;
        if(a[i].num==p)
        {
            flag=1;
            switch(n)
            {
                case 1:
                     {
                        printf("请输入修改的学号: ");
                        scanf("%d",&n);
                        a[i].num=n;
                        break;
                     }
                case 2:
                     {
                        printf("请输入修改的姓名: ");
                        scanf("%s",c);
                        strcpy(a[i].name,c);
                        break;
                     }
                case 3:
                     {
                       flag=1;
                       while(flag2)
                       {
                        printf("请输入对于课程列表修改的选项: \n");
                        printf("1.增加课程\n");
                        printf("2.删除课程\n");
                        printf("请输入选项: ");
                        scanf("%d",&n);
                        switch(n)
                        {
                            case 1:
                                 {
                                    flag2=0;
                                    printf("请输入增加的课程数量: ");
                                    scanf("%d",&n);
                                    for(j=0;j<n;j++)
                                    {
                                         printf("请输入增加的课程名: ");
                                         scanf("%s",c);
                                         for(s=0;s<size_b;s++)
                                            if(strcmp(b[s].name,c)==0)
                                            {
                                                if(b[s].selected_num==b[s].online_num)
                                                {
                                                    printf("课程人数已经到达上限，无法进行添加!!!\n");
                                                }
                                                else
                                               {
                                                b[s].selected_num++;
                                                strcpy(a[i].stu_course[a[i].stu_cou_num],c);
                                                a[i].stu_cou_num++;
                                                a[i].total_score+=b[s].score;
                                               }
                                               break;
                                            }
                                         if(s>=size_b)
                                         {
                                               printf("课程系统中没有选的这门课!!!\n");
                                         }
                                    }
                                    break;
                                 }
                            case 2:
                                 {
                                    flag2=0;
                                    printf("请输入删除的课程数量: ");
                                    scanf("%d",&n);
                                    for(j=0;j<n;j++)
                                    {
                                         temp=0;
                                         if(a[i].stu_cou_num==0)
                                         {    printf("选课列表为空，无法继续删除课程！！\n");
                                              break;
                                         }
                                         printf("请输入删除的课程名: ");
                                         scanf("%s",c);
                                         for(s=0;s<a[i].stu_cou_num;s++)
                                         {
                                             if(strcmp(a[i].stu_course[s],c)==0)
                                             {
                                                 temp=1;
                                                 for(k=0;k<size_b;k++)
                                                    if(strcmp(c,b[k].name)==0)
                                                    {
                                                       b[k].selected_num--;
                                                       break;
                                                    }
                                                 for(x=s;x<a[i].stu_cou_num-1;x++)
                                                    strcpy(a[i].stu_course[x],a[i].stu_course[x+1]);
                                                 a[i].stu_cou_num--;
                                                 a[i].total_score-=b[k].score;
                                                 break;
                                             }
                                         }
                                         if(temp==0)
                                            printf("!!!不存在你要删除的课程!!!");
                                    }
                                    break;
                                 }
                             default: printf("!!!请输入正确的选项!!!\n");
                          }
                        }
                         break;
                     }
              }
              break;
         }
      }
      if(flag==0)
        printf("!!!不存在你需要修改的学生的信息!!!\n");
      else
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
