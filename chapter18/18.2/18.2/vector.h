#pragma once

#include <initializer_list>
#include <algorithm>

namespace darek {


class vector
{
    int size;
    double* elements;
public:
    explicit vector(int size)
        :size(size), elements{ new double[size] }
    {
        for (int counter = 0; counter < size ; ++counter) elements[counter] = 0.0;
    }

    vector(std::initializer_list<double> list)
        :size{ static_cast<int>(list.size()) }, elements{ new double[size] }
    {
        std::copy(list.begin(), list.end(), elements);
    }

    ~vector() { delete[] elements; }

    int get_size()
    {
        return size;
    }

    vector(const vector&);
    vector& operator=(const vector&);

    vector(vector&&);
    vector& operator=(vector&&);


    double get(int element_no);
};



}//namespace darek
