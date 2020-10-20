all: val.pdf


valores_propios.x: valores_propios.cpp
	g++ valores_propios.cpp -o valores_propios.x

valores_propios.txt: valores_propios.x runvalues.sh
	bash runvalues.sh

val.pdf: valores_propios.txt valores_propios.gp
	gnuplot valores_propios.gp


clean:
	rm a.out *~ *.x 
