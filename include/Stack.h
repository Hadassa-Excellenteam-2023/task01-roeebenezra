#pragma once

#include <iostream>
#include <stdexcept>
#include "Vector.h"

class Stack {
public:
    // Constructor: creates a stack with the specified size and value for each element
    explicit Stack(size_t size = 0, int value = 0);

    // Copy constructor: creates a new stack that is a copy of another stack
    Stack(const Stack &other);

    // Move constructor
    Stack(Stack &&other) noexcept;

    // Destructor: deallocates memory used by the data array
    ~Stack() = default;

    // Copy assignment operator
    Stack &operator=(const Stack &other);

    // Move assignment operator
    Stack &operator=(Stack &&other) noexcept;

    // Returns true if the stack is empty (i.e., it contains no elements)
    [[nodiscard]] bool isEmpty() const;

    // Adds an element to the top of the stack
    void push(int value);

    // Removes the top element of the stack
    void pop();

    // Returns the number of elements in the stack
    [[nodiscard]] size_t size() const { return m_top; }

    // Returns the number of elements in the stack
    [[nodiscard]] size_t capacity() const { return m_data.capacity(); }

    // Returns a vector obj of the data
    Vector data() { return m_data; }

    // Returns a const vector obj of the data
    [[nodiscard]] Vector data() const { return m_data; }

    // Comparison operators
    bool operator==(const Stack &other) const;

    bool operator!=(const Stack &other) const;

    bool operator<(const Stack &other) const;

    bool operator>(const Stack &other) const;

    // Arithmetic operators
    Stack &operator+=(int value);

    Stack &operator-=(int value);

    Stack &operator*=(int value);

    Stack &operator/=(int value);

    Stack operator+(const Stack &other) const;

    Stack &operator+=(const Stack &other);

private:
    Vector m_data;        // A Vector to manage the data in the stack
    size_t m_top;       // The index of the top element in the stack
};
