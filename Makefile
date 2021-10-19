all:
	gcc isys/tinyexpr.c -c
	g++ isys.cpp tinyexpr.o -g -o isyspp