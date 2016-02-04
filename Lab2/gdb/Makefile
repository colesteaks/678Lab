STUDENT_ID=XXXXXXX

all: valgrind-test-build build

build:
	cd bash-4.2; ./configure; cd ..
	make -C ./bash-4.2 -j8 CFLAGS=-g

valgrind-test-build:
	gcc -O0 -Wall -g valgrind_test.c -o valgrind-test

test:
	./bash-4.2/bash finder.sh ./bash-4.2 execute 20

tar:
	-rm -f valgrind-test
	-make distclean -C bash-4.2
	mkdir $(STUDENT_ID)-gdb-lab
	cp -r bash-4.2 Makefile finder.sh $(STUDENT_ID)-gdb-lab
	tar cvzf $(STUDENT_ID)-gdb-lab.tar.gz $(STUDENT_ID)-gdb-lab
	rm -rf $(STUDENT_ID)-gdb-lab

