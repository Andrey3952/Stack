#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    int m_length;
    int m_maxLength;
    int *m_array;

public:
    Stack(int length = 5);
    ~Stack();
    Stack(const Stack &other);
    Stack &operator=(const Stack &other);

    void push(int elem);
    int pop();
    bool isEmpty() const;

    void multiPop(int N);

    void show() const;

    void func(int *array, int len);
};
#endif
