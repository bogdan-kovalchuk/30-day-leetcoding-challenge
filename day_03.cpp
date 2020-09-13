#include <vector>
#include <iostream>
#include <numeric>
#include <limits>
#include <algorithm>

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

class SolutionKadane {
public:
    int maxSubArray(vector<int> &nums) {
        int best = nums[0], current = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            current = std::max(nums[i], current + nums[i]);
            best = std::max(best, current);
        }
        return best;
    }
};

class SolutionDivideConquer {
public:
    int maxSubArray(vector<int> &nums) {
        return divide(nums, 0, (int)nums.size() - 1);
    }
private:
    int divide(vector<int> &nums, int lo, int hi) {
        if (lo == hi) return nums[lo];
        int mid = lo + (hi - lo) / 2;
        int leftBest = divide(nums, lo, mid);
        int rightBest = divide(nums, mid + 1, hi);
        int leftMax = nums[mid], sum = 0;
        for (int i = mid; i >= lo; --i) {
            sum += nums[i];
            leftMax = std::max(leftMax, sum);
        }
        int rightMax = nums[mid + 1];
        sum = 0;
        for (int i = mid + 1; i <= hi; ++i) {
            sum += nums[i];
            rightMax = std::max(rightMax, sum);
        }
        return std::max({leftBest, rightBest, leftMax + rightMax});
    }
};

int main() {
    Solution solution = Solution();
    SolutionKadane solutionKadane = SolutionKadane();
    SolutionDivideConquer solutionDC = SolutionDivideConquer();
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int out = solution.maxSubArray(nums);
    vector<int> numsCopy1(nums.begin(), nums.end());
    vector<int> numsCopy2(nums.begin(), nums.end());
    int outKadane = solutionKadane.maxSubArray(numsCopy1);
    int outDC = solutionDC.maxSubArray(numsCopy2);

    std::cout << "Original: " << out << " Kadane: " << outKadane << " D&C: " << outDC << std::endl;

    return 0;
}