#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>

using std::vector;
using std::unordered_map;
using std::string;
using std::list;
using std::cout;
using std::endl;

class FirstUnique {
public:
    FirstUnique(vector<int> &nums) {
        for (auto num :nums) add(num);
    }

    int showFirstUnique() {
        return unique.empty() ? -1 : unique.front();
    }

    void add(int value) {
        if (iter_map.find(value) != iter_map.end()) {
            auto iter = iter_map[value];
            if (iter != unique.end()) {
                unique.erase(iter);
                iter_map[value] = unique.end();
            }
        } else {
            unique.emplace_back(value);
            iter_map[value] = --unique.end();
        }
    }

private:
    unordered_map<int, list<int>::iterator> iter_map;
    list<int> unique;
};

int main() {
    vector<int> nums = {2, 3, 5};
    auto *firstUnique = new FirstUnique(nums);
    cout << firstUnique->showFirstUnique() << endl; // return 2
    firstUnique->add(5);                            // the queue is now [2,3,5,5]
    cout << firstUnique->showFirstUnique() << endl; // return 2
    firstUnique->add(2);                            // the queue is now [2,3,5,5,2]
    cout << firstUnique->showFirstUnique() << endl; // return 3
    firstUnique->add(3);                            // the queue is now [2,3,5,5,2,3]
    cout << firstUnique->showFirstUnique() << endl; // return -1
    return 0;
}