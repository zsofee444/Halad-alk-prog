#include <iostream>
#include <math.h>

double sqrt_newton(double num, double x0){
    int n;
    int i = 0;
     do{
         i = x0-(x0*x0-num)/2*x0;
         i=x0;
         ++i;
    }
    while(i <= n);
return i;
}

int main(){
    double num=612;
    double x0=10;
    int n=10;
    sqrt_newton(num, x0);
}

