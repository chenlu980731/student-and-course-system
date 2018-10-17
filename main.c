#include <stdio.h>
#include <stdlib.h>
#include "main.h"
void main()
{
    int flag=1;
    printf("\n\nWelcome To Student Selection Management System");
    if((fs=fopen("./operation.log","a+"))==NULL)
    {
        printf("can not open operation.log");
        exit(1);
    }
    while(flag)
    {
      int n;
      char b[20]={0};
      printf("\n请选择功能的对应选项:\n");
      printf("\n===========================================\n\n");
      printf("1.初始化学生信息、课程信息\n");
      printf("2.查看学生的详细信息\n");
      printf("3.添加新的学生信息\n");
      printf("4.修改学生的信息\n");
      printf("5.删除学生信息\n");
      printf("6.查看课程的详细信息\n");
      printf("7.添加新的课程信息\n");
      printf("8.修改课程的信息\n");
      printf("9.删除课程信息\n");
      printf("10.退出\n");
      printf("\n===========================================\n\n");
      printf("请输入选择的功能序号: ");
      scanf("%d",&n);
      switch(n)
      {
          case 1:{
                      printf("请输入初始化的方式:\n");
                      printf("1.通过键盘输入方式初始化\n");
                      printf("2.通过文件方式初始化\n");
                      printf("\n请输入初始化方式序号: ");
                      scanf("%d",&n);
                      switch(n)
                      {
                         case 1:{
                                  printf("学生系统初始化:\n");
                                  keyboard_stu_init();
                                  printf("学生系统初始化完毕!\n");
                                  printf("课程系统初始化:\n");
                                  keyboard_cou_init();
                                  printf("课程系统初始化完毕!\n");
                                  break;
                                }
                         case 2:{file_stu_init(); file_cou_init(); break;}
                      }
                      break;
                  }
          case 2:{
                      file_stu_init();
                      printf("请输入你要查看学生的学号或姓名: ");
                      scanf("%s",b);
                      searchstudent(b);
                      break;
                 }
          case 3:{
                      file_stu_init();
                      file_cou_init();
                      fprintf(fs,"%s","add student ");
                      printf("请输入要添加学生信息的学生数: ");
                      scanf("%d",&n);
                      addstudent(n);
                      break;
                 }
          case 4:{
                      file_stu_init();
                      file_cou_init();
                      fprintf(fs,"%s","change student ");
                      printf("请输入要修改学生信息的学生学号: ");
                      scanf("%d",&n);
                      fprintf(fs,"%d\n",n);
                      changestudent(n);
                      break;
                 }
          case 5:{
                      file_stu_init();
                      file_cou_init();
                      fprintf(fs,"%s","delete student ");
                      printf("请输入要删除学生信息的学生学号: ");
                      scanf("%d",&n);
                      fprintf(fs,"%d\n",n);
                      deletestudent(n);
                      break;
                 }
          case 6:{
                      file_stu_init();
                      file_cou_init();
                      printf("请输入你要查看课程的编号或名字: ");
                      scanf("%s",b);
                      searchcourse(b);
                      break;
                 }
          case 7:{
                      file_stu_init();
                      file_cou_init();
                      fprintf(fs,"%s","add course ");
                      printf("请输入要添加课程的数量: ");
                      scanf("%d",&n);
                      fprintf(fs,"num:%d ",n);
                      addcourse(n);
                      break;
                 }
          case 8:{
                      file_stu_init();
                      file_cou_init();
                      fprintf(fs,"%s","change course ");
                      printf("请输入要修改课程信息的课程编号: ");
                      scanf("%d",&n);
                      changecourse(n);
                      break;
                 }
          case 9:{
                      file_stu_init();
                      file_cou_init();
                      fprintf(fs,"%s","delete course ");
                      printf("请输入要删除课程信息的课程编号: ");
                      scanf("%d",&n);
                      fprintf(fs,"%d\n",n);
                      deletecourse(n);
                      break;
                 }
         case 10:{   flag=0; break;}
         default: printf("!!!please input correct num!!!");
      }
   }
   fclose(fs);
}

