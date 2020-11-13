CXX=g++ 
CXXFLAGS=-std=c++17  -g
OBJECTS= main.o functions.o
SANITFLAGS=  -fsanitize=address -fsanitize=leak
VALGRINDFLAGS=--tool=memcheck  --track-origins=yes --leak-check=full

##################################################################

all: sanitize

%.o:  %.cpp %.hpp erase 
	$(CXX)  -c  $< -o  $@

sanitize: $(OBJECTS)
	$(CXX)  $(CXXFLAGS) $(SANITFLAGS)  $^  -o main.x
	./main.x 
	@echo "END RUN WITH SANITIZERS"


##################################################################

main.x: $(OBJECTS)
	$(CXX) -pg $(CXXFLAGS)  $^  -o main.x

memcheck: main.x
	valgrind $(VALGRINDFLAGS) ./$<
	@echo "END RUN WITH VALGRIND"


##################################################################

gprof: main.x
	./$<
	gprof ./$< > gprof-report.txt
	@echo "END RUN WITH PROFILING"

cachegrind: main.x main.cpp functions.cpp
	./$<
	valgrind --tool=cachegrind ./$<
	cg_annotate $$(ls -t cachegrind.out.* | head -n 1) > cachegrind-report.txt


##################################################################


test.x: test.o functions.o
	g++ $^ -o $@


test: test.x
	./$<


##################################################################


plot: sanitize  plots.gp
	gnuplot plots.gp

show: plot 
	evince Images/entropy.pdf Images/total_molecules.pdf Images/drop_size.pdf

##################################################################


erase: 
	rm -f a.out *.x  *.txt *~ *.png gmon.out cachegrind.out.*

clean:
	rm -f  *.o a.out *.x  *.txt *~ *.png gmon.out  cachegrind.out.*
