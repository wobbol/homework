CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
OUTPUTNAME=zipper_v2

info:
	print "this is something"
	echo "this is anotyhre thing"
	echo "-D __debug_large_loop -D __debug_init_struct"

zipper:
	$(CC) zipper_v2.c -o $(OUTPUTNAME)
	
zipper_debug:
	$(CC) zipper_v2.c -o $(OUTPUTNAME)_d -ggdb

.PHONY: info