# -*- Makefile -*-

# list/Makefile
#
# Makefile for list implementation and test file.
#
# Manish Basnet


list: main.o list.o
	gcc main.o list.o -o list
	
main.o: main.c
	gcc -c main.c
	
list.o: list.c
	gcc -c list.c
	
	