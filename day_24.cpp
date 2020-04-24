#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class LRUCache {
public:
    LRUCache(int capacity) {

    }

    int get(int key) {

    }

    void put(int key, int value) {

    }
};


int main() {

    auto *cache = new LRUCache(2 /* capacity */ );

    cache->put(1, 1);
    cache->put(2, 2);
    std::cout << cache->get(1) << std::endl;        // returns 1
    cache->put(3, 3);                               // evicts key 2
    std::cout << cache->get(2) << std::endl;        // returns -1 (not found)
    cache->put(4, 4);                               // evicts key 1
    std::cout << cache->get(1) << std::endl;        // returns -1 (not found)
    std::cout << cache->get(3) << std::endl;        // returns 3
    std::cout << cache->get(4) << std::endl;        // returns 4

    return 0;
}