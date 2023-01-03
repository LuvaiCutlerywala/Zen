#pragma once

#include <cstdint>
#include <vector>

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

        uint32_t getRows();
        uint32_t getColumns();
        uint64_t size();

    private:
        uint32_t m_rows;
        uint32_t m_columns;
        std::vector<T> m_container;
};

#endif