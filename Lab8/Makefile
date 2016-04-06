# Add the dp_asymmetric and dp_waiter targets to all as you implement
# them
#
MY_LAST_NAME = "jurden"
STUDENT_ID = 2415098

all: main.o
	gcc -lm main.o -o main

main.o: main.c
	gcc -Wall -c main.c

clean:
	rm -f main.o

tar:
	make clean
	mkdir $(STUDENT_ID)-qsort-lab
	cp Makefile main.c process.txt $(STUDENT_ID)-qsort-lab/
	tar cvzf $(STUDENT_ID)-qsort-lab.tar.gz $(STUDENT_ID)-qsort-lab
	rm -rf $(STUDENT_ID)-qsort-lab
