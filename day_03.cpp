#include <vector>
#include <iostream>
#include <numeric>
#include <limits>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = INT_MIN;
        vector<int> sums;
        vector<int> cum_sums;
        for (auto num : nums) {
            if (num > 0) {
                cum_sums.push_back(0);
            } else if (num > sum) {
                sum = num;
            }

            for (auto &cum_sum : cum_sums) {
                cum_sum += num;
            }

            if (num > 0) {
                sums.insert(sums.end(), cum_sums.begin(), cum_sums.end());
            }
        }

        if (!sums.empty()) {
            sum = *max_element(sums.begin(), sums.end());
        }

        return sum;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int out = solution.maxSubArray(nums);

    std::cout << out << std::endl;

    return 0;
}