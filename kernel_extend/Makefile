EXEC = kernel_macro.out

.PHONY: all, clean

all: $(EXEC)

%.out: %.c
	gcc -std=gnu99 $^ -o $@ -g

clean:
	rm $(EXEC)
