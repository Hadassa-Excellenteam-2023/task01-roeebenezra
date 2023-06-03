#include "Vector.h"


// Constructor: creates a vector with the specified size and value for each element
Vector::Vector(size_t size, int value) : m_size(size)
// Always allocate at least one element, even if the requested size is zero
        , m_capacity(size ? size : 1)
{
    // Allocate memory for the data array
    m_data = new int[m_capacity];
    // Initialize each element with the specified value
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = value;
    }
}

// Copy constructor: creates a new vector that is a copy of another vector
Vector::Vector(const Vector& other)
        : m_size(other.m_size), m_capacity(other.m_capacity)
{
    // Allocate memory for the data array
    m_data = new int[m_capacity];
    // Copy the elements from the other vector
    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}


// Move constructor: creates a new vector that takes ownership of another vector's resources
Vector::Vector(Vector&& other) noexcept
: m_size(other.m_size), m_capacity(other.m_capacity), m_data(other.m_data)
{
// Reset the source vector to a valid state
other.m_size = 0;
other.m_capacity = 0;
other.m_data = nullptr;
}


Vector& Vector::operator=(const Vector& other)
{
    if (this != &other) {
        // Create a temporary vector that is a copy of the other vector
        Vector temp(other);
        // Swap the contents of this vector and the temporary vector
        swap(temp);
    }
    return *this;
}


void Vector::swap(Vector& other)
{
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_data, other.m_data);
}


void Vector::push_back(int value)
{
    // If the vector is full, increase its capacity
    if (m_size == m_capacity) {
        reserve(m_capacity * (m_capacity <= 128 ? 2 : 1.5));
    }
    // Add the new element to the end of the vector
    m_data[m_size++] = value;
}


void Vector::pop_back()
{
    if (m_size > 0) {
        --m_size;
    }
}

// Reserves memory for the data array to have at least the specified capacity
void Vector::reserve(size_t new_capacity)
{
    if (new_capacity > m_capacity) {
        // Allocate memory for the new data array
        int* new_data = new int[new_capacity];
        // Copy the elements from the old data array to the new data array
        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }
        // Deallocate the old data array and update the class members to use the new data array
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
}


void Vector::resize(size_t new_size, int value)
{
    if (new_size > m_size) {
        // If the new size is larger than the current size, add new elements to the end of the vector
        if (new_size > m_capacity) {
            reserve(new_size);
        }
        for (size_t i = m_size; i < new_size; ++i) {
            m_data[i] = value;
        }
    }
    // If the new size is smaller than the current size, remove elements from the end of the vector
    m_size = new_size;
}


int& Vector::operator[](size_t index)
{
    if (index >= m_size) {
        throw std::out_of_range("Vector index out of range");
    }
    return m_data[index];
}


const int& Vector::operator[](size_t index) const
{
    if (index >= m_size) {
        throw std::out_of_range("Vector index out of range");
    }
    return m_data[index];
}


std::strong_ordering Vector::operator<=>(const Vector& other) const
{
    // Compare the sizes of the two vectors
    if (m_size < other.m_size) {
        return std::strong_ordering::less;
    }
    else if (m_size > other.m_size) {
        return std::strong_ordering::greater;
    }

    // The sizes are equal, so compare the elements of the two vectors
    for (size_t i = 0; i < m_size; ++i) {
        if (m_data[i] < other.m_data[i]) {
            return std::strong_ordering::less;
        }
        else if (m_data[i] > other.m_data[i]) {
            return std::strong_ordering::greater;
        }
    }

    // All elements are equal, so the vectors are equal
    return std::strong_ordering::equal;
}


bool Vector::operator==(const Vector& other) const {
    return (*this <=> other) == std::strong_ordering::equal;
}


void Vector::insert(size_t index, int value)
{
    // If the index is equal to the current size, behave like push_back
    if (index == m_size) {
        push_back(value);
        return;
    }
    if (index > m_size) {
        throw std::out_of_range("Vector index out of range");
    }
    // If the vector is full, increase its capacity
    if (m_size == m_capacity) {
        reserve(m_capacity * (m_capacity <= 128 ? 2 : 1.5));
    }
    // Move the elements after the specified position to make room for the new element
    for (size_t i = m_size; i > index; --i) {
        m_data[i] = m_data[i - 1];
    }
    // Insert the new element at the specified position
    m_data[index] = value;
    // Increment the size of the vector
    ++m_size;
}

void Vector::erase(size_t index)
{
    if (index >= m_size) {
        throw std::out_of_range("Vector index out of range");
    }
    // Move the elements after the specified position to fill the gap left by the erased element
    for (size_t i = index; i < m_size - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }
    // Decrement the size of the vector
    --m_size;
}