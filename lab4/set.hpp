#pragma once

#include <stdexcept>
#include <vector>

template <typename Key> class Set {
private:
  std::vector<Key> keys_; // kept sorted in ascending order, no duplicates
  // Return the index of the smallest element in keys_ that is >= key
  // (i.e. where key belongs, or already sits, in the sorted array).
  // Return keys_.size() if key is larger than every element.
  // Do NOT use std::lower_bound / std::binary_search / std::find.
  int binarySearchHelper(const Key &key, int low, int high) const {
    // TODO: implement binary search over keys_.

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
    // TODO: use binarySearch to check whether key is present.
    //
    if (keys_.empty())
      return false;
    int idx = binarySearch(key);
    return idx < static_cast<int>(keys_.size()) &&
           keys_[idx] == key; // placeholder return value
  }

  void add(const Key &key) {
    // TODO: find the insertion point with binarySearch. If key is
    // already present, do nothing. Otherwise shift every element
    // from that point onward up by one slot and place key there.
    // Do not use vector::insert.

    if (contains(key))
      return;

    int idx = binarySearch(key);
    keys_.push_back(0);

    for (int i{static_cast<int>(keys_.size())}; i > idx; i--) {
      keys_[i] = keys_[i - 1];
    }
    keys_[idx] = keys_[key];
    // first i add 0 to the end of vector
    // then i go backwards untill i have found the insertion point
    // then i swap the two values
  }

  void remove(const Key &key) {
    // TODO: find key with binarySearch. If present, shift every
    // element above it down by one slot to close the gap.
    // Do not use vector::erase.

    if (!contains(key))
      return;

    int idx = binarySearch(key);

    for (int i{idx}; i < keys_.size() - 1; i++) {
      keys_[i] = keys_[i + 1];
    }

    keys_.pop_back();
  }

  Key ceiling(const Key &key) const {
    // TODO: smallest key in the set >= given key.
    // Throw std::runtime_error if no such key exists.
    int idx = binarySearch(key);
    if (idx >= size())
      throw std::runtime_error("no ceiling for key");
    return keys_[idx];
  }

  int rank(const Key &key) const {
    // TODO: number of keys in the set strictly smaller than key.
    //
    int idx = binarySearch(key);

    if (!contains(key))
      return -1;
    else
      return idx;
  }

  Key select(int i) const {
    // TODO: the i-th largest key in the set (see lab handout).
    // Throw std::runtime_error if i is out of range.
    if (i > keys_.size())
      throw std::runtime_error("index out of range");

    return keys_[i];
  }

  Key min() const {
    // TODO: return the smallest key in the set.
    // Throw std::runtime_error if the set is empty.
    if (keys_.empty())
      throw std::runtime_error("set is empty");

    return keys_[0];
  }
};
