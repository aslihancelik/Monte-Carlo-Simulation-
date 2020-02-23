//
//  main.c
//
//  Created by Aslihan Celik on 8/25/19.
//  Copyright © 2019 Aslihan Celik. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

double f(double x)
{
    double func=x*x ;
    return func;
}

int main( ) {
    double a=0;
    double b=0;
    printf("Enter a value for a:");
    scanf( "%lf",&a);
    printf("Enter a value for b:");
    scanf("%lf" ,&b);
    if (a<b){
        printf("The value you entered for a is: %lf \n", a);
        printf("The value you entered for b is: %lf \n", b);}
    else if(a>b){
        printf("Input Error: Value of a is supposed to be smaller than value of b. Try again.\n ");
        return 0;
        }
    else{
        printf("The estimated area under the function f(x) by Monte Carlo simulation is zero when a=b. \n");
        return 0;
        }
        
    //Checking if the function is going to infinity within the [a,b] interval as well as checking if we can determine K value.
    
    double g=a;
    int N=10000000;
    double increment=(b-a)/N;

    for(int i=0;i<=N;i++){
        double e=g+increment;
        double slope=((f(e)-f(g))/(e-g));
        
        //Checking if slope is a very large number to understand if the function goes to infinity. If function goes to infinity within the specified interval of [a,b] we can not determine a K value. Therefore, program gives and error in such case.
        
        if(f(g)>=0 && f(e)>=0 && (fabs(slope)>=10000000)){ /*First two conditions are to see if it satisfies f(x)>=0 at this x                                                  values.*/
           printf("Error: Approximately at point x=(%lf) slope is undefined.K can't be determined because the function goes to infinity within the interval.Try another function. \n", e);
           return 0;
           }
        g=e;
       }
    
    N=10;
    
    for (int w=1;w<=7;w++){              //This is the for loop for trying different N values for the area estimation.
            N=N*10;
            printf("Calculating For N=%d \n",N);
        
            //Finding K
            double inc=((b-a)/N);       //This is for incrementing the interval inputs each time.
        
            /*In order to find K we first need to find the maximum value of the function within the specified interval. Starting by inputting a to the f(x) function,we input incremented c values to the function in order to find the maximum value. */
        
           double K=f(a);
           double c=a;
        
            for(int i=0; i<N; i++){
                c=c+inc;          //incremented c values
                if (f(c)>K){     /*Each time the for loop runs, if the current value of the function is bigger than the current               value of K, program updates K by assigning the current function value to the K value.*/
                      K=f(c);    /*To assign the maximum value of the function within the interval to the K aa a result of the          for loop.*/
                        }
                    }
        
            double max=K+(0.001); /*In order to pick a K that is bigger than the maximum value of the function within the given                    interval, I assumed K to be larger than the maximum value of the function by a small number                      0.001)*/
            if(K>0){            /*f(x) should be greater and equal to zero and K should be greater than f(x).Therefore, we can                   only select a positive K value.*/
                
                printf("K value is: %lf \n",max);}
            else{
                printf("Error:K value is supposed to be positive.Function f(x) is smaller than zero within this interval. Try a different function or a different interval. \n");
                return 0;}
    
            //Randomly generating (x_,y_) points within the rectangle bounded by X axis and lines y=K, x=a and x=b
            int ncount=0;
            srand((double)time(NULL));
        
            //For Calculating n
            for(int numAmount=1; numAmount<=N ; numAmount++) {
        
                 double x_ = ((double)rand()/(double)(RAND_MAX))*(b-a)+a;
                 double y_ = ((double)rand()/(double)(RAND_MAX))*K;
        
                 if( f(x_)>=0 && y_<=f(x_)){
                    ncount=ncount+1;
                     }
                }
           int n =ncount;
           printf ("n value is: %d \n",n);
           double Z=n*K*(b-a)/N;
           printf("For N= %d The estimated area under the function f(x) by Monte Carlo simulation is %lf \n",N,Z);
        
    }


return 0;
    
}
    

