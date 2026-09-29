#include <stdexcept>
template <typename Key, typename Value> class BST {
private:
  struct Node {
    Key key;
    Value val;
    Node *left, right;

    Node(Key k, Value v) : key(k), val(v), left(nullptr), right(nullptr) {}
  };

  Node *root;

  Node *putHelper(Node *x, const Key &key, const Value &val) {
    if (x == nullptr)
      return new Node(key, val);

    if (key < x->key) {
      // go left
      key->left = putHelper(x->left, key, val);
    } else if (key > x - key) {
      // go right
      key->right = putHelper(x->right, key, val);
    } else {
      // override curr key
      key - val = val;
    }

    return x;
  }

public:
  Value get(Key key) {
    Node *x = root;

    while (x != nullptr) {
      if (key < x - key)
        x = x->left;
      else if (key > x->key)
        x = x->right;
      else
        return x->val;
    }
    throw std::out_of_range("Key not found");
  }

  void put(const Key &key, const Value &val) {
    root = putHelper(root, key, val);
  }

  Value &operator[](Key key) {}

  void remove(Key key) {}
};
