#include <iostream>
#include <cmath>

//trapéz szabályos közelítés lesz majd
double fun(double x){
        return sin(x);
}

double integrate(int n, double x0, double x1){
    double x=x0;
    int i=1;
    double sum=0.0;
    double d=(x1-x0)/n;
    if (n==0){
        std::cout << "We can't divide with zero, so we stop the program.";
        return 0;
    }
    
    else {
        if(x1<x0){
            if (n<0){
                std::cout << "n means the numbers of the steps, so it must be a positive integer." ;
                n=-n;
            }
            std::cout << "x0 is the smaller limit of the integrate, so it must be smaller than x1, so swap the two limits.";
            std::swap(x0,x1);
        }
        while (i<=n) {
            sum += d*(fun(x)+fun(x+d));
            x+=d;
            i++;
        }
    return sum/2.0;
    }
}
        

int main(){
    double x0=0;
    double x1=1;
    int n=10;
    std::cout.precision(16);
    std::cout <<  "integrate függvény által számolt érték: \n " << integrate(n, x0, x1);
    std::cout <<  "\n A Wolframalpha által számolt értéke a sin(x) 0 és 1 között: \n 0.45970";
}
