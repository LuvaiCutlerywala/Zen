#include "Matrix.hpp"
#include <algorithm>

template <typename T>
MATRIX<T>::MATRIX(uint32_t rows, uint32_t columns)
    : m_rows(rows), m_columns(columns)
{
    this->m_container = new std::vector<T>(rows * columns);
}

template <typename T>
MATRIX<T>::~MATRIX()
{
    delete this->m_container;
}

template <typename T>
T MATRIX<T>::get(uint32_t row, uint32_t column)
{
    return this->m_container.at((row * column) - 1);
}

template <typename T>
void MATRIX<T>::setElement(T element, uint32_t row, uint32_t column)
{
    this->m_container.insert((row * column) - 1, element);
}

template <typename T>
void MATRIX<T>::setMatrix(std::vector<T> container)
{
    std::copy(container.begin(), container.end(), std::back_inserter(this->m_container));
}

template <typename T>
uint32_t MATRIX<T>::getRows()
{
    return this->m_rows;
}

template <typename T>
uint32_t MATRIX<T>::getColumns()
{
    return this->m_columns;
}

template <typename T>
uint64_t MATRIX<T>::size()
{
    return this->m_container.size();
}