CFLAGS=-Wall -g

errors:
	rm -f stringtest
	make hash
	valgrind -v ./hash

origins:
	rm -f stringtest
	make hash
	valgrind --track-origins=yes ./hash
