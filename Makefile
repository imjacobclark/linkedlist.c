CC=gcc

%.o: %.c
	$(CC) -c -o $@ $<

linkedlist: linkedlist.o
	$(CC) linkedlist.o -o linkedlist && rm *.o