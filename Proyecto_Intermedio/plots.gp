set xlabel "t"
set ylabel "Total Molecules"
set terminal pdf
set output "Images/total_molecules.pdf"
p 'total_molecules.txt' u 1:2 t "lattice = 50, Nmol in= 400, hole=10" w lp lt 6
set ylabel "S"
set key right bottom
set output "Images/entropy.pdf"
p 'entropy.txt' u 1:2 t "lattice = 50, Nmol = 400" w l lt 2
set ylabel "Drop Size"
f(x) = A*sqrt(x)
fit f(x) 'drop_size.txt' via A
A = 2.8;
set output "Images/drop_size.pdf"
p 'drop_size.txt' u 1:2 t "lattice = 50 pt 5, Nmol = 400" w p, f(x) t "fit" w l lw 2 lt 4
