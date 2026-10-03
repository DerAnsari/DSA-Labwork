#pragma once

#include <vector>
#include <cassert>
#include <stdexcept>
#include <stack>
#include <queue>
#include <iostream>

template<typename Key, typename Value>
class BST {
    struct Node {
        std::pair<const Key,Value> data;
        Node *left, *right;
        int count;
        Node(Key k, Value v, int c=1)
            : data {k, v},
              left{nullptr}, right{nullptr},
              count{c} {  }
    };

    Node* root;

    public:
    BST() : root{nullptr} {  }
    ~BST() { remove_all(root); }

    private:
    void remove_all(Node* x) {
        if (x == nullptr) return;
        remove_all(x->left);
        remove_all(x->right);
        delete x;
    }

    public:
    Value& get(const Key& key) {
        Node *x = root;
        while (x != nullptr) {
            if(key < x->data.first)
                x = x->left;
            else if (x->data.first < key)
                x = x->right;
            else
                return x->data.second;
        }
        throw std::out_of_range("Key not found");
    }

    void put(const Key& key, const Value& val) {
        root = put(root, key, val);
    }

    private:
    Node* put(Node* x, const Key& key, const Value& val)  {
        if (x == nullptr) return new Node(key, val, 1);

        if (key < x->data.first)
            x->left  = put(x->left,  key, val);
        else if (x->data.first < key)
            x->right = put(x->right, key, val);
        else
            x->data.second = val;
        x->count = 1 + size(x->left) + size(x->right);
        return x;
    }

    public:
    Value& operator[](const Key& key) {
        root = ensure_key(root, key);
        return get(key);
    }

    private:
    Node* ensure_key(Node* x, const Key& key) {
        if (x == nullptr) return new Node(key, Value(), 1);

        if (key < x->data.first)
            x->left  = ensure_key(x->left,  key);
        else if (x->data.first < key)
            x->right = ensure_key(x->right, key);

        x->count = 1 + size(x->left) + size(x->right);
        return x;
    }


    public:
    const Key& min() {
        if (root == nullptr)
            throw std::out_of_range("called min() with empty symbol table");
        Node* x = min(root);
        return x->data.first;
    }

    private:
    Node* min(Node* x) {
        while (x->left != nullptr) x = x->left;
        return x;
    }

    public:
    const Key& floor(const Key& key) {
        return floor(root, key);
    }

    private:
    const Key& floor(Node* x, const Key& key, Node* champ=nullptr) {
        if (x == nullptr) {
            if(champ==nullptr)
                throw std::out_of_range("No such floor key");
            return champ->data.first;
        }

        if (key == x->data.first) return key;

        if (key < x->data.first)
            return floor(x->left, key, champ);

        return floor(x->right, key, x);
    }

    public:
    const Key& ceil(const Key& key) {
        return ceil(root, key);
    }

    private:
    const Key& ceil(Node* x, const Key& key, Node* champ=nullptr) {
        if (x == nullptr) {
            if(champ==nullptr)
                throw std::out_of_range("No such floor key");
            return champ->data.first;
        }

        if (key == x->data.first) return key;

        if (key < x->data.first)
            return ceil(x->left, key, x);

        return ceil(x->right, key, champ);
    }

    public:
    int size() {
        return size(root);
    }

    private:
    int size(Node* x) {
        if (x == nullptr) return 0;
        return x->count;
    }

    public:
    int rank(Key key) {
        return rank(root, key);
    }

    private:
    int rank(Node* x, const Key& key) {
        if (x == nullptr) return 0;

        if (key < x->data.first)
            return rank(x->left, key);
        else if (key > x->data.first)
            return 1 + size(x->left) + rank(x->right, key);
        else
            return size(x->left);
    }

    public:
    Key select(int k) {
        if (k < 0 || k >= size())
            throw std::out_of_range("called select() with invalid argument");

        Node* x = select(root, k);
        return x->data.first;
    }

    private:
    Node* select(Node* x, int k) {
        assert(x != nullptr);

        int t = size(x->left);
        if (t > k)
            return select(x->left,  k);
        else if (t < k)
            return select(x->right, k-t-1);
        else
            return x;
    }

    public:
    void removeMin() {
        if(root == nullptr)
            throw std::out_of_range("Symbol table underflow");
        Node* d = nullptr;
        root = removeMin(root, d);
        delete d;
    }

    private:
    Node* removeMin(Node* x, Node*& d) {
        if (x->left == nullptr) {
            Node* right = x->right;
            d = x; // to be removed
            return right;
        }
        x->left  = removeMin(x->left, d);
        x->count = 1 + size(x->left) + size(x->right);
        return x;
    }

    public:
    void remove(const Key& key) {
        root = remove(root, key);
    }

    private:
    Node* remove(Node* x, const Key& key) {
        if (x == nullptr) throw std::out_of_range("Key not found");

        if (key < x->data.first)
            x->left  = remove(x->left,  key);

        else if (x->data.first < key)
            x->right = remove(x->right, key);

        else {
            if (x->right == nullptr || x->left  == nullptr) {
                Node* ch = x->right==nullptr ? x->left : x->right;
                delete x;
                return ch;
            }

            Node* s = nullptr;
            x->right = removeMin(x->right, s);
            s->left = x->left;
            s->right = x->right;

            delete x;
            x = s;
        }
        x->count = size(x->left) + size(x->right) + 1;
        return x;
    }

    public:
    class iterator {
        std::vector<Node*> stack;
        public:
        iterator(Node* r) {
            while(r) {
                stack.push_back(r);
                r = r->left;
            }
        }
        iterator& operator++() {
            if(stack.empty())
                throw std::out_of_range("Incrementing end iterator");
            Node* x = stack.back();
            stack.pop_back();
            if(x->right) {
                x = x->right;
                while(x) {
                    stack.push_back(x);
                    x = x->left;
                }
            }
            return *this;
        }
        bool operator!=(const iterator& other) const {
            return stack != other.stack;
        }
        std::pair<const Key, Value>& operator*() {
            if(stack.empty())
                throw std::out_of_range("Dereferencing end iterator");
            Node* x = stack.back();
            return x->data;
        }

        std::pair<const Key, Value>* operator->() {
            if(stack.empty())
                throw std::out_of_range("Dereferencing end iterator");
            Node* x = stack.back();
            return &(x->data);
        }

    };

    public:
    iterator begin() { return iterator(root); }
    iterator end()   { return iterator(nullptr); }

    public:
    void print() { print(root);}

    private:
    void print(Node* x) {
        // In-order traversal
        if (x == nullptr) return;
        print(x->left);
        std::cout << "[" << x->data.first << ":" << x->data.second << "]  ";
        print(x->right);
    }

    public:
    void in_order() {
        std::stack<Node*> q;
        Node* x = root;
        while(x || !q.empty()) {
            while(x) {
                q.push(x);
                x = x->left;
            }
            x = q.top(); q.pop();
            std::cout << "[" << x->data.first << ":" << x->data.second << "]  ";
            x = x->right;
        }
    }

    public:
    void level_order() {
        if (root == nullptr) return;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* x = q.front(); q.pop();
            std::cout << "[" << x->data.first << ":" << x->data.second << "]  ";
            if(x->left)  q.push(x->left);
            if(x->right) q.push(x->right);
        }
    }
};
