//
// Created by axavi on 3/24/2026.
//

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdexcept>
#include <vector>

/**
 * Array-backed stack implemented with std::vector.
 * pop() / top() throw std::out_of_range when the stack is empty.
 */
template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) { data.push_back(value); }

    void pop() {
        if (data.empty()) throw std::out_of_range("ArrayStack::pop on empty stack");
        data.pop_back();
    }

    T top() const {
        if (data.empty()) throw std::out_of_range("ArrayStack::top on empty stack");
        return data.back();
    }

    bool empty() const { return data.empty(); }

    int size() const { return static_cast<int>(data.size()); }
};

#endif  // ARRAYSTACK_H