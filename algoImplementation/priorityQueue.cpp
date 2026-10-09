#include <utility>
template <typename Key> class maxPQ {
private:
  int n;
  Key *pq;

  void swim(int i) {
    while (i > 1 && pq[i / 2] < pq[i]) {
      std::swap(pq[i], pq[i / 2]);
      i = i / 2;
    }
  }

  void sink(int i) {
    while (2 * i <= n) {
      int j = 2 * i;
      if (j < n && pq[j] < pq[j + 1])
        j++;
      if (!(pq[i] < pq[j]))
        break;

      std::swap(pq[i], pq[j]);
      i = j;
    }
  }

public:
  maxPQ(int cap) : n(0), pq(new Key[cap + 1]) {}
  ~maxPQ() { delete[] pq; }

  bool empty() { return n == 0; }

  int size() { return n; }

  void insert(Key value) {
    pq[++n] = value;
    swim(n);
  }

  Key deleteMax() {
    std::swap(pq[1], pq[n--]);
    sink(1);

    return std::move(pq[n + 1]);
  }

  // WE DONT GOTTA WORRY ABOUT THIS
  // void heapSort() {
  //   for (int i{0}; i < n; i++)
  //     swim(i);
  //
  //   int j{n - 1};
  //   while (j > 0) {
  //     std::swap(pq[1], pq[j]);
  //     sink(j);
  //     j--;
  //   }
  // }

  Key deleteMin() {
    // TODO
  }
};
