#include <algorithm>
#include <stdexcept>

template <typename Key, typename Value> class AVLTREE {
private:
  struct Node {
    Key key;
    Value value;
    Node *left;
    Node *right;
    int height;

    Node(Key k, Value val, int h)
        : key(k), value(val), left(nullptr), right(nullptr), height(h) {}
  };
  Node *root = nullptr;

  int height(Node *n) { return (n == nullptr) ? 0 : n->height; }

  int balanceFactor(Node *n) const {
    return height(n->left) - height(n->right);
  }

  void updateHeight(Node *n) {
    n->height = 1 + std::max(height(n->left), height(n->right));
  }

  Node *rotateRight(Node *root) {
    Node *leftSubtree = root->left;
    Node *tempSubtree = leftSubtree->right;

    leftSubtree->right = root;
    root->left = tempSubtree;

    updateHeight(leftSubtree);
    updateHeight(root);

    return leftSubtree;
  }

  Node *rotateLeft(Node *root) {
    Node *rightSubtree = root->right;
    Node *tempSubtree = rightSubtree->left;

    rightSubtree->left = root;
    root->right = tempSubtree;

    updateHeight(rightSubtree);
    updateHeight(root);

    return rightSubtree;
  }

  Node *rebalance(Node *root) {
    updateHeight(root);
    int bFactor = balanceFactor(root);

    if (bFactor > 1) {
      if (balanceFactor(root->left) < 0)
        root->left = rotateLeft(root->left);
      return rotateRight(root);
    }
    if (bFactor < -1) {
      if (balanceFactor(root->right) > 0)
        root->right = rotateRight(root->right);
      return rotateLeft(root);
    }

    return root;
  }

public:
  void put(const Key &key, const Value &val) {}

  Value get(Key key) const {
    Node *n = root;

    while (n != nullptr) {
      if (key < n->key)
        n = n->left;
      else if (n->key < key)
        n = n->right;
      else
        return n->value;
    }
    throw std::out_of_range("Key not found");
  }

  void remove(Key key) {}
};
