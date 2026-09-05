#pragma once

#include <vector>

class UF {
private:
  std::vector<int> parent, size;

public:
  UF(int n) : parent(n), size(n) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int i) {
    // TODO: return the root of the set containing i.
    // Use path compression: while searching, make every node
    // point directly to the root (or use recursion).
    int root = parent[i];
    if (parent[i] == i)
      return parent[i];

    parent[i] = find(parent[i]);
    return parent[i];
  }

  void unify(int p, int q) {
    // TODO: merge the sets containing p and q.
    // Use union by size: attach the root of the smaller tree
    // under the root of the larger tree.
    int pRoot = find(p);
    int qRoot = find(q);

    if (pRoot == qRoot)
      return;

    if (size[pRoot] < size[qRoot]) {
      parent[pRoot] = qRoot;
      size[qRoot] += size[pRoot];
    } else {
      parent[qRoot] = pRoot;
      size[pRoot] += size[qRoot];
    }
  }
};
