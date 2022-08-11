#Use to compile program and run
all:
	make Rail_fence_cipher && make run
#Use to compile	
Rail_fence_cipher:
	gcc -Wall -pedantic -o Rail_fence_cipher Rail_fence_cipher.c
#Use to run executable	
run:
	./Rail_fence_cipher
#Use to delete executable	
clean:
	rm Rail_fence_cipher