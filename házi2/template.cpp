#include <iostream>
#include <cmath>

 template<typename F, typename E, typename T>
T newton(F f1, E f2, T x0){
    int n=10.0;
    int i = 0.0;
    double s;
    do{
         s = x0-f1(x0)/(f2(x0));
         ++i;
         x0=s;
    }
    while(i <= n);
    return s;
}

  int main(){
    std::cout.precision(7);
    std::cout << "A Wikipedian lévő érték: 24.7386338, míg a beépített gyök függvény értéke:" << sqrt(612.0);
    std::cout << "A megírt Newton gyökkereső által adott érték pedig:" << newton([](double x){ return x*x-612.0;},[](double x){return 2.0*x; }, 10.0);
}