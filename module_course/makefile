addcourse.o:changecourse.o
	gcc -c addcourse.c -o addcourse.o -I ../include
	ar -rsv ../release/libcourse.a *.o
changecourse.o:deletecourse.o
	gcc -c changecourse.c -o changecourse.o -I ../include
deletecourse.o:searchcourse.o
	gcc -c deletecourse.c -o deletecourse.o -I ../include
searchcourse.o:
	gcc -c searchcourse.c -o searchcourse.o -I ../include

clean:
	rm *.o