#include <iostream>
#include <string>
#include "templatevector2.h"
#include <vector>
using namespace std;

int main()
{
    vector2d<double> v1{}, v2{};
    std::cout << "Enter vector 1:\n";
    std::cin >> v1;
    std::cout << "Enter vector 2:\n";
    std::cin >> v2;
    std::cout<<v1 << '\n' << v2 << std::endl;
    std::cout << "The sum of the two vectors is:\n" << v1+v2;
    std::cout << "The multiplication of the two vectors is: \n"<< dot(v1, v2);
    std::cout << "The difference of the two vectors is: \n" << v1-v2;
    std::cout << "The  ratio of the two vectors is: \n" << v1/3.0;
    std::cout << "The multiplication of a vector and a number: \n" << v1*3.0;
    std::cout << "The multiplication of a a number and a vecttor \n" << 3.0*v1;
    
    if(v1*3.0 == 3.0*v1)
    {
         std::cout << "The multiplication is kummutative, so it is good.";
    }
    else
    {
        std::cout << "The multiplication is not kommutative, so there is some problem..." ;
        std::cout << "The multiplication of a vector and a number: \n" << v1*3.0;
        std::cout << "The multiplication of a a number and a vector \n" << 3.0*v1;
    }
    
    if(mulright(v1,1/3.0) == v1/3.0)
    {
         std::cout << "The multiplication's inverse is the division. \n";
    }
    else
    {
        std::cout << "There is some problems..." ;
        std::cout << "The multiplication of a vector and a number: \n" << mulright(v1,1/3.0);
        std::cout << "The vector divided by 3 \n" << v1/3.0;
    }
    
    return 0;
}
