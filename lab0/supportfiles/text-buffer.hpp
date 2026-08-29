#pragma once
#include "stack.hpp"
#include <stdexcept>
#include <string>

// =============================
// Part D: Text Buffer
// =============================

// --- TextBuffer using ArrayStack ---
class TextBufferArray {
private:
  ArrayStack left;  // characters to the left of cursor
  ArrayStack right; // characters to the right of cursor

public:
  void insert(char c) {
    // Insert character c at the cursor position (i.e., push onto left stack)
    // ----- TODO -------
    left.push(c);
  }

  void remove() {
    // Remove the character at the cursor position (i.e., pop from right stack)
    // Handle the case when the right stack is empty (i.e., no character to
    // remove)
    // ----- TODO -------
    if (right.empty())
      throw std::out_of_range("Its empty");

    right.pop();
  }

  void moveLeft() {
    // Move the cursor one position to the left (i.e., pop from left stack and
    // push onto right stack) Handle the case when the left stack is empty
    // (i.e., cursor is at the beginning of the text)
    // ----- TODO -------
    if (left.empty()) {
      throw std::invalid_argument("Wrong to do");
    }
    char leftVal = left.pop();
    right.push(leftVal);
  }

  void moveRight() {
    // Move the cursor one position to the right (i.e., pop from right stack and
    // push onto left stack) Handle the case when the right stack is empty
    // (i.e., cursor is at the end of the text)
    // ----- TODO -------

    if (right.empty()) {
      throw std::invalid_argument("Wrong to do");
    }
    char rightVal = right.pop();
    left.push(rightVal);
  }

  std::string getText() {
    // Return the current text in the buffer as a string
    // This may involve combining the contents of the left and right stacks
    // ----- TODO -------
    return left.to_string() +
           right.to_string(); // Placeholder return value, should be replaced
                              // with actual implementation
  }
};

// --- TextBuffer using LinkedListStack ---
class TextBufferList {
private:
  LinkedListStack left;
  LinkedListStack right;

public:
  void insert(char c) {
    // Insert character c at the cursor position (i.e., push onto left stack)
    // ----- TODO -------
    left.push(c);
  }

  void remove() {
    // Remove the character at the cursor position (i.e., pop from right stack)
    // Handle the case when the right stack is empty (i.e., no character to
    // remove)
    // ----- TODO -------
    right.pop();
  }

  void moveLeft() {
    // Move the cursor one position to the left (i.e., pop from left stack and
    // push onto right stack) Handle the case when the left stack is empty
    // (i.e., cursor is at the beginning of the text)
    // ----- TODO -------

    if (left.empty()) {
      throw std::invalid_argument("Wrong to do");
    }
    left.pop();
    char leftval = left.top();
    right.push(leftval);
  }

  void moveRight() {
    // Move the cursor one position to the right (i.e., pop from right stack and
    // push onto left stack) Handle the case when the right stack is empty
    // (i.e., cursor is at the end of the text)
    // ----- TODO -------

    if (right.empty()) {
      throw std::invalid_argument("Wrong to do");
    }
    right.pop();
    char rightval = right.top();
    right.push(rightval);
  }

  std::string getText() {
    // Return the current text in the buffer as a string
    // This may involve combining the contents of the left and right stacks
    // ----- TODO -------
    return left.to_string() +
           right.to_string(); // Placeholder return value, should be replaced
                              // with actual implementation
  }
};
