file_stu_init.o : keyboard_stu_init.o
	gcc -c file_stu_init.c -o file_stu_init.o -I ../include
	ar -rsv ../release/libinit.a *.o
keyboard_stu_init.o : file_cou_init.o
	gcc -c keyboard_stu_init.c -o keyboard_stu_init.o -I ../include
file_cou_init.o :keyboard_cou_init.o
	gcc -c file_cou_init.c -o file_cou_init.o -I ../include
keyboard_cou_init.o:
	gcc -c keyboard_cou_init.c -o keyboard_cou_init.o -I ../include
clean :
	rm *.o
