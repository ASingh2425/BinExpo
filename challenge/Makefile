all:
	gcc -fstack-protector -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now -no-pie -o dream_heap dream_heap.c

clean:
	rm -f dream_heap
