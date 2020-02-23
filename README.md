# Monte-Carlo-Simulation-
Monte Carlo Simulation for Integral Estimation

Author          : Aslihan Celik
Created         : August 25, 2019
Last Modified   : August 30, 2019

Affiliation     : Georgia Institute of Technology


Description
-------------

This program is a  "Monte Carlo Simulation for Estimating the Value of an Integral", 
specifically for finding the estimation of the area under the function. Function f(x) 
is assumed to be bigger than and equal to zero. In order to implement the Monte Carlo 
simulation approach, function is bounded by a rectangle bound by the X axis, and the 
lines y=K, x=a and x=b. a and b values are user input. K value is determined to be 
greater than the maximum value of the function within the [a,b] interval. Code is 
designed to give an error if the function goes to infinity within the specified 
interval of [a,b] due to not being able to select a K value. To estimate the area 
by Monte Carlo simulation, N random points are selected within the rectangle bound. 
Program computes for seven different N values which gives an idea of the estimated 
value of the integral gets closer to the real value of the integral as N increases.


Installation
------------

To install, simply run

    gcc main.c -std=c99 -o monteCarlo

Execution
-----------

Run it using

    ./monteCarlo
