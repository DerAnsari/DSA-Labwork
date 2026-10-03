#pragma once

#include <cmath>
#include <iostream>
#include <map>

// Sparse vector of doubles: only the nonzero entries are stored.
class Svector {
private:
  std::map<int, double> entries_; // index -> nonzero value

public:
  // Set the i-th entry to x (if x == 0, remove the entry if it exists).
  void set(int i, double x) {
    // TODO

    if (x == 0)
      entries_.erase(x);
    else
      entries_.insert({i, x});
  }

  // Return the i-th entry (0 if not present).
  double get(int i) const {
    // TODO
    auto it = entries_.find(i);
    return (it == entries_.end()) ? 0 : it->second;
  }

  // Dot product of this vector with that, in time proportional to the
  // total number of nonzero entries in both vectors.
  double dot(const Svector &that) const {
    // TODO
    double total{0};
    auto it = entries_.begin();
    while (it != entries_.end()) {
      auto match = entries_.find(it->first);

      if (match != that.entries_.end()) {
        double product = match->second * it->second;
        total += product;
      }

      ++it;
    }

    return total;
  }

  // Euclidean norm.
  double norm() const {
    // TODO
    auto it = entries_.begin();
    double total{0};

    while (it != entries_.end()) {
      total += it->second * it->second;
    }
    return std::sqrt(total);
  }

  // Sum of this vector and that.
  Svector add(const Svector &that) const {
    // TODO
    return Svector(); // placeholder return value
  }

  // Multiply this vector by alpha (scaling by 0 removes every entry).
  void scale(double alpha) {
    // TODO
  }

  // Print the nonzero entries as {(i1,x1), (i2,x2), ...}
  void print() const {
    // TODO
  }
};
