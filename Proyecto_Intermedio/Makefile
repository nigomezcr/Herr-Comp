CXX=g++ -g
CXXFLAGS=-std=c++17
OBJECTS= main.o functions.o
SANITFLAGS=  -fsanitize=address -fsanitize=leak
VALGRINDFLAGS=--tool=memcheck --track-origins=yes --leak-check=full


all: execute

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


main.x: $(OBJECTS) functions.hpp
	$(CXX) $(CXXFLAGS) $(OBJECTS)  -o $@


execute: main.x
	./$<

#plot: execute # entropy.txt drop_size.txt plots.gp
#	gnuplot plots.gp

#walk.txt: main.x
#	./main.x > walk.txt

#walk.pdf: walk.gp walk.txt
#	gnuplot walk.gp

#show: walk.pdf
#	evince walk.pdf

#test

#gprof

#cachegrind

#memcheck

clean: 
	rm -f a.out *.x *.o *.txt *~ *.png
