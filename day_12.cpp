#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {

    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {2, 7, 4, 1, 8, 1};

    int count = solution.lastStoneWeight(nums);

    std::cout << count << std::endl;

    return 0;
}