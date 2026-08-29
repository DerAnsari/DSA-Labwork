#pragma once
#include "linked-list.hpp"
#include "resizable-array.hpp"
#include <string>

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
  std::string to_string() { return arr.to_string(); }

  void push(char value) {
    // Add a new character to the top of the stack.
    // ----- TODO -------
    arr.push_back(value);
  }

  char pop() {
    // Remove and return the top character from the stack.
    // If the stack is empty, handle it appropriately (e.g., throw an
    // exception).
    // ----- TODO -------
    char toPop = arr.back(arr.size());
    arr.pop_back();
    return toPop; // Placeholder return value, should be replaced with actual
                  // implementation
  }

  char top() const {
    // Return the top element of the stack without removing it.
    // If the stack is empty, handle it appropriately (e.g., throw an
    // exception).
    // ----- TODO -------
    return arr.back(arr.size());
    // Placeholder return value, should be replaced with actual
    // implementation
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
  std::string to_string() const { return list.to_string(); }

  void push(char value) {
    // Add a new character to the top of the stack.
    // ----- TODO -------
    list.push_front(value);
  }

  void pop() {
    // Remove the top character from the stack.
    // If the stack is empty, handle it appropriately (e.g., throw an
    // exception).
    // ----- TODO -------
    list.pop_front();
  }

  char top() const {
    // Return the top element of the stack without removing it.
    // If the stack is empty, handle it appropriately (e.g., throw an
    // exception).
    // ----- TODO -------
    return list.front(); // Placeholder return value, should be replaced with
                         // actual implementation
  }
};
