EXEC=cat_popen fork_pipe f_pipe

all:${EXEC}

%:%.c
	gcc -std=gnu99 $^ -o $@

.PHONY: clean
clean:
	rm -rf ${EXEC}
