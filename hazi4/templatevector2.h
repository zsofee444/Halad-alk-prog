#include <iostream>
#include <string>
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
