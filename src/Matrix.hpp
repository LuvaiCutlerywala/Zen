#pragma once

#include <cstdint>
#include <array>

#ifndef MATRIX_H
#define MATRIX_H

template <class T, int rows, int columns>
class MATRIX
{

    public:
    MATRIX();
    ~MATRIX();

    T get(uint32_t row, uint32_t column);
    void set(T element, uint32_t row, uint32_t column);

    private:
    std::array<std::array<T, rows>, columns> m_matrix;

};

#endif