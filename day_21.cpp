#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
public:
    int get(int x, int y);

    vector<int> dimensions();
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {

    }
};

int main() {
    Solution solution = Solution();

    BinaryMatrix preorder;

    std::cout << solution.leftMostColumnWithOne(preorder) << std::endl;

    return 0;
}