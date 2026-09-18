#pragma once
#include <cstdlib>
#include <random>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename Key> class MinPQ {
private:
  std::vector<Key> pq; // Index 0 is unused

public:
  MinPQ() : pq(1) {}

  const Key &min() const {
    if (empty())
      throw std::runtime_error("Priority queue underflow");
    return pq[1];
  }

  const bool empty() const { return pq.size() == 1; }

  const int size() const { return pq.size() - 1; }

  void insert(const Key &x) {
    // Insert new element at the end of the heap
    // and then swim it to restore heap order
    pq.push_back(x);
    swim(pq.size() - 1);
  }

  Key delMin() {
    // Add underflow check and resizing logic
    if (pq.size() == 1)
      throw std::runtime_error("Priority queue underflow");

    // Exchange the root of the heap with the last element
    // and then sink the new root to restore heap order
    std::swap(pq[1], pq.back());
    const auto min = std::move(pq.back());
    pq.pop_back();
    sink(1);
    return min;
  }

  Key delRandom() {
    // Add underflow check and resizing logic
    if (pq.size() == 1)
      throw std::runtime_error("Priority queue underflow");

    int R = pq.size() - 1;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> intDist(1, R);
    int randIdx = intDist(rng);

    // Exchange the root of the heap with the last element
    // and then sink the new root to restore heap order
    std::swap(pq[randIdx], pq.back());
    const auto val = std::move(pq.back());

    pq.pop_back();

    if (randIdx < static_cast<int>(pq.size())) {
      sink(randIdx);
      swim(randIdx);
    }

    return val;
  }

private:
  void swim(int k) {
    while (k > 1 && pq[k / 2] > pq[k]) {
      std::swap(pq[k], pq[k / 2]);
      k = k / 2;
    }
  }

  void sink(int k) {
    int n = pq.size() - 1;
    while (2 * k <= n) {
      int j = 2 * k;
      if (j < n && pq[j] > pq[j + 1])
        j++;
      if (!(pq[k] > pq[j]))
        break;
      std::swap(pq[k], pq[j]);
      k = j;
    }
  }
};
