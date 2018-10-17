main:
	make -C ./module_student/
	make -C ./module_course/
	make -C ./init_infor/
	gcc -o main main.c -I ./include -L ./release/ -lstudent -lcourse -linit
clean :
	rm ./release/*.a main ./module_student/*.o  ./module_course/*.o ./init_infor/*.o
