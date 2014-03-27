CC=g++
CFLAGS=-std=c++11 -Wall -Werror -c
LINK=g++
OBJS=main.o node.o haffuman.o

hfm		: $(OBJS)
	$(LINK) $(OBJS) -o hfm

main.o	: haffuman.h node.h main.cpp
	$(CC) $(CFLAGS) main.cpp

node.o	: node.h node.cpp
	$(CC) $(CFLAGS) node.cpp

haffuman.o	: haffuman.cpp haffuman.h node.h 
	$(CC) $(CFLAGS) haffuman.cpp

clean :
	rm -f $(OBJS)
