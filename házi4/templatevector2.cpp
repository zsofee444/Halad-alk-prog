#include <iostream>
#include <cmath>

template<typename T>
struct vector2d
{
    T x,y;

    vector2d<T>& operator+=( vector2d <T> const& v )
    {
        x+= v.x; y+=v.y;
        return *this;
    }
};

template<typename T>
vector2d<T> operator+( vector2d<T> const& a, vector2d<T> const& b )
{
    return vector2d<T>{ a.x + b.x, a.y + b.y };
}
    
template<typename T>
vector2d<T> operator-( vector2d<T> const& a, vector2d<T> const& b )
{
    return vector2d<T>{ a.x - b.x, a.y - b.y };
}

template<typename T>
vector2d<T> mulright( vector2d<T> const& a, T const& b )
{
    return vector2d<T>{a.x *b, a.y*b};
}

template<typename T>
vector2d<T> mulleft (T const b,  vector2d<T> const& a)
{
    return vector2d<T>{ b*a.x , b*a.y};
}
    
template<typename T>
vector2d<T> operator/( vector2d<T> const& a, T  const& b )
{
    return vector2d<T>{ a.x / b, a.y / b };
}

template<typename T>
T dot(vector2d<T> const& a, vector2d<T> const& b)
{
    return a.x *b.x + a.y*b.y;
}

template<typename T>
T length(vector2d<T> const& a)
{
    return sqrt(a.x*a.x+a.y*a.y);
}

template<typename T>
T sqlength(vector2d<T> const& a)
{
    return a.x*a.x+a.y*a.y;
}

template<typename T>
vector2d<T> normalize(vector2d<T> const& a)
{
    double n=length(a);
    return {a.x/n , a.y/n};
}
    
template<typename T>
bool operator== (vector2d<T> const& a, vector2d<T> const& b)
{
    double e=1e-10;
    if(std::abs(a.x-b.x) <e && std::abs(a.y-b.y) <e)
    {
        return true;
    }
    return false;
}    

template<typename T>
std::istream& operator>> (std::istream& i, vector2d<T> & a)
{
    i>>a.x;
    i>>a.y;
    return i;
}

template<typename T>
std::ostream& operator<< (std::ostream& i, vector2d<T> const& a)
{
    i<<"(" << a.x << ";" << a.y << ")" << std::endl ;
    return i;
}

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
    std::cout << "The vector divided by 3 \n" << v1/3.0;
    std::cout << "The multiplication of a vector and a number: \n" << mulright(v1, 3.0);
    std::cout << "The multiplication of a a number and a vecttor \n" << mulleft(3.0, v1);
    
    if(mulright(v1,3.0) ==mulleft(3.0,v1))
    {
         std::cout << "The multiplication is kummutative, so it is good.\n";
    }
    else
    {
        std::cout << "The multiplication is not kommutative, so there is some problems..." ;
        std::cout << "The multiplication of a vector and a number: \n" << mulright(v1,3.0);
        std::cout << "The multiplication of a a number and a vector \n" << mulleft(3.0,v1);
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
