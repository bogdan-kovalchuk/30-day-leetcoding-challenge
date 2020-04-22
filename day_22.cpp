#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        if (nums.empty()) return 0;

        int size = nums.size();
        if (size == 1 && nums[0] == k) return 1;
        if (size == 1 && nums[0] != k) return 0;

        int subarray_sum_count = 0, tmp_sum = 0;
        vector<int> sums;

        for (const auto &val : nums) {
            tmp_sum += val;
            sums.emplace_back(tmp_sum);
            if (tmp_sum == k) ++subarray_sum_count;
        }

        for (int i = 0; i < sums.size(); ++i){
            for (int j = i; j < size; ++j){


            }
        }
        return 0;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums = {1, 1, 1};
    int target = 2;

    std::cout << solution.subarraySum(nums, target) << std::endl;

    return 0;
}