#include <stdexcept>
#include <utility>
template <typename Key, typename Value> class BinarySearchTree {
private:
  struct Node {
    Key key;
    Value value;
    Node *Left;
    Node *Right;

    Node(Key k, Value v) : key(k), value(v), Left(nullptr), Right(nullptr) {}
  };

  Node *Root{nullptr};

  Node *insertHelper(Node *Root, const Key &key, const Value &val) {
    if (Root == nullptr)
      return new Node(key, val);

    if (key < Root->key)
      Root->Left = insertHelper(Root->Left, key, val);
    else if (key > Root->key)
      Root->Right = insertHelper(Root->Right, key, val);
    else
      Root->value = val;
    return Root;
  }

  Node *removeMinHelper(Node *Root) {
    if (Root->Left == nullptr) {
      Node *right = Root->Right;
      delete Root;
      return right;
    }
    Root->Left = removeMinHelper(Root->Left);
    return Root;
  }

  Node *removeHeper(Node *Root, const Key &key) {
    if (Root == nullptr)
      throw std::invalid_argument("Key don't exist bro");

    if (key < Root->key)
      Root->Left = removeHeper(Root->Left, key);
    else if (key > Root->key)
      Root->Right = removeHeper(Root->Right, key);
    else {
      if (Root->Right == nullptr || Root->Left == nullptr) {
        Node *leftOver = Root->Right == nullptr ? Root->Left : Root->Right;
        delete Root;
        return leftOver;
      }
      // Find the successsor ???
      Node *successor = Root->Right;
      while (successor->Left != nullptr)
        successor = successor->Left;

      std::swap(Root->key, successor->key);
      std::swap(Root->value, successor->value);
      Root->Right = removeMinHelper(Root->Right);
    }
    return Root;
  }

public:
  void Insert(const Key &key, const Value &val) {
    Root = insertHelper(Root, key, val);
  }

  Value find(const Key &key) {
    Node *current = Root;

    while (current != nullptr) {
      if (key < current->key)
        current = current->Left;

      else if (key > current->key)
        current = current->Right;
      else
        return current->value;
    }
    throw std::invalid_argument("This key doesnt exist bro");
  }

  void removeMin() {
    if (Root == nullptr)
      throw std::invalid_argument("This key doesnt exist bro");
    Root = removeMinHelper(Root);
  }

  // we will use hibbard deletion to find the successsor
  void remove(Key &key) { Root = removeHeper(Root, key); };
};
