#include <vector>
#include <iostream>
#include <numeric>
#include <limits>
#include <string>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i != j) {
            if (nums[i] == 0) {
                for (int k = i; k < j; k++) {
                    nums[k] = nums[k + 1];
                }
                nums[j] = 0;
                j--;
                i--;
            }
            i++;
        }
    }
};

class SolutionSwap {
public:
    void moveZeroes(vector<int> &nums) {
        int write = 0;
        for (int read = 0; read < (int)nums.size(); ++read) {
            if (nums[read] != 0) {
                std::swap(nums[write], nums[read]);
                ++write;
            }
        }
    }
};

int main() {
    Solution solution;
    SolutionSwap solutionSwap;

    auto runBoth = [&](vector<int> v, const std::string &label) {
        vector<int> c(v);
        solution.moveZeroes(v);
        solutionSwap.moveZeroes(c);
        bool ok = (v == c);
        std::cout << label << ": Shift=[";
        for (size_t i = 0; i < v.size(); ++i) std::cout << (i ? "," : "") << v[i];
        std::cout << "] Swap=[";
        for (size_t i = 0; i < c.size(); ++i) std::cout << (i ? "," : "") << c[i];
        std::cout << "]" << (ok ? " OK" : " MISMATCH") << std::endl;
    };

    runBoth({0, 1, 0, 3, 12}, "general");
    runBoth({0, 0, 1}, "leading zeros");
    runBoth({1, 0, 0}, "trailing zeros");
    runBoth({0, 0}, "all zeros");
    runBoth({1, 2, 3}, "no zeros");
    runBoth({}, "empty");

    std::cout << "\nComplexity comparison:" << std::endl;
    std::cout << "Shift: O(n^2) worst case (shift per zero), O(1) space" << std::endl;
    std::cout << "Swap:  O(n) time, O(1) space, minimal writes" << std::endl;

    return 0;
}