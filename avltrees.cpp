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

  int height(Node *n) const { return (n == nullptr) ? 0 : n->height; }

  Node *minNode(Node *n) {
    while (n->left != nullptr)
      n = n->left;
    return n;
  }
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

  Node *putHelper(Node *root, const Key &key, const Value &val) {
    if (root == nullptr)
      return new Node(key, val, 1);

    if (key < root->key)
      root->left = putHelper(root->left, key, val);
    else if (key > root->key)
      root->right = putHelper(root->right, key, val);
    else {
      root->value = val;
      return root;
    }

    return rebalance(root);
  }

  Node *removeHelper(Node *root, const Key &key) {
    if (root == nullptr)
      throw std::out_of_range("Key Not Found");

    if (key < root->key)
      root->left = remove(root->left, key);
    else if (key > root->key)
      root->right = remove(root->right, key);
    else {
      if (root->left == nullptr || root->right == nullptr) {
        Node *deleted = (root->left == nullptr) ? root->right : root->left;
        delete root;
        return deleted;
      }

      Node *s = min(root->right);
      root->key = s->key;
      root->value = s->value;
      root->right = remove(root->right, s->key);
    }
    return rebalance(root);
  }

public:
  void put(const Key &key, const Value &val) {
    root = putHelper(root, key, val);
  }

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

  void remove(const Key &key) { root = removeHelper(root, key); }
};
