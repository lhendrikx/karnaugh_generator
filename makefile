CC=gcc
DEPS = karnaugh.h
OBJ = karnaugh.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

karnaugh: $(OBJ)
	$(CC) -o $@ $^
