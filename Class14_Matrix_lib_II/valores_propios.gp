set log xy
f(x) = A*x**B
A=1.0e-5; B=3;
fit f(x) 'valores_propios.txt' via A, B
set xlabel 'N'
set ylabel 'CPU time (s)'
set term pdf 
set out "val.pdf"
plot 'valores_propios.txt' w lp lw 5 t 'escalamiento normal', f(x) lw 4 t 'fit', 'valores_propios.txt' w lp lw 5 t 'escalamiendo optimizado'
