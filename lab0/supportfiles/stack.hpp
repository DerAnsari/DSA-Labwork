#pragma once
#include <string>
#include "resizable-array.hpp"
#include "linked-list.hpp"


// =============================
// Part C: Stack Implementations
// =============================

// --- Stack using ResizableArray ---
class ArrayStack {
private:
    ResizableArray arr;

public:
    // Return true if the stack is empty, false otherwise
    bool empty() const { return arr.empty(); }

    // Return the contents of char stack as a string
    std::string to_string() {
        return arr.to_string();
    }

    void push(char value) {
        // Add a new character to the top of the stack.
        // ----- TODO -------
    }

    char pop() {
        // Remove and return the top character from the stack.
        // If the stack is empty, handle it appropriately (e.g., throw an exception).
        // ----- TODO -------
        return '\0'; // Placeholder return value, should be replaced with actual implementation
    }

    char top() const {
        // Return the top element of the stack without removing it.
        // If the stack is empty, handle it appropriately (e.g., throw an exception).
        // ----- TODO -------
        return '\0'; // Placeholder return value, should be replaced with actual implementation
    }
};

// --- Stack using LinkedList ---
class LinkedListStack {
private:
    LinkedList list;

public:
    // Return true if the stack is empty, false otherwise
    bool empty() const { return list.empty(); }

    // Return the contents of char stack as a string
    std::string to_string() const {
        return list.to_string();
    }

    void push(char value) {
        // Add a new character to the top of the stack.
        // ----- TODO -------
    }

    void pop() {
        // Remove the top character from the stack.
        // If the stack is empty, handle it appropriately (e.g., throw an exception).
        // ----- TODO -------
    }

    char top() const {
        // Return the top element of the stack without removing it.
        // If the stack is empty, handle it appropriately (e.g., throw an exception).
        // ----- TODO -------
        return '\0'; // Placeholder return value, should be replaced with actual implementation
    }
};
