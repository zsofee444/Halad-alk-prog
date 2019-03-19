#include <iostream>
#include <cmath>

template<typename T>
struct vector2d
{
    T x,y;

    vector2d<T>& operator+c( vector2d <T> const& v )
    {
        x+= v.x; y+=v.y;
        return *this;
    }

    vector2d<T> operator+( vector2d<T> const& a, vector2d<T> const& b )
    {
    return Vector2<T>{ a.x + b.x, a.y + b.y };
    }
    
    vector2d<T> operator-( vector2d<T> const& a, vector2d<T> const& b )
    {
        return vector2d<T>{ a.x - b.x, a.y - b.y };
    }

    vector2d<T> operator*( vector2d<T> const& a, const& b )
    {
        return vector2d<T>{ a.x * b, a.y + b };
    }

    vector2d<T> operator/( vector2d<T> const& a,  const& b )
    {
        return vector2d<T>{ a.x / b, a.y / b };
    }

    double dot(vector2d<T> const&, vector2d<T> const&);
    {
        return {a.x *b.x + a.y*b.y};
    }

    double length(vector2d<T> const&);
    {
        return {sqrt{a.x**2+b.x**2}};
    }

    double sqlength(vector2d<T> const&);
    {
        return {a.x**2+b.x**2};
    }

    vector2d<T> normalize(vector2d<T> const&);
    {
        n=length(vector2d<T> const&);
        return {a.x/n , b.x/n
    }
}


int main()
{
    vector2d<T> v1{}, v2{};
    std::cout << "Enter vector 1:\n";
    std::cin >> v1;
    std::cout << "Enter vector 2:\n";
    std::cin >> v2;
    std::cout << "The sum of the two vectors is:\n" << v1+v2;
    std::cout << "The multiplication of the two vectors is: \n"<< v1*v2;
    std::cout << "The difference of the two vectors is: \n" << v1-v2;
    std::cout << "The  ratio of the two vectors is: \n" << v1/v2;
    return 0;
}