#include <iostream>
#include <math.h>

double sqrt_newton(double num, double x0){
    int n=10;
    int i = 0;
     do{
         x= x0-(x0*x0-num)/2*x0;
         ++i;
    }
    while(i <= n);
return x;
}

int main(){
    double num=612;
    double x0=10;
    sqrt_newton(num, x0);
}

