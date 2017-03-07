ifdef DEBUG
	DFLAGS = -g
else
	DFLAGS = 
endif
all: serv cli

serv: serv.c
	gcc $< -o $@ -pthread -lrt $(DFLAGS)

cli: cli.c
	gcc $< -o $@ -pthread -lrt $(DFLAGS)

clean:
	rm -f serv cli
