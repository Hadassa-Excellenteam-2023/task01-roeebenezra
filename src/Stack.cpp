#pragma once

#include "Stack.h"
#include <stdexcept>

// Constructor: creates a stack with the specified size and value for each element
Stack::Stack(size_t size, int value) : m_top(value ? size : 0), m_data(size, value) {}


// Copy constructor: creates a new stack that is a copy of another stack
Stack::Stack(const Stack &other)
        : m_top(other.m_top), m_data(other.m_data) {}


// Copy assignment operator: replaces the contents of this stack with a copy of another stack
Stack &Stack::operator=(const Stack &other) {
    if (this != &other) {
        m_top = other.m_top;
        m_data = other.m_data;
    }
    return *this;
}


// Move constructor
Stack::Stack(Stack &&other) noexcept
        : m_top(other.m_top), m_data(std::move(other.m_data)) {}

// Move assignment operator
Stack &Stack::operator=(Stack &&other) noexcept {
    if (this != &other) {
        m_top = other.m_top;
        m_data = std::move(other.m_data);
    }
    return *this;
}


// Returns true if the stack is empty (i.e., it contains no elements)
bool Stack::isEmpty() const {
    return m_top == 0;
}


// Adds an element to the top of the stack
void Stack::push(int value) {
    if (m_top == m_data.capacity()) {
        m_data.resize(m_data.capacity() * (m_data.capacity() <= 128 ? 2 : 1.5));
    }
    m_data.insert(0, value);
    ++m_top;
}


// Removes the top element of the stack
void Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    --m_top;
}


// Comparison operators
bool Stack::operator==(const Stack &other) const {
    return m_data.capacity() == other.data().capacity() && m_data == other.m_data;
}


bool Stack::operator!=(const Stack &other) const {
    return !(*this == other);
}


bool Stack::operator<(const Stack &other) const {
    return this->capacity() < other.capacity();
}


bool Stack::operator>(const Stack &other) const {
    return this->capacity() > other.capacity();
}


// Arithmetic operators
Stack Stack::operator+(const Stack &other) const {
    Stack result(*this);
    result += other;
    return result;
}


Stack &Stack::operator+=(const Stack &other) {
    if (m_data.size() < m_top + other.m_top) {
        m_data.resize(m_top + other.m_top);
    }
    for (size_t i = 0; i < other.m_top; ++i) {
        m_data[m_top++] = other.m_data[i];
    }
    return *this;
}


Stack &Stack::operator+=(int value) {
    for (int i = 0; i < this->size(); ++i)
        this->m_data.data()[i] += value;

    return *this;
}


Stack &Stack::operator-=(int value) {
    for (int i = 0; i < this->size(); ++i)
        this->m_data.data()[i] -= value;

    return *this;
}


Stack &Stack::operator*=(int value) {
    for (int i = 0; i < this->size(); ++i)
        this->m_data.data()[i] *= value;

    return *this;
}


Stack &Stack::operator/=(int value) {
    for (int i = 0; i < this->size(); ++i)
        this->m_data.data()[i] /= value;

    return *this;
}
