#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> toRight = {1};
        vector<int> toLeft = {1};
        vector<int> output;
        for (int i = 0, j = nums.size() - 1; i < nums.size() - 1; i++, j--) {
            toRight.push_back(toRight[i] * nums[i]);
            toLeft.insert(toLeft.begin(), toLeft.front() * nums[j]);
        }
        for (int i = 0; i < nums.size(); i++) {
            output.emplace_back(toRight[i] * toLeft[i]);
        }

        return output;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums = {1, 2, 3, 4};

    vector<int> out = solution.productExceptSelf(nums);

    for (const auto &n : out) {
        std::cout << n << " ";
    }

    return 0;
}