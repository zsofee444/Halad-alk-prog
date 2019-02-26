#include <iostream>
#include <math.h>

//lineáris egyenlet megoldó:
void solvelin(double a, double b){
    if(a == 0.0){
        std::cout <<"There is no soulution. \n";
    }
    else{
        std::cout<< "the solution is:" << -b/a << "\n";
    }
}

// másodfokú megoldó:
void solve(double a, double b, double c){
    if(a == 0.0 ){
        solvelin(b, c);
    }
    else{
        if(b*b -4*a*c < 0.0){
            std::cout <<"There is no real solution. \n";
        }
        else if (b*b-4*a*c == 0.0 ){
            std::cout <<"There is one solution, which is:" << -b/(2*a)<< "\n";
        }
        else(b*b-4*a*c > 0.0); {
            std::cout << "There are two solutions, which are: \n"
            << -b+sqrt(b*b-4*a*c)/(2*a) << "\n"
            <<-b-sqrt(b*b-4*a*c)/(2*a) << "\n";
        }
    }
}

int main(){
    double a=1 ;
    double b=1 ;
    double c=1 ;

    solve( a,b,c);
}

 