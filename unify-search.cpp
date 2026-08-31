#include <iostream>
#include <vector>
class QuickFind {
private:
  std::vector<int> data;
  int n;

public:
  QuickFind(int n) : n(n) {
    int value;
    for (int i{0}; i < n; i++) {
      std::cin >> value;
    }
  }

  void unify(int v1, int v2) {
    for (int i{0}; i < n; i++) {
      if (data[i] == v2)
        data[i] = v1;
    }
  }

  int find(int val) { return data[val]; }
};

class quickUnion {
private:
  std::vector<int> data;
  int n;

public:
  quickUnion(int n) : n(n) {
    int value;
    for (int i{0}; i < n; i++) {
      std::cin >> value;
    }
  }

  int find(int val) {
    while (val != data[val]) {
      val = data[val];
    }
    return val;
  }

  void unify(int v1, int v2) {
    int i{find(v1)};
    int j{find(v2)};

    data[i] = j;
  }
};

class weightedQuickUnion {
private:
  std::vector<int> parent;
  std::vector<int> capacity;

public:
  weightedQuickUnion(int n) : parent(n), capacity(n, 1) {
    for (int i{0}; i < n; i++)
      parent[i] = i;
  }

  int find(int val) {
    while (val != parent[val])
      val = parent[val];
    return val;
  }

  void unify(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);

    if (p == q)
      return;

    // we gotta swap the damn thing
  }
};

int main() {}
