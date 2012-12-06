#----------------------------------------------------------------------------
# Author: Team Amurica (Ben Nelson, Carlos Brennesein, Tucker McKnight, Scott Stromberg)
# Date: 2/22/11
#----------------------------------------------------------------------------



CC              = g++ 
CFLAGS          = -g -w -Wall -pedantic
CPPFLAGS        = $(CFLAGS)
LIBS            = -lcurl


################################################################
# ALL
#
# when you run make by itself, this is what it will try to create
#
all:crawler


################################################################
#
# Dependencies
#

crawler: Crawler.C Crawler.h Domain.C Domain.h Graph.C Graph.h Link.C Link.h HashTable.C HashTable.h LinkedList.C LinkedList.h LL_Node.C LL_Node.h Dictionary.C Dictionary.h Webpage.c Webpage.h

	$(CC) $(CFLAGS) $(LIBS) -o $@ Crawler.C Crawler.h Domain.C Domain.h Graph.C Graph.h Link.C Link.h HashTable.C HashTable.h LinkedList.C LinkedList.h LL_Node.C LL_Node.h Dictionary.C Dictionary.h Webpage.c Webpage.h

clean:
	rm -f *.o crawler