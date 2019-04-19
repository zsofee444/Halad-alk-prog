#include <iostream>
#include <string>
#include "matrix.h"
#include <array>
using namespace std;

int main(){
    cout.precision(7);
    matrix<double> const m1({30.2, 12.0, 61.4, 15.7, 81.6, 17.6, 63.5, 52.4, 77.3}, 3);
    matrix<double> const m2({16.3, 74.5, 36.1, 27.0, 99.1, 81.6, 38.7, 42.0, 11.35}, 3);
    double eps = 1e-10;

    //The checking values are from excel, and: http://www.bluebit.gr/matrix-calculator/matrix_multiplication.aspx 

    cout<<m1<<endl;

    if(!mat_eq(m1, m1, eps))
    {
        cout<<"There is a probléem, with the equality's def."<<endl;
    }    

    matrix<double> add1 = m1 + m2;
    matrix<double> add2 = m2 + m1;
    if(!mat_eq(add1, add2, eps))
    {
        cout<<"There is a problem with the addition's def, because it must be kommutative."<<endl;
        cout<<add1<<endl;
        cout<<add2<<endl;
    }
    
    matrix<double> const add_check({46.5, 86.5, 97.5, 42.7, 180.7, 99.2, 102.2, 94.4, 88.65}, 3);
    if(!mat_eq(add1, add_check, eps))
    {
        cout<<"The addition's def is wrong."<<endl;
        cout<<add1<<endl;
        cout<<add_check<<endl;
    }
    
    matrix<double> sub = m1 - m2;
    matrix<double> const sub_check({13.9, -62.5, 25.3, -11.3, -17.5, -64.0, 24.8, 10.4, 65.95}, 3);
    if(!mat_eq(sub, sub_check, eps))
    {
        cout<<"The substraction's def is wrong."<<endl;
        cout<<sub<<endl;
        cout<<sub_check<<endl;;        
   }

    matrix<double> mul1 = m1 * m2;
    matrix<double> const mul1_check({3192.44, 6017.9, 2766.31, 3140.23, 9995.41, 7425.09, 5441.36, 13170.19, 7445.545}, 3);
    if(!mat_eq(mul1, mul1_check, eps))
    {
        cout<<"The multiplication of two matrixes is wrong.";
        cout<<mul1<<endl;
        cout<<mul1_check<<endl;; 
    }

    matrix<double> mul2 = m2 * m1;
    matrix<double> const mul2_check({3954.26, 8166.44, 5102.55, 7552.87, 12686.4, 9709.64, 2548.865, 4486.34, 3992.735}, 3);
    if(!mat_eq(mul2, mul2_check, eps))
    {
        cout<<"The multiplication of two matrixes is wrong."<<endl;
        cout<<mul2<<endl;
        cout<<mul2_check<<endl;; 
    }

    matrix<double> constmul1 = m1 * 1.4;
    matrix<double> constmul2 = 1.4 * m1;
    if(!mat_eq(constmul1, constmul2, eps))
    {
        cout<<"Theres is a problem with the def of matrix multipling constant, because it must be kommutative."<<endl;
        cout<<constmul1<<endl;
        cout<<constmul2<<endl;
    }
    
    matrix<double> const constmul_check({42.28, 16.8, 85.96, 21.98, 114.24, 24.64, 88.9, 73.36, 108.22}, 3);
    if(!mat_eq(constmul1, constmul_check, eps))
    {
        cout<<"The multiplication of a matrix and a constant is wrong."<<endl;
        cout<<constmul1<<endl;
        cout<<constmul_check<<endl;; 
    }

    matrix<double> divi = m1/10;    
    matrix<double> divi_check({3.02, 1.2, 6.14, 1.57, 8.16, 1.76, 6.35, 5.24, 7.73}, 3);
    if(!mat_eq(divi, divi_check, eps))
    {
        cout<<"The division's def is wrong."<<endl;
        cout<<divi<<endl;
        cout<<divi_check<<endl;; 
    }

   return 0;

}
