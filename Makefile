
all: libhashtable.so libhashtable.o compile

libhashtable.so: lib/hashtable.c
	gcc lib/hashtable.c -o lib/libhashtable.so -fpic -shared

libhashtable.o: lib/hashtable.c
	gcc -c lib/hashtable.c -o lib/libhashtable.o

compile: example.c lib/hashtable.h lib/libhashtable.o
	gcc -c example.c -o hashtable-example.o
	gcc -o hashtable-example hashtable-example.o lib/libhashtable.o

install:
	cp -f lib/hashtable.h /usr/include/hashtable.h
	cp -f lib/libhashtable.so /usr/lib/libhashtable.so

uninstall:
	rm /usr/include/hashtable.h
	rm /usr/lib/libhashtable.so

clean:
	rm hashtable-example hashtable-example.o lib/libhashtable.o lib/libhashtable.so
