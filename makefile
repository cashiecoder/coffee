install: all
	cp coffee.man /usr/local/share/man/man1/coffee.1
	cp coffee /usr/local/bin

all: coffee

coffee: coffee.o
	gcc -o coffee coffee.o

coffee.o: coffee.c
	gcc -c coffee.c