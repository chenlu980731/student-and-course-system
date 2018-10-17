addstudent.o:changestudent.o
	gcc -c addstudent.c -o addstudent.o -I ../include
	ar -rsv ../release/libstudent.a *.o
changestudent.o:deletestudent.o
	gcc -c changestudent.c -o changestudent.o -I ../include
deletestudent.o:searchstudent.o
	gcc -c deletestudent.c -o deletestudent.o -I ../include
searchstudent.o:
	gcc -c searchstudent.c -o searchstudent.o -I ../include

clean:
	rm *.o
