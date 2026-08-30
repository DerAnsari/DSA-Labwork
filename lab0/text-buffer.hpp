#pragma once
#include "stack.hpp"
#include <string>

// =============================
// Part D: Text Buffer
// =============================
//
// COMPLETED

// --- TextBuffer using ArrayStack ---
class TextBufferArray {
private:
  ArrayStack left;
  ArrayStack right;

public:
  void insert(char c) { left.push(c); }

  void remove() {
    if (right.empty())
      return;

    right.pop();
  }

  void moveLeft() {
    if (left.empty())
      return;

    char leftVal = left.pop();
    right.push(leftVal);
  }

  void moveRight() {
    if (right.empty())
      return;

    char rightVal = right.pop();
    left.push(rightVal);
  }

  // WHY LIKE THIS?
  std::string getText() {
    std::string r = right.to_string();
    return left.to_string() + std::string(r.rbegin(), r.rend());
  }
};

// --- TextBuffer using LinkedListStack ---
class TextBufferList {
private:
  LinkedListStack left;
  LinkedListStack right;

public:
  void insert(char c) { left.push(c); }

  void remove() {
    if (right.empty())
      return;

    right.pop();
  }

  void moveLeft() {
    if (left.empty())
      return;

    char leftval = left.top();
    left.pop();
    right.push(leftval);
  }

  void moveRight() {
    if (right.empty())
      return;

    char rightval = right.top();
    right.pop();
    left.push(rightval);
  }

  std::string getText() {
    std::string l = left.to_string();
    return std::string(l.rbegin(), l.rend()) + right.to_string();
  }
};
