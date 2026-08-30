#pragma once
#include <stdexcept>
#include <string>

// ============================================================================
// Part A: Resizable Array of characters
// Complete the implementation of the ResizableArray class below.
// You will need to implement the resize, push_back, pop_back, and get methods.
// ============================================================================
//
// *COMPLETED IT*

class ResizableArray {
private:
  int _capacity;
  int _size;
  char *data;

  void resize(int newCapacity) {
    char *newData = new char[newCapacity];

    for (int i{0}; i < _size; i++) {
      newData[i] = data[i];
    }

    _capacity = newCapacity;
    delete[] data;
    data = newData;
  }

public:
  ResizableArray() : _capacity(2), _size(0), data(new char[_capacity]) {}
  ~ResizableArray() { delete[] data; }

  int size() const { return _size; };

  bool empty() const { return _size == 0; };

  std::string to_string() const {
    std::string result(_size, '\0');
    for (int i{0}; i < _size; ++i) {
      result[i] = data[i];
    }
    return result;
  }

  void push_back(char value) {
    if (size() == _capacity)
      resize(2 * _capacity);

    data[_size++] = value;
  }

  void pop_back() {
    if (empty())
      throw std::underflow_error("empty array");

    if (size() < _capacity / 4)
      resize(_capacity / 2);

    _size--;
  }

  char back(int index) const {
    if (index >= _size || index < 0)
      throw std::out_of_range("Index Out of bounds");

    return data[index];
  }
};
