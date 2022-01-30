q2.exe : q2.o mystring.o myword.o
	gcc q2.o mystring.o myword.o -o q2.exe

q2.o : myword_main.c
	gcc -c myword_main.c -o q2.o

myword.o : myword.h myword.c
	gcc -c myword.c -o myword.o

mystring.o : mystring.h mystring.c
	gcc -c mystring.c -o mystring.o

run: q2.exe
	q2.exe

clean :
	rm q2.o mystring.o myword.o q2.exe
