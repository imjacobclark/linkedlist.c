CC=gcc

linkedlist: linkedlist.c
	$(CC) $^ -o $@
	./$@

run: linkedlist
	./$^
