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
  bool empty() const { return arr.empty(); }

  std::string to_string() { return arr.to_string(); }

  void push(char value) { arr.push_back(value); }

  char pop() {
    char toPop = arr.back(arr.size() - 1);
    arr.pop_back();
    return toPop;
  }

  char top() const { return arr.back(arr.size() - 1); }
};

// --- Stack using LinkedList ---
class LinkedListStack {
private:
  LinkedList list;

public:
  bool empty() const { return list.empty(); }

  std::string to_string() const { return list.to_string(); }

  void push(char value) { list.push_front(value); }

  void pop() { list.pop_front(); }

  char top() const { return list.front(); }
};
