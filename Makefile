VERBOSE=0
all:
	g++ main.cpp functions.cpp -g -o a
	./a
	#make clean

clean:
	rm -rf *o a
