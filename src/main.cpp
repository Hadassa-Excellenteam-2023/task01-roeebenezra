#pragma once

#include <iostream>
#include <stdexcept>
#include "Stack.h"

using namespace std;

int main() {

/************ Vector class tests ***************/

    // Test the default constructor
    Vector v1;
    if (!v1.empty() || v1.capacity() != 1) {
        std::cerr << "Default constructor test failed" << std::endl;
        return 1;
    }

    // Test the constructor with size and value arguments
    Vector v2(5, 2);
    if (v2.size() != 5 || v2.capacity() < 5 || v2[0] != 2) {
        std::cerr << "Constructor with size and value test failed" << std::endl;
        return 1;
    }

    // Test the copy constructor
    Vector v3(v2);
    if (v3.size() != 5 || v3.capacity() < 5 || v3[0] != 2 || v3[4] != 2) {
        std::cerr << "Copy constructor test failed" << std::endl;
        return 1;
    }

    // Test the assignment operator
    Vector v4;
    v4 = v3;
    if (v4.size() != 5 || v4.capacity() < 5 || v4[0] != 2 || v4[4] != 2) {
        std::cerr << "Assignment operator test failed" << std::endl;
        return 1;
    }

    // Test the subscript operator
    v4[1] = 3;
    if (v4[1] != 3) {
        std::cerr << "Subscript operator test failed" << std::endl;
        return 1;
    }

    // Test the push_back method
    v4.push_back(4);
    if (v4.size() != 6 || v4.capacity() < 6 || v4[5] != 4) {
        std::cerr << "push_back method test failed" << std::endl;
        return 1;
    }

    // Test the pop_back method
    v4.pop_back();
    if (v4.size() != 5 || v4.capacity() < 6 || v4[4] == 4) {
        std::cerr << "pop_back method test failed" << std::endl;
        return 1;
    }

    // Test the insert method
    v4.insert(2, 5);
    if (v4.size() != 6 || v4.capacity() < 6 || v4[2] != 5 || v4[3] != 2) {
        std::cerr << "insert method test failed" << std::endl;
        return 1;
    }

    // Test the insert method with index equal to size
    v4.insert(v4.size(), 6);
    if (v4.size() != 7 || v4.capacity() < 7 || v4[6] != 6) {
        std::cerr << "insert method test with index equal to size failed" << std::endl;
        return 1;
    }

    // Test the erase method
    v4.erase(1);
    if (v4.size() != 6 || v4.capacity() < 7 || v4[1] != 5 || v4[3] != 2) {
        std::cerr << "erase method test failed" << std::endl;
        return 1;
    }
    try {
        v4.erase(10);
        std::cerr << "erase method test failed - no exception thrown for out of range";
        // Test the erase method with out of range index
    } catch (const std::out_of_range& e) {
        // Exception should be thrown for out of range index
    } catch (...) {
        std::cerr << "erase method test failed - wrong exception thrown for out of range index" << std::endl;
        return 1;
    }

    // Test the reserve method
    v4.reserve(10);
    if (v4.capacity() < 10) {
        std::cerr << "reserve method test failed" << std::endl;
        return 1;
    }

    // Test the clear method
    v4.clear();
    if (!v4.empty() || v4.capacity() < 10) {
        std::cerr << "clear method test failed" << std::endl;
        return 1;
    }

    // Test the data method
    Vector v5(0);
    v5.push_back(1);
    if (v5.data() == nullptr || v5.data()[0] != 1) {
        std::cerr << "data method test failed for non-empty vector" << std::endl;
        return 1;
    }

    // Test the comparison operator
    Vector v6(3, 2);
    if (v5 > v6 || !(v5 < v6) || v5 == v6) {
        std::cerr << "comparison operator test failed" << std::endl;
        return 1;
    }

    // All vector tests passed
    std::cout << "All Vector Class tests passed" << std::endl;


/************************* Stack class tests *****************************/

    // Test the default constructor
    Stack s1;
    if (!s1.isEmpty() || s1.capacity() != 1) {
        std::cerr << "Default constructor test failed" << std::endl;
        return 1;
    }

    // Test the constructor with size and value arguments
    Stack s2(5, 2);
    if (s2.size() != 5 || s2.capacity() < 5) {
        std::cerr << "Constructor with size and value test failed" << std::endl;
        return 1;
    }

    // Test the copy constructor
    Stack s3(s2);
    if (s3.size() != 5 || s3.capacity() < 5) {
        std::cerr << "Copy constructor test failed" << std::endl;
        return 1;
    }

    // Test the assignment operator
    Stack s4;
    s4 = s3;
    if (s4.size() != 5 || s4.capacity() < 5) {
        std::cerr << "Assignment operator test failed" << std::endl;
        return 1;
    }

    // Test the pop method
    s4.pop();
    if (s4.size() != 4) {
        std::cerr << "Stack pop method test failed" << std::endl;
        return 1;
    }

    // Test the push_back method
    s4.push(4);
    if (s4.size() != 5 || s4.capacity() < 5 || s4.data()[0] != 4) {
        std::cerr << "Stack push method test failed" << std::endl;
        return 1;
    }

    // Test the comparison operator
    Stack s5(3, 2);
    if (s4 < s5 || !(s4 > s5) || s4 == s5 || !(s4 != s5)) {
        std::cerr << "Comparison operator test failed" << std::endl;
        return 1;
    }

    // Test the Arithmetic operators
    s5 += 5;
    s5 -= 1;
    s5 /= 2;
    s5 *= 4;
    if (s5.data()[0] != 12) {
        std::cerr << "Add-equal operator test failed" << std::endl;
        return 1;
    }

    // Test the Add stacks operators
    s5 = s5 + s4;
    if (s5.size() != 8) {
        std::cerr << "Add two stacks to one operator test failed" << std::endl;
        return 1;
    }

    s5 += s4;
    if (s5.size() != 13 || s5.data()[12] != 2) {
        std::cerr << "Add two stacks to one operator test failed" << std::endl;
        return 1;
    }

    // All stack tests passed
    std::cout << "All Stack Class tests passed" << std::endl;
    return 0;
}
