#pragma once

#include <initializer_list>

namespace darek {

class vector
{
    int size;
    double* elements;
public:
    vector(int size)
        :size(size), elements{ new double[size] }
    {
        for (int counter = 0; counter < size ; ++counter) elements[counter] = 0.0;
    }

    vector(initializer_list<double> list)
        :size{ list.size() }, elements{ new double[size] }
    {
        
    }
};

}
