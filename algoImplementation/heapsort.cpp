#include <utility>

template <typename Key> class maxPQ {
  int n;
  Key *arr;

  void swim(int i) {
    while (i > 1 && arr[i / 2] < arr[i]) {
      std::swap(arr[i], arr[i / 2]);
      i = i / 2;
    }
  }

  void sink(int i) {
    while (2 * i <= n) {
      int j = 2 * i;
      if (j < n && arr[j] < arr[j + 1])
        j++;
      if (!(arr[i] < arr[j]))
        break;

      std::swap(arr[i], arr[j]);
      i = j;
    }
  }

  void buildHeap() {
    for (int i{0}; i < n; i++) {
      arr[i] = arr[i];
      sink(i);
    }
  }

  void heapSort() {
    buildHeap();
    int temp = n - 1;

    while (temp > 0) {
      std::swap(arr[1], arr[temp]);
      sink(1);
      temp--;
    }
  }
};
