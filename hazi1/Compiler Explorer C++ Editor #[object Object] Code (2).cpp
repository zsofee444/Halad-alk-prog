#include <iostream>
#include <math.h>

//trapéz szabályos közelítés lesz majd
double integrate(int n, double x0, double x1){
    double x=x0;
    void fun(double x);{
        return sin(x);
    }
    int i=1;
    double sum=0.0;
    while (i<=n) {
        double d;
        d=(x1-x0)/n;
        x+=x+d;
        sum += d*(fun(x(i-1))+fun(x(i)));
    }
    return 1/2*sum;
}

int main(){
    double x0=0;
    double x1=1;
    int n=10;
    integrate(n, x0, x1);
}

