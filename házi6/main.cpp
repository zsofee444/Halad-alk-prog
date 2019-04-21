#include "matrix.h"
#include <random>
#include <chrono>
#include <fstream>

int main(int,char**)
{

    //random number generation
    std::random_device rd{};
    std::mt19937 gen(rd());
    std::normal_distribution<double> distr(0.,10.);
    
    for( int n; n<100; n=n+1 )
    {
        
        matrix<double> data(1500);
        matrix<double> mat_ran1 (generate(data.begin(),data.end(), [&]{ return distr(gen); }, n));
        matrix<double> mat_ran2 (generate(data.begin(),data.end(), [&]{ return distr(gen); }, n));
    
        auto t1=std::chrono::high_resolution_clock::now();
    
        mat_ran1 * mat_ran2;
   
        auto t2=std::chrono::high_resolution_clock::now();

        double t=(static_cast<std::chrono::duration<double,std::milli>>(t2-t1)).count();

        std::ofstream myfile;
        myfile.open("time.txt",std::fstream::app);
        myfile<<n<<"  "<<t<< "\n";
        myfile.close();
    }
    return 0;
}
