
#include <iostream>
#include <stdexcept>
#include <compare>

class Vector {
public:
    // Constructor: creates a vector with the specified size and value for each element
    explicit Vector(size_t size = 0, int value = 0);

    // Copy constructor: creates a new vector that is a copy of another vector
    Vector(const Vector &other);

    // Move constructor: creates a new vector that takes ownership of another vector's resources
    Vector(Vector&& other) noexcept;

    // Destructor: deallocates memory used by the data array
    ~Vector() { delete[] m_data; }

    // Swaps the contents of this vector with another vector
    void swap(Vector &other);

    // Adds an element to the end of the vector
    void push_back(int value);

    // Removes the last element of the vector
    void pop_back();

    // Reserves memory for the data array to have at least the specified capacity
    void reserve(size_t new_capacity);

    // Resizes the vector to the specified size, adding or removing elements as necessary
    void resize(size_t new_size, int value = 0);

    // Returns the number of elements in the vector
    [[nodiscard]] size_t size() const { return m_size; }

    // Returns the amount of memory currently allocated for the data array
    [[nodiscard]] size_t capacity() const { return m_capacity; }

    // Returns true if the vector is empty (i.e., it contains no elements)
    [[nodiscard]] bool empty() const { return m_size == 0; }

    // Removes all elements from the vector
    void clear() { m_size = 0; }

    // Returns a pointer to the data array
    int *data() { return m_data; }

    // Returns a const pointer to the data array
    [[nodiscard]] const int *data() const { return m_data; }

    // Assignment operator: replaces the contents of this vector with a copy of another vector
    Vector &operator=(const Vector &other);

    // Returns a reference to the element at the specified index, allowing it to be modified
    int &operator[](size_t index);

    // Returns a const reference to the element at the specified index, allowing it to be read but not modified
    const int &operator[](size_t index) const;

    // Three-way comparison operator
    std::strong_ordering operator<=>(const Vector& other) const;

    // Define the == operator for the Vector class
    bool operator==(const Vector& other) const;

    // Inserts a value at the specified position in the vector
    void insert(size_t index, int value);

    // Erases the element at the specified position in the vector
    void erase(size_t index);

protected:
    size_t m_size;      // The number of elements in the vector
    size_t m_capacity;  // The amount of memory allocated for the data array
    int *m_data;        // A pointer to the data array
};
