VERBOSE=0
all:
	g++ main.cpp -o a
	./a
	make clean

clean:
	rm -rf *o a
