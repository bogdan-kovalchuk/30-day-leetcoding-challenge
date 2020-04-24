#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        int out = -1;
        if (cache.find(key) != cache.end()){
            out = cache[key];
            auto it = find(last_used.begin(), last_used.end(), key);
            int index = distance(last_used.begin(), it);
            last_used.erase(last_used.begin() + index);
            last_used.push_back(key);
        }
        return out;
    }

    void put(int key, int value) {
        if (cache.find(key) == cache.end()){
            if (last_used.size() == capacity){
                auto last = last_used.begin();
                cache.erase(*last);
                last_used.erase(last);
            }
        } else {
            auto it = find(last_used.begin(), last_used.end(), key);
            int index = distance(last_used.begin(), it);
            last_used.erase(last_used.begin() + index);
        }
        cache[key] = value;
        last_used.emplace_back(key);
    }
private:
    int capacity = 0;
    vector<int> last_used;
    unordered_map<int, int> cache;
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