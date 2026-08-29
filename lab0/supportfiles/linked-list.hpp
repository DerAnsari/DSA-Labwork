#pragma once
#include <stdexcept>
#include <string>

// =============================================================================
// Part B: Singly linked List of characters
// Complete the implementation of the LinkedList class below.
// You will need to implement the push_front, push_back, and pop_front methods.
// =============================================================================

class LinkedList {
private:
  struct Node {
    char data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
  };
  Node *head;
  int _size;

public:
  LinkedList() : head(nullptr), _size(0) {}
  ~LinkedList() {
    while (!empty())
      pop_front();
  }

  bool empty() const { return _size == 0; }
  int size() const { return _size; }

  std::string to_string() const {
    std::string result(_size, '\0');
    int i = 0;
    Node *current = head;
    while (current != nullptr) {
      result[i++] = current->data;
      current = current->next;
    }
    return result;
  }

  void push_front(int value) {
    Node *newFront = new Node(value);
    newFront->next = head;
    head = newFront;
    _size++;
  }

  char pop_front() {
    if (empty())
      throw std::underflow_error("LinkedList is empty");

    Node *tempPtr = head;
    head = head->next;
    char popVal = tempPtr->data;
    delete tempPtr;
    return popVal;
  }

  char pop_back(int value) {
    // TODO maybe
  }

  char front() const {
    if (empty())
      throw std::underflow_error("LinkedList is empty");

    return head->data;
  }
};
