#ifndef _MAIN_
#define _MAIN_
#define N 20
typedef struct
{
   int num;
   char name[N];
   char stu_course[N][N];
   float total_score;
   int stu_cou_num;
}stu;
stu a[50];
int size_a;
typedef struct
{
   int num;
   char name[N];
   char nature[N];
   float hour;
   float score;
   int selected_num;
   int online_num;
}course;
course b[50];
int size_b;
void file_stu_init();
void file_cou_init();
void keyboard_stu_init();
void keyboard_cou_init();

void addcourse(int n);
void deletecourse(int n);
void searchcourse(char cou[N]);
void changecourse(int p);

void addstudent(int n);
void deletestudent(int n);
void changestudent(int p);
void searchstudent(char stu[N]);
FILE *fs;
#endif
