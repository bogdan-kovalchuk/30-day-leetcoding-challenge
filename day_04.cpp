#include <vector>
#include <iostream>
#include <numeric>
#include <limits>

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

int main() {
    Solution solution = Solution();
    vector<int> nums = {0,1,0,3,12};

    solution.moveZeroes(nums);

    for (const auto &num: nums) {
        std::cout << num << " ";
    }

    return 0;
}