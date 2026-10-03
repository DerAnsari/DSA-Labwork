#pragma once

#include <iostream>
#include <stdexcept>
#include "bst.hpp"

// Mutable string: the characters are the values of a BST<double, char>
// in inorder (see the lab handout).
class Mstring {
private:
    BST<double, char> st_;

public:
    // Length of the string.
    int size() {
        // TODO
        return -1; // placeholder return value
    }

    // Return the i-th character (0-based).
    char get(int i) {
        // TODO
        return '?'; // placeholder return value
    }

    // Insert c so that it becomes the i-th character (0 <= i <= size()).
    void insert(int i, char c) {
        // TODO
    }

    // Delete the i-th character.
    void remove(int i) {
        // TODO
    }

    // Print the entire string.
    void print() {
        // TODO
    }
};
