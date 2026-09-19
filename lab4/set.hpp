#pragma once

#include <stdexcept>
#include <vector>

template <typename Key> class Set {
private:
  std::vector<Key> keys_;
  int binarySearchHelper(const Key &key, int low, int high) const {
    if (low > high)
      return low;

    int mid = low + (high - low) / 2;

    if (keys_[mid] == key)
      return mid;
    else if (keys_[mid] > key)
      return binarySearchHelper(key, low, mid - 1);
    else
      return binarySearchHelper(key, mid + 1, high);
  }

  int binarySearch(const Key &key) const {
    return binarySearchHelper(key, 0, static_cast<int>(keys_.size()) - 1);
  }

public:
  Set() {}

  int size() const { return keys_.size(); }

  bool contains(const Key &key) const {
    if (keys_.empty())
      return false;

    int idx = binarySearch(key);

    return idx < static_cast<int>(keys_.size()) &&
           keys_[idx] == key; // placeholder return value
  }

  void add(const Key &key) {
    if (contains(key))
      return;

    int idx = binarySearch(key);

    keys_.push_back(0);

    for (int i{static_cast<int>(keys_.size())}; i > idx; i--) {
      keys_[i] = keys_[i - 1];
    }

    keys_[idx] = keys_[key];
  }

  void remove(const Key &key) {
    if (!contains(key))
      return;

    int idx = binarySearch(key);

    for (int i{idx}; i < keys_.size() - 1; i++) {
      keys_[i] = keys_[i + 1];
    }

    keys_.pop_back();
  }

  Key ceiling(const Key &key) const {
    int idx = binarySearch(key);

    if (idx >= size())
      throw std::runtime_error("no ceiling for key");

    return keys_[idx];
  }

  int rank(const Key &key) const {
    int idx = binarySearch(key);

    if (!contains(key))
      return -1;
    else
      return idx;
  }

  Key select(int i) const {
    if (i > keys_.size())
      throw std::runtime_error("index out of range");

    return keys_[i];
  }

  Key min() const {
    if (keys_.empty())
      throw std::runtime_error("set is empty");

    return keys_[0];
  }
};
