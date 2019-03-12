#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <numeric>
#include <cmath>

double linill(std::vector<double> const& A, std::vector<double> const& B)
{   
    int n= static_cast <int>(A.size());
    int l= static_cast <int>(B.size());
    double Aátl= std::accumulate(A.begin(), A.end(), 0)/n;
    double Bátl= std::accumulate(B.begin(), B.end(), 0)/l;
    auto f=[Aátl, Bátl](int x, double a, double b){ return x+(a-Aátl)*(b-Bátl);};
    double sqsum= std::accumulate(A.begin(), A.end(), B.begin(), B.end(), 0,f); //itt van a baj, mert két vektor elejét-végét adtam meg
    auto g=[Aátl](int y, double a){return y+(a-Aátl);};
    double r=std::accumulate(A.begin(), A.end(), 0, g);
    double b=sqsum/r;
    double m=Bátl-b*Aátl;
    std::array<double, 2> M={1,2};
    M[0]=m;
    M[1]=b;
    std::cout << M[0] << ", " << M[1] << "\n";
}
    
int main()
{
    std::vector<double> A={1,2,3};
    std::vector<double> B={4,5,6};
    linill( A, B);
}
