#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void file_cou_init()
{
    FILE *fp;
    int i=0;
    if((fp=fopen("/home/cl/myproject/init_infor/course.txt","r"))==NULL)
    {
        printf("can not open student.txt");
        exit(1);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %s %f %f %d %d ",&b[i].num,b[i].name,b[i].nature,&b[i].hour,&b[i].score,&b[i].selected_num,&b[i].online_num);
        i++;
    }
    size_b=i;
    fclose(fp);
}
