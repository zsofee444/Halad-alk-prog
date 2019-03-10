#include <iostream>
#include <cmath>

double sqrt_newton(double num, double x0){
    int n=5;
    int i = 0;
    double s;
    do{
         s = x0-(x0*x0-num)/(2.0*x0);
         ++i;
         x0=s;
    }
    while(i <= n);
    return s;
}

int main(){
    double num=612;
    double x0=10;
    std::cout.precision(7);
    std::cout << "A Wikipedian lévő érték: 24.7386338, míg a beépített gyök függvény értéke:" << sqrt(num);
    std::cout << "A megírt Newton gyökkereső által adott érték pedig:" << sqrt_newton(num, x0);
}