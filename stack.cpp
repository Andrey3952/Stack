#include "stack.h"
#include <iostream>
#include <algorithm>

using namespace std;

Stack::Stack(int length)
    : m_length(0), m_maxLength(length), m_array(new int[length])
{
}

Stack::~Stack()
{
    delete[] m_array;
}

Stack::Stack(const Stack &other)
    : m_length(other.m_length), m_maxLength(other.m_maxLength),
      m_array(new int[other.m_maxLength])
{
    copy(other.m_array, other.m_array + m_length, m_array);
}

Stack &Stack::operator=(const Stack &other)
{
    if (this != &other)
    {
        delete[] m_array;

        m_length = other.m_length;
        m_maxLength = other.m_maxLength;
        m_array = new int[m_maxLength];
        copy(other.m_array, other.m_array + m_length, m_array);
    }
    return *this;
}

void Stack::push(int elem)
{
    if (m_length == m_maxLength)
    {
        int newSize = m_maxLength + 1;
        int *newArray = new int[newSize];

        for (int i = 0; i < m_length; ++i)
        {
            newArray[i] = m_array[i];
        }

        delete[] m_array;
        m_array = newArray;
        m_maxLength += 1;
    }
    m_array[m_length++] = elem;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return m_array[--m_length];
}

bool Stack::isEmpty() const
{
    return m_length == 0;
}

void Stack::multiPop(int N)
{
    if (N > m_length)
    {
        cout << "Not enough elements in the stack!" << endl;
        N = m_length;
    }
    for (int i = 0; i < N; ++i)
    {
        pop();
    }
}

void Stack::show() const
{
    for (int i = 0; i < m_length; ++i)
    {
        std::cout << m_array[i];
        if (i != m_length - 1)
            std::cout << " ";
    }
    cout << endl;
}
