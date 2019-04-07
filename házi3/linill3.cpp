#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <numeric>
#include <cmath>


double linill(std::vector<double> const& A, std::vector<double> const& B)
{   
    double n=A.size();
    double l=B.size();
    double Aatl= std::accumulate(A.begin(), A.end(), 0)/n;
    double Batl= std::accumulate(B.begin(), B.end(), 0)/l;
    double sqsum=std::inner_product(A.begin(), A.end(), B.begin(),0.0, std::plus<>(), std::equal_to<>());
    auto g=[Aatl](int y, double a){return y+(a-Aatl);};
    double r=std::accumulate(A.begin(), A.end(), 0, g);
    double b=sqsum/r;
    double m=Batl-b*Aatl;
    std::array<double,2> M={1,2};
    M[0]=m;
    M[1]=b;
    std::cout << M[0] << ", " << M[1] << "\n";
    return M;
}
    
int main()
{
    std::vector<double> A={1.0,2.0,3.0};
    std::vector<double> B={4.0,5.0,6.0};
