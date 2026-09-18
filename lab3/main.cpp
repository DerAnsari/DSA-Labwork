#include "minpq.hpp"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;

struct Item {
  long long sum;
  int i, j;

  bool operator>(const Item &other) const { return sum > other.sum; }
};

static long long cube(long long x) { return x * x * x; }

static MinPQ<Item> makePQ(int n) {
  MinPQ<Item> pq;
  for (int i = 0; i <= n; i++)
    pq.insert({cube(i) + cube(i), i, i});
  return pq;
}

void printSorted(int n) {
  MinPQ<Item> pq = makePQ(n);

  while (!pq.empty()) {
    Item cur = pq.delMin();
    cout << cur.sum << " = " << cur.i << "^3 + " << cur.j << "^3\n";

    if (cur.j < n)
      pq.insert({cube(cur.i) + cube(cur.j + 1), cur.i, cur.j + 1});
  }
}

void findPairs(int n) {
  MinPQ<Item> pq = makePQ(n);

  Item prev{-1, -1, -1};
  while (!pq.empty()) {
    Item cur = pq.delMin();

    if (cur.sum == prev.sum)
      cout << cur.sum << " = " << prev.i << "^3 + " << prev.j
           << "^3 = " << cur.i << "^3 + " << cur.j << "^3\n";

    if (cur.j < n)
      pq.insert({cube(cur.i) + cube(cur.j + 1), cur.i, cur.j + 1});

    prev = cur;
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " n [pairs]\n";
    return 1;
  }

  int n = std::stoi(argv[1]);
  if (n < 0) {
    cerr << "n must be non-negative\n";
    return 1;
  }

  if (argc >= 3 && std::string(argv[2]) == "pairs")
    findPairs(n);
  else
    printSorted(n);

  return 0;
}
