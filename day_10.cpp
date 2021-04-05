#include <vector>
#include <iostream>
#include <numeric>
#include <map>

using std::vector;
using std::string;
using std::map;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        minStack.push_back(x);
    }

    void pop() {
        minStack.pop_back();
    }

    int top() {
        return minStack.back();
    }

    int getMin() {
        return *std::min_element(minStack.begin(), minStack.end());
    }
private:
    vector<int> minStack;
};

// Paired-stack: each entry stores (value, min-so-far).
// All operations O(1). Space O(n).
class MinStack2 {
public:
    void push(int x) {
        if (stk.empty()) stk.push_back({x, x});
        else stk.push_back({x, std::min(x, stk.back().second)});
    }
    void pop() { stk.pop_back(); }
    int top() { return stk.back().first; }
    int getMin() { return stk.back().second; }
private:
    vector<std::pair<int,int>> stk;
};

int main() {
    struct Op { const char *name; int arg; };
    vector<Op> ops = {
        {"push",-2}, {"push",0}, {"push",-3},
        {"getMin",0}, {"pop",0}, {"top",0}, {"getMin",0},
        {"push",5}, {"push",-5}, {"getMin",0}, {"pop",0}, {"getMin",0},
        {"push",1}, {"push",1}, {"getMin",0}, {"pop",0}, {"getMin",0},
    };

    MinStack ms1;
    MinStack2 ms2;

    for (const auto &op : ops) {
        if (std::string(op.name) == "push") {
            ms1.push(op.arg);
            ms2.push(op.arg);
        } else if (std::string(op.name) == "pop") {
            ms1.pop();
            ms2.pop();
        } else if (std::string(op.name) == "top") {
            int v1 = ms1.top(), v2 = ms2.top();
            std::cout << "top: orig=" << v1 << " paired=" << v2
                      << (v1 == v2 ? " OK" : " MISMATCH") << std::endl;
        } else {
            int v1 = ms1.getMin(), v2 = ms2.getMin();
            std::cout << "getMin: orig=" << v1 << " paired=" << v2
                      << (v1 == v2 ? " OK" : " MISMATCH") << std::endl;
        }
    }

    return 0;
}

// Complexity comparison:
// MinStack  (linear scan): push O(1), pop O(1), top O(1), getMin O(n).
// MinStack2 (paired):      push O(1), pop O(1), top O(1), getMin O(1).
// Paired approach makes getMin constant at cost of storing an extra int per entry.
