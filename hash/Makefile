CFLAGS=-Wall -g

errors:
	rm -f hash
	make hash
	valgrind -v ./hash

origins:
	rm -f hash
	make hash
	valgrind --track-origins=yes ./hash

leaks:
	rm -f hash
	make hash
	valgrind --leak-check=full --show-leak-kinds=all ./hash

gdb:
	rm -f hash
	make hash
	gdb ./hash
