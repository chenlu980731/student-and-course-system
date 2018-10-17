#!/bin/bash
echo "修改学生信息的次数:";
cat operation.log | grep "student" | wc -l
echo "修改课程信息的次数:";
cat operation.log | grep "course" | wc -l

echo "------------------------------------------"

read -p "请输入要查找的修改学生的学号:" stu
cat operation.log | awk '$2=="student" && $3=='$stu' {print $0}'

echo "------------------------------------------"

read -p "请输入要查找的修改课程的编号:" cou
cat operation.log | awk '$2=="course" && $3=='$cou' {print $0}'
