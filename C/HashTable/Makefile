# Cooper Trowbridge
# January 2014
# WordSearch Makefile

CFLAGS = -Wall -g

errors:
	rm -f hash
	make hash
	valgrind -v ./hash
leaks:
	rm -f hash
	make hash
	valgrind --leak-check=full --show-leak-kinds=all ./hash
gdb:
	rm -f hash
	make hash
	gdb ./hash
