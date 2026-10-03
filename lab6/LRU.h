#pragma once

#include <iostream>
#include <list>
#include <map>
#include <stdexcept>

// LRU cache of ints holding at most capacity items.
class LRU {
private:
    int capacity_;
    std::list<int> order_;                         // items, most recently accessed first
    std::map<int, std::list<int>::iterator> pos_;  // item -> its node in order_

public:
    LRU(int capacity) : capacity_(capacity) {}

    // Insert item if not already present, evicting the least recently
    // accessed item if the cache is over capacity; mark item as the most
    // recently accessed.
    void access(int item) {
        // TODO
    }

    // Remove and return the least recently accessed item.
    // Throw std::out_of_range if the cache is empty.
    int remove() {
        // TODO
        throw std::out_of_range("cache is empty");
    }

    // Print the items from most recent to least recent access.
    void print() const {
        // TODO
    }

    bool contains(int item) const {
        // TODO
        return false; // placeholder return value
    }

    int size() const {
        // TODO
        return -1; // placeholder return value
    }

    bool empty() const {
        // TODO
        return false; // placeholder return value
    }
};
