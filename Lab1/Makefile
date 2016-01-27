all: simple.o
	gcc -lm simple.o -o simple

simple.o: simple.c simple.h
	gcc -Wall -c simple.c

tar: 
	mkdir editors
	cp dot_vimrc Makefile simple.* editors/
	tar cvzf eecs678-editors-lab.tar.gz editors
	rm -rf editors
