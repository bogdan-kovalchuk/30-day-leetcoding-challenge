#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using std::vector;
using std::map;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;
        map<int, int> countMap;

        for (auto num : nums) {
            countMap[num]++;
        }

        for (auto item : countMap) {
            if (item.second == 1) {
                result = item.first;
                break;
            }
        }

        return result;
    }
};

class SolutionXOR {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (auto num : nums) {
            result ^= num;
        }
        return result;
    }
};

class SolutionSort {
public:
    int singleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 1 < (int)nums.size(); i += 2) {
            if (nums[i] != nums[i + 1]) return nums[i];
        }
        return nums.back();
    }
};

int main() {
    Solution solution = Solution();
    SolutionXOR solutionXOR = SolutionXOR();
    SolutionSort solutionSort = SolutionSort();
    vector<int> nums = {2, 2, 5, 8, 9, 5, 1, 1, 9};
    vector<int> numsCopy1(nums.begin(), nums.end());
    vector<int> numsCopy2(nums.begin(), nums.end());

    int out = solution.singleNumber(nums);
    int outXOR = solutionXOR.singleNumber(numsCopy1);
    int outSort = solutionSort.singleNumber(numsCopy2);

    std::cout << "Map: " << out << " XOR: " << outXOR << " Sort: " << outSort << std::endl;

    return 0;
}