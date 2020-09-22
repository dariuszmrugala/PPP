#include "vector.h"
#include <iostream>

namespace darek {



vector::vector(const vector& copied_vector)
//allocate elements, then initialize them by copying
    :size{ copied_vector.size }, elements{ new double[copied_vector.size] }
{
    std::cout << "vector(const vector&)\n";
    std::copy(copied_vector.elements, copied_vector.elements + copied_vector.size, elements);
}

vector& vector::operator=(const vector& copied_vec)
{
    double* p = new double[copied_vec.size];
    std::copy(copied_vec.elements, copied_vec.elements + copied_vec.size, p);
    delete[] elements;
    elements = p;
    size = copied_vec.size;
    return *this;
}

vector::vector(vector&& moved_vector)
    :size{ moved_vector.size }, elements{ moved_vector.elements }
{
    moved_vector.size = 0;
    moved_vector.elements = nullptr;
}

vector& vector::operator=(vector&& moved_vector)
{
    delete[] elements;
    elements = moved_vector.elements;
    size = moved_vector.size;
    moved_vector.elements = nullptr;
    moved_vector.size = 0;
    return *this;
}

double vector::get(int element_no)
{
    return elements[element_no];
}

}//namespace darek