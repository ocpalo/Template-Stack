//
// Created by berkeyvx on 1.05.2021.
//

#include <exception>
#include <iostream>
#include <cstddef>

#ifndef STACK_STACK_H
#define STACK_STACK_H

template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    Stack& operator=(const Stack& other ); // TODO:: not implemented yet
    Stack& operator=(Stack&& other) noexcept; // TODO:: not implemented yet

    // element access
    const T& top() const;
    T& top();

    // capacity
    T size() const { return m_index + 1; }
    bool empty() const { return m_index == -1; }

    // modifiers
    void push(const T& value);
    void push(T&& value);
    void pop();
    void swap(Stack& other) noexcept; // TODO:: not implemented yet

    // debug :)
    void print();

private:
    void expand();
    void shrink();
    T *m_pData;
    std::size_t m_size {4}; // DEFAULT SIZE
    long long m_index {-1};
};


template<typename T>
Stack<T>::Stack()
{
    m_pData = new T[m_size];
}


template<typename T>
Stack<T>::~Stack()
{
    delete[] m_pData;
    m_pData = nullptr; // do i need this?
}


template<typename T>
Stack<T> &Stack<T>::operator=(const Stack &other)
{
    if(this == &other)
        return *this;

    return *this;
}


template<typename T>
Stack<T> &Stack<T>::operator=(Stack &&other) noexcept
{
    return *this;
}


template<typename T>
const T& Stack<T>::top() const
{
    if(m_index == -1)
        throw std::out_of_range("No data in Stack");
    return m_pData[m_index];
}


template<typename T>
T& Stack<T>::top()
{
    if(m_index == -1)
        throw std::out_of_range("No data in Stack");
    return m_pData[m_index];
}


template<typename T>
void Stack<T>::push(const T& value)
{
    if(m_index == m_size - 1)
        this->expand();
    m_pData[++m_index] = value;
}


template<typename T>
void Stack<T>::push(T &&value)
{
    if(m_index == m_size - 1)
        this->expand();
    m_pData[++m_index] = std::move(value);
}


template<typename T>
void Stack<T>::pop()
{
    if(m_size > 4 && m_index < m_size/4)
        shrink();

    if (m_index == -1)
    {
        throw std::out_of_range("No data in Stack");
    }

    m_pData[m_index--];
}


template<typename T>
void Stack<T>::swap(Stack &other) noexcept
{

}


template<typename T>
void Stack<T>::expand()
{
    m_size = m_size * 2;
    T *pTempData = new T[m_size];
    for (std::size_t i = 0; i <= m_index; ++i)
    {
        pTempData[i] = m_pData[i];
    }

    delete m_pData;
    m_pData = pTempData;
}


template<typename T>
void Stack<T>::shrink()
{
    m_size = m_size / 2;
    T* pTempData = new T[m_size];
    for(std::size_t i = 0; i <= m_index; ++i)
    {
        pTempData[i] = m_pData[i];
    }

    delete m_pData;
    m_pData = pTempData;
}





template<typename T>
void Stack<T>::print()
{
    std::cout << "Capacity: " << m_size << " Data: ";
    for (int i = 0; i <= m_index; ++i)
    {
        std::cout << m_pData[i] << " ";
    }
    std::cout << "\n";
}



#endif //STACK_STACK_H
