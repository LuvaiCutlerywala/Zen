#include "Matrix.hpp"

template <class T, int rows, int columns>
MATRIX<T, rows, columns>::MATRIX()
{
    this->m_matrix = new std::array<std::array<T, rows>, columns>();
}

template <class T, int rows, int columns>
MATRIX<T, rows, columns>::~MATRIX()
{
    delete this->m_matrix;    
}

template <class T, int rows, int columns>
T MATRIX<T, rows, columns>::get(uint32_t row, uint32_t column)
{
    return this->m_matrix[column][row];
}

template <class T, int rows, int columns>
void MATRIX<T, rows, columns>::set(T element, uint32_t row, uint32_t column)
{
    this->m_matrix[column][row] = element;
}