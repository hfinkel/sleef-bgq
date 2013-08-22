all : tester testersp testeru1 testerspu1

tester : tester.c
	gcc -g -Wall tester.c -lm -lmpfr -o tester

testeru1 : testeru1.c
	gcc -g -Wall testeru1.c -lm -lmpfr -o testeru1

testersp : testersp.c
	gcc -g -Wall testersp.c -lm -lmpfr -o testersp

testerspu1 : testerspu1.c
	gcc -g -Wall testerspu1.c -lm -lmpfr -o testerspu1

clean :
	rm -f *~ *.o tester testersp testeru1 testerspu1
