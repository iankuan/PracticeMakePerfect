all: hello
hello.i: hello.c
	gcc -E hello.c -o hello.i

hello.s: hello.i
	gcc -S hello.i -o hello.s

hello.o: hello.s
	gcc -c hello.s -o hello.o

hello: hello.o
	objdump -x -s -d hello.o
	ld -static ctr1.o crti.o ctrbeginT.o hello.o \
		-start-group -lgcc -lgcc_eh -lc -end-group crtend.o crtn,o -o hello
