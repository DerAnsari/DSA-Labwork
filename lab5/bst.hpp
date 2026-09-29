#pragma once

#include <algorithm>
#include <climits>
#include <cstddef>
#include <queue>
#include <tuple>
#include <vector>

struct Node {
  int key;
  Node *left;
  Node *right;
  Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Number of nodes in the tree (provided; see lab handout).
int size(Node *root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + size(root->left) + size(root->right);
}

// Free every node in the tree (provided).
void destroy(Node *root) {
  if (root == nullptr)
    return;
  destroy(root->left);
  destroy(root->right);
  delete root;
}

// ---------------------------------------------------------------
// Part A & B: Level order
// ---------------------------------------------------------------

// Part A: keys of the tree level by level, left to right.
std::vector<int> levelOrder(Node *root) {
  // TODO: use a std::queue<Node*>. Start with the root; repeatedly
  // remove a node, record its key, and add its non-null children
  // (left, then right) to the queue.
  std::vector<int> results;
  std::queue<Node *> trace;
  trace.push(root);
  Node *curr;

  if (root == nullptr)
    return results;

  while (!trace.empty()) {
    curr = trace.front();
    results.push_back(curr->key);

    if (curr->left != nullptr)
      trace.push(curr->left);
    if (curr->right != nullptr)
      trace.push(curr->right);

    trace.pop();
  }
  return results;
}

constexpr long long LOW = LLONG_MIN;
constexpr long long HIGH = LLONG_MAX;

// Part B: rebuild the BST whose level order traversal is `keys` and return
// its root (nullptr if keys is empty).
Node *buildFromLevelOrder(const std::vector<int> &keys) {
  // TODO: use either approach from the lab handout:
  //   1. insert the keys one by one into an empty BST, or
  //   2. a queue of (node, min, max) entries for O(n) time.
  // return nullptr;  placeholder return value

  if (keys.empty())
    return nullptr;

  Node *root = new Node(keys[0]);
  std::queue<std::tuple<Node *, long long, long long>> q;

  q.push({root, LOW, HIGH});
  size_t i{1};

  while (!q.empty() && i < keys.size()) {
    auto [node, lo, hi] = q.front();
    q.pop();

    if (i < keys.size() && keys[i] > lo && keys[i] < node->key) {
      node->left = new Node(keys[i++]);
      q.push({node->left, lo, node->key});
    }

    if (i < keys.size() && keys[i] > node->key && keys[i] < hi) {
      node->right = new Node(keys[i++]);
      q.push({node->right, node->key, hi});
    }
  }

  return root;
}

// ---------------------------------------------------------------
// Part C: Recursive methods
// Conventions: the root has depth 0; an empty tree has height -1.
// ---------------------------------------------------------------

// Maximum depth of any node in the tree.
int height(Node *root) {
  // TODO
  if (root == nullptr)
    return -1;

  return 1 + std::max(height(root->left),
                      height(root->right)); // placeholder return value
}

// Number of nodes with an odd key.
int sizeOdd(Node *root) {
  // TODO
  if (root == nullptr)
    return 0;

  int count = (root->key % 2 != 0) ? 1 : 0;
  return count + sizeOdd(root->left) + sizeOdd(root->right);
}

// At every node, do the left and right subtrees have the same height?
bool isPerfectlyBalanced(Node *root) {
  // TODO
  if (root == nullptr)
    return true;

  return (height(root->left) == height(root->right)) &&
         isPerfectlyBalanced(root->left) && isPerfectlyBalanced(root->right);
}

// Is every node semi-balanced? (see lab handout for the definition)
bool isSemiBalanced(Node *root) {
  // TODO
  if (root == nullptr)
    return true;

  int a = size(root->left);
  int b = size(root->right);
  int L = std::max(a, b);
  int S = std::min(a, b);

  return (L + 1 <= 2 * (S + 1)) && isSemiBalanced(root->left) &&
         isSemiBalanced(root->right);
}

// Number of nodes at depth d.
int sizeAtDepth(Node *root, int d) {
  // TODO
  if (root == nullptr)
    return 0;

  if (d == 0)
    return 1;

  return sizeAtDepth(root->left, d - 1) + sizeAtDepth(root->right, d - 1);
}

// Number of nodes whose depth is < d.
int sizeAboveDepth(Node *root, int d) {
  // TODO
  if (root == nullptr)
    return 0;

  if (d <= 0)
    return 0;

  return 1 + sizeAboveDepth(root->left, d - 1) +
         sizeAboveDepth(root->right, d - 1);
}

// Number of nodes whose depth is > d.
int sizeBelowDepth(Node *root, int d) {
  // TODO
  if (root == nullptr)
    return 0;

  if (d < 0)
    return size(root);

  return sizeBelowDepth(root->left, d - 1) + sizeBelowDepth(root->right, d - 1);
}
