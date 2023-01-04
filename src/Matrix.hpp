#pragma once

#include <cstdint>
#include <vector>
#include <algorithm>

#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class MATRIX
{
    public:
        MATRIX(uint32_t rows, uint32_t columns);
        ~MATRIX();

        T get(uint32_t row, uint32_t column);
        void setElement(T element, uint32_t row, uint32_t column);
        void setMatrix(std::vector<T> elements);

        uint32_t rows();
        uint32_t columns();
        uint64_t size();

    private:
        uint32_t m_rows;
        uint32_t m_columns;
        std::vector<T> m_container;
        
};

template <typename T>
MATRIX<T>::MATRIX(uint32_t rows, uint32_t columns)
    : m_rows(rows), m_columns(columns)
{
    this->m_container = std::vector<T>(rows * columns);
}

template <typename T>
MATRIX<T>::~MATRIX()
{}

template <typename T>
T MATRIX<T>::get(uint32_t row, uint32_t column)
{
    row--;
    int i = (row * this->m_columns) + column;
    return this->m_container.at(i - 1);
}

template <typename T>
void MATRIX<T>::setElement(T element, uint32_t row, uint32_t column)
{
    row--;
    int i = (row * this->m_columns) + column;
    this->m_container.at(i - 1) = element;
}

template <typename T>
void MATRIX<T>::setMatrix(std::vector<T> container)
{
    if(container.size() > this->m_container.size()) throw std::length_error("Vector is larger than matrix size.");
    for(int i = 0; i < this->m_container.size(); ++i)
    {
        this->m_container.at(i) = container.at(i);
    }
}

template <typename T>
uint32_t MATRIX<T>::rows()
{
    return this->m_rows;
}

template <typename T>
uint32_t MATRIX<T>::columns()
{
    return this->m_columns;
}

template <typename T>
uint64_t MATRIX<T>::size()
{
    return this->m_container.size();
}

#endif