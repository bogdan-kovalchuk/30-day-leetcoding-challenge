#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        while (stones.size() > 1) {
            std::sort(stones.begin(), stones.end(), std::greater<int>());
            if (stones[0] > stones[1]) {
                stones[0] -= stones[1];
                stones.erase(stones.begin() + 1);

            } else if (stones[0] < stones[1]) {
                stones[1] -= stones[0];
                stones.erase(stones.begin());
            } else {
                stones.erase(stones.begin(), stones.begin() + 2);
            }
        }
        if (stones.size() == 1) {
            return stones[0];
        } else {
            return 0;
        }
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {2, 7, 4, 1, 8, 1};
//    vector<int> nums = {2, 2};

    int count = solution.lastStoneWeight(nums);

    std::cout << count << std::endl;

    return 0;
}