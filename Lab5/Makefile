# Defined constants for command base name and arguments for simple test
#
STUDENT_ID=XXXXXXX
PTC=ptcount
LOOP=1000000
INC=1

(PTC): $(PTC).c
	gcc -g  -o $(PTC) $(PTC).c -lpthread

test: $(PTC)
	./$(PTC) $(LOOP) $(INC)

clean:
	rm -f $(PTC)

submit:
	make clean
	mkdir $(STUDENT_ID)-pthreads_intro-lab
	cp ptcount.c ptcount-c.txt
	cp Makefile Makefile.txt
	mv ptcount-c.txt Makefile.txt $(STUDENT_ID)-pthreads_intro-lab/
	zip -r $(STUDENT_ID)-pthreads_intro-lab $(STUDENT_ID)-pthreads_intro-lab
	rm -rf $(STUDENT_ID)-pthreads_intro-lab

.PHONY: test clean submit
