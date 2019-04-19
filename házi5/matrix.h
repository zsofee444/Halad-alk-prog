#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <initializer_list>
#include <cmath>
#include <ostream>
#include<sstream>

namespace detail
{
	template<typename M1, typename M2, typename F>
	void transform_matrix1(M1 const& m1, M2& m2, F f)
	{
		std::transform(m1.cbegin(), m1.cend(), m2.begin(), f);
	}

	template<typename M1, typename M2, typename M3, typename F>
	void transform_matrix2(M1 const& m1, M2 const& m2, M3 & m3, F f)
	{
		std::transform(m1.cbegin(), m1.cend(), m2.cbegin(), m3.begin(), f);
	}
}

auto add = [](auto const& x, auto const& y){ return x + y; };
auto sub = [](auto const& x, auto const& y){ return x - y; };

template<typename T>
std::vector<T> mat_mul(std::vector<T> const& m1, std::vector<T> const& m2)
{
    int const size = static_cast<int>(m1.size());
    int n = static_cast<int>(std::sqrt(size));
    T sum = 0;
    std::vector<T> temp(size);
    if(size != static_cast<int>(m2.size()) || n * n != size)
    {
        std::cout<<"Matrices cannot be multiplied."<<std::endl;
        return temp;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum = 0;
            for(int k = 0; k < n; k++)
            {
                sum += (m1[i * n + k]) * (m2[k * n + j ]);
            }
        temp[n*i+j] = sum;
        }
    }
    return temp;
}

template<typename T>
class matrix
{
    int dim;
    std::vector<T> data;
    
    public:
    
    matrix(): dim{1}, data{{0.0}}{};
    matrix(int i): dim{i}, data(i*i,0){};
    matrix(int i, std::vector<T> const& v):dim(i) 
    {
        if(dim * dim == static_cast<int>(v.size()))
        {
            data = v;
        }
        else
        {
            std::cout<<"Initialization error!"<<std::endl;
            exit(-1);
        }
    };

    matrix<T>(matrix<T> const& cpy): dim{cpy.dim}, data{cpy.data}
    {
        if( dim != cpy.dim)
        {
            std::cout<<"Dimension is wrong."<<std::endl;
            exit(-1);
        }
    }

    matrix(matrix&&) = default;
    matrix<T>& operator=(matrix&&) = default;
    T & operator()(int i, int j){return data[dim * i + j];}
    T const& operator()(int i, int j) const {return data[ dim * i + j];}
    T & operator[](int i){return data[i];}
    T const& operator[](int i) const {return data[i];}
    matrix(std::initializer_list<T> const& list, int dimension)
    {
        if(dimension*dimension != static_cast<int>(list.size()))
        {
            std::cout<<"It is not a square matrix."<<std::endl;
            exit(-1);
        }
        dim = dimension;
        data = list;
    };

    matrix( int dimension, std::initializer_list<T> const& list)
    {
        if(dimension*dimension != static_cast<int>(list.size()))
        {
            std::cout<<"It is not a square matrix."<<std::endl;
            exit(-1);
        }
        dim = dimension;
        data = list;
    };

    matrix<T>& operator-=(matrix<T> const& m)
    {
        detail::transform_matrix2((*this).data, m.data, (*this).data, sub);
        return *this;
    }

    matrix<T>& operator*=(T const& c)
    {
        detail::transform_matrix1((*this).data, (*this).data, [=](T const& x){return x * c;});
        return *this;
    }
    
    matrix<T>& operator/=(T const& c)
    {
        detail::transform_matrix1((*this).data, (*this).data, [=](T const& x){return x / c;});
        return *this;
    }

    int dimension() const
    {
		return dim;
	}

    int size() const
    {
		return dim*dim;
	}
    std::vector<T> read_data() const&
    {
		return data;
	}

	auto begin()
	{
		return data.begin();
	}

	auto cbegin() const
	{
		return data.cbegin();
	}

	auto end()
	{
		return data.end();
	}

	auto cend() const
	{
		return data.cend();
    }
};

template<typename T>
int mat_prod(matrix<T> & m1, matrix<T> & m2, int lab)
{
    int n = m1.dimension();
    std::vector<T> temp(n);  
    if(lab == 1)
    {
        for(int i = 0; i <  n; i++)
        {
            std::fill(temp.begin(), temp.end(), 0);
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    temp[j] += m1(i, k) * m2(k, j);
                    if(j == n - 1)
                    {
                        m1(i, k) = temp[k];
                    }
                }
            }
        }
        return 0;
    }
    else if(lab == 2)
    {
        for(int i = 0; i <  n; i++)
        {
            std::fill(temp.begin(), temp.end(), 0);
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    temp[j] += m1(j, k) * m2(k, i);
                    if(j == n - 1)
                    {
                        m2(k, i) = temp[k];
                    }
                }
            }
        }
        return 0;
    }
    return -1;
}

template<typename T>
bool  mat_eq (matrix<T> const& m1, matrix<T> const& m2, T eps)
{
    int n = m1.dimension();
    if(n != m2.dimension() || m1.size() != n*n || m2.size() != n*n)
    {
        return false;
    }
    for(int i = 0; i < n * n; i++)
    {
        if(std::abs(m1[i] - m2[i]) > eps)
        {
            return false;
        }
    }
    return true; 
}

template<typename T>
matrix<T> operator+(matrix<T> const& m1, matrix<T> const& m2)
{
    matrix<T> result(m1.dimension());
    detail::transform_matrix2(m1, m2, result, add);
    return result;
}

template<typename T>
matrix<T>&& operator+(matrix<T>&& m1, matrix<T> const& m2)
{
    detail::transform_matrix2(m1, m2, m1, add);
    return std::move(m1);
}

template<typename T>
matrix<T>&& operator+(matrix<T> const& m1, matrix<T>&& m2)
{
    detail::transform_matrix2(m1, m2, m2, add);
    return std::move(m2);
}

template<typename T>
matrix<T>&& operator+(matrix<T>&& m1, matrix<T>&& m2)
{
    detail::transform_matrix2(m1, m2, m1, add);
    return std::move(m1);
}

template<typename T>
matrix<T> operator-(matrix<T> const& m1, matrix<T> const& m2)
{
    matrix<T> result(m1.dimension());
    detail::transform_matrix2(m1, m2, result, sub);
    return result;
}

template<typename T>
matrix<T>&& operator-(matrix<T>&& m1, matrix<T> const& m2)
{
    detail::transform_matrix2(m1, m2, m1, sub);
    return std::move(m1);
}

template<typename T>
matrix<T>&& operator-(matrix<T> const& m1, matrix<T>&& m2)
{
    detail::transform_matrix2(m1, m2, m2, sub);
    return std::move(m2);
}

template<typename T>
matrix<T>&& operator-(matrix<T>&& m1, matrix<T>&& m2)
{
    detail::transform_matrix2(m1, m2, m1, sub);
    return std::move(m1);
}

template<typename T>
matrix<T> operator*(matrix<T> const& m, T const& c)
{
    matrix<T> result(m.dimension());
    detail::transform_matrix1(m, result, [c](T const& x){return x * c;});
    return result;
}

template<typename T>
matrix<T>&& operator*(matrix<T>&& m, T const& c)
{
    detail::transform_matrix1(m, m, [c](T const& x){return x * c;});
    return std::move(m);
}

template<typename T>
matrix<T> operator*(T const& c, matrix<T> const& m)
{
    matrix<T> result(m.dimension());
    detail::transform_matrix1(m, result, [c](T const& x){return x * c;});
    return result;
}

template<typename T>
matrix<T>&& operator*(T const& c, matrix<T>&& m)
{
    detail::transform_matrix1(m, m, [c](T const& x){return x * c;});
    return std::move(m);
}

template<typename T1, typename T2>
matrix<T1> operator/(matrix<T1> const& m, T2 const& c)
{
    matrix<T1> result(m.dimension());
    detail::transform_matrix1(m, result, [c](T1 const& x){return x / c;});
    return result;
}

template<typename T1, typename T2>
matrix<T1>&& operator/(matrix<T1>&& m, T2 const& c)
{
    detail::transform_matrix1(m.data, m.data, [c](T1 const& x){return x / c;});
    return std::move(m);
}

template<typename T>
matrix<T> operator*(matrix<T> const& m1, matrix<T> const& m2)
{
    std::vector<T> v(m1.size());
    v = mat_mul(m1.read_data(), m2.read_data());
    matrix<T> temp(m1.dimension(), v);
    return temp;
}

template<typename T>
matrix<T>&& operator*(matrix<T> && m1, matrix<T> & m2)
{
    if(mat_prod(m1, m2, 1) != 0){
        std::cout<<"Matrix multiplication is not good."<<std::endl;
    }
    return std::move(m1);
}

template<typename T>
matrix<T>&& operator*(matrix<T> & m1, matrix<T>&& m2)
{
    if(mat_prod(m1, m2, 2) != 0){
        std::cout<<"Matrix multiplication is not good."<<std::endl;
    }
    return std::move(m2);
}

template<typename T>
matrix<T>&& operator*(matrix<T> && m1, matrix<T>&& m2)
{ 
    if(mat_prod(m1, m2, 1) != 0)
    {
        std::cout<<"Matrix multiplication is not good."<<std::endl;
    }
    return std::move(m1);
}

template<typename T>
std::ostream& operator<<(std::ostream& o, matrix<T> const& m)
{
	int n = {m.dimension()};
		for(int i = 0; i < n; i++)
		{
            o<<" ";
            for(int j = 0 ; j < n; j++)
            {
                o<<m(i,j)<<" ";
            }
            o<<"\n";
		}
	return o;
}
