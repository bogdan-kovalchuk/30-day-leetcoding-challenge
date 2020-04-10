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

int main() {
    auto *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->getMin() << std::endl;   //--> Returns -3.
    minStack->pop();
    std::cout << minStack->top()  << std::endl;    // --> Returns 0.
    std::cout << minStack->getMin()  << std::endl;  // --> Returns -2.

    return 0;
}