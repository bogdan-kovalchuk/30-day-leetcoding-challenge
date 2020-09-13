#include <vector>
#include <iostream>
#include <numeric>
#include <limits>
#include <algorithm>
#include <string>

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
    Solution solution;
    SolutionKadane solutionKadane;
    SolutionDivideConquer solutionDC;

    auto runAll = [&](vector<int> v, const std::string &label) {
        vector<int> c1(v), c2(v);
        int r1 = solution.maxSubArray(v);
        int r2 = solutionKadane.maxSubArray(c1);
        int r3 = solutionDC.maxSubArray(c2);
        bool ok = (r1 == r2) && (r2 == r3);
        std::cout << label << ": Orig=" << r1 << " Kadane=" << r2 << " D&C=" << r3
                  << (ok ? " OK" : " MISMATCH") << std::endl;
    };

    runAll({-2, 1, -3, 4, -1, 2, 1, -5, 4}, "general");
    runAll({-3, -2, -5}, "all negative");
    runAll({5}, "single element");
    runAll({1, 2, 3}, "all positive");
    runAll({-1, 0, -2}, "with zero");

    std::cout << "\nComplexity comparison:" << std::endl;
    std::cout << "Original:  O(n^2) worst case, O(n) space for cumulative sums" << std::endl;
    std::cout << "Kadane:    O(n) time, O(1) space" << std::endl;
    std::cout << "D&C:       O(n log n) time, O(log n) stack space" << std::endl;

    return 0;
}