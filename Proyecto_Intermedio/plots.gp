set xlabel "t"
set ylabel "S"
set key right bottom
set terminal pdf
set output "entropy.pdf"
p 'entropy.txt' u 1:2 t "lattice = 50, Nmol = 400" w l lt 2
set ylabel "Drop Size"
f(x) = A*sqrt(x)
fit f(x) 'drop_size.txt' via A
A = 2.8;
set output "drop_size.pdf"
p 'drop_size.txt' u 1:2 t "lattice = 50, Nmol = 400" w p, f(x) t "fit" w l lw 2 lt 4
