set term png size 1280,720
set out "plot.png"

set title "Monopoly results"

set style data histograms
 
set autoscale ymax
set xlabel "Playertype"
set ylabel "Money amount"
set style fill solid
set offset graph 0.1, 0.1

plot "data.dat" using 2:xtic(3) linecolor 'blue' title 'Amount of Money'
