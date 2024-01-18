#!/bin/bash
for imageNumber in {001..300}
do
 ./main.c -0.6444473597635 -0.644447359761 -0.475127269499 -
0.475127269497 $imageNumber > "Images/Image_"$imageNumber".ppm"
done
convert -delay 10 Images/*.ppm Resultats/Mandelbrot1.gif
rm Images/*.ppm
