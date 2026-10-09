#include <iostream>
#include <utility>
#include <vector>

class quickFindUF {
private:
  std::vector<int> leaders;

public:
  quickFindUF(int n) : leaders(n) {
    for (int i{0}; i < n; i++)
      leaders[i] = i;
  }

  void unify(int x, int y) {
    int leaderX = leaders[x];
    int leaderY = leaders[y];

    if (leaderX == leaderY)
      return;

    for (int &i : leaders)
      if (i == leaderY)
        i = leaderX;
  }

  int find(int x) { return leaders[x]; }
};

class quickUnionUF {
private:
  std::vector<int> parents;

public:
  quickUnionUF(int n) : parents(n) {
    for (int i{0}; i < n; i++)
      parents[i] = i;
  }

  int find(int x) {

    // regular way
    // while (parents[x] != x)
    //   x = parents[x];
    // return x;

    // path compression
    if (parents[x] != x)
      parents[x] = find(parents[x]);
    return parents[x];
  }

  void unify(int x, int y) {
    int leaderX = find(x);
    int leaderY = find(y);

    if (leaderX == leaderY)
      return;

    parents[leaderY] = leaderX;
  }
};

class weightedQuickUnionUF {
private:
  std::vector<int> parents;
  std::vector<int> size;

public:
  weightedQuickUnionUF(int n) : parents(n), size(n) {
    for (int i{0}; i < n; i++) {
      parents[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    while (parents[x] != x)
      x = parents[x];
    return x;
  }

  void unify(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY)
      return;

    // swap the roots based on which is smaller
    if (size[rootX] > size[rootY])
      std::swap(rootX, rootY);

    parents[rootY] = rootX;
    size[rootX] += size[rootY];
  }
};

int main() {
  // testing quick find
  // quickFindUF UF(5);
  // quickUnionUF UF(5);
  weightedQuickUnionUF UF(5);

  UF.unify(3, 2);
  UF.unify(3, 4);
  UF.unify(3, 1);
  std::cout << UF.find(2) << UF.find(1) << UF.find(3) << std::endl;
}
