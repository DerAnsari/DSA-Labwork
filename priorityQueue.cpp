
// std::priority_queue<typename Tp, typename Sequence>#include <queue>
#include <utility>
class Node {
private:
  int data;
  int *next;

public:
  Node() : data(0), next(nullptr) {}
  Node(int val) : data(val), next(nullptr) {}
};

class linkedList {};

// unordered list aproach -->
// ordered array aproach -> O(n),  O(1)

// better aproach binary heaps:
// binary tree --> specially a complete binrary tree which is one that has all
// level filled except last one in which each level starts from left to right

// Binray heap array representation
template <typename key> class MaxPQ {
private:
  char pq[] = {'\0', 'T', 'S', 'R', 'P', 'N', 'O', 'A', 'E', 'I', 'H', 'G'};
  int n = 11;

  void swim(int k) {
    while (k > 1 && pq[k / 2] < pq[k]) {
      std::swap(pq[k], pq[k / 2]);
      k = k / 2;
    }
  }

  void sink(int k) {
    while (2 * k <= n) {
      int j = 2 * k;
      if (j < n && pq[j] < pq[j + 1])
        j++;

      if (!(pq[k] < pq[j]))
        break;

      std::swap(pq[k], pq[j]);
      k = j;
    }
  }

public:
  key delmax() {
    // swap smoll and root[1]
    std::swap(pq[n--], pq[1]);

    sink(1);

    return std::move(pq[n + 1]);
    void insert(key x) {
      pq[++n] = x;
      swim(n);
    }
  }
};

class maximumPriorityQ {
private:
};
