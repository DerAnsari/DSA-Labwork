#pragma once
#include "maxpq.hpp"
#include "minpq.hpp"
#include <stdexcept>

template <typename Key> class dynamicMedian {
private:
  MinPQ<Key> lilpq;
  MaxPQ<Key> bigpq;

  void balance() {
    if (bigpq.size() > lilpq.size() + 1)
      lilpq.insert(bigpq.delMax());
    else if (lilpq.size() > bigpq.size())
      bigpq.insert(lilpq.delMin());
  }

public:
  dynamicMedian() = default;

  void insert(Key val) {
    if (bigpq.empty() || val <= bigpq.max())
      bigpq.insert(val);
    else
      lilpq.insert(val);
    balance();
  }

  Key median() const {
    if (bigpq.empty())
      throw std::runtime_error("Priority Queue is empty man");
    return bigpq.max();
  }

  Key removeMedian() {
    if (bigpq.empty())
      throw std::runtime_error("Priority Queue is empty man");
    Key med = bigpq.delMax();
    balance();
    return med;
  }
};
