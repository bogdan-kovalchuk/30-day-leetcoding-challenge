#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

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
    vector<int> edge1 = {1};
    vector<int> edge2 = {-1, -1, -2};
    vector<int> edge3 = {0, 0, 3};

    auto runAll = [&](vector<int> v, const std::string &label) {
        vector<int> c1(v.begin(), v.end());
        vector<int> c2(v.begin(), v.end());
        int r1 = solution.singleNumber(v);
        int r2 = solutionXOR.singleNumber(c1);
        int r3 = solutionSort.singleNumber(c2);
        bool ok = (r1 == r2) && (r2 == r3);
        std::cout << label << ": Map=" << r1 << " XOR=" << r2 << " Sort=" << r3
                  << (ok ? " OK" : " MISMATCH") << std::endl;
    };

    runAll(nums, "general");
    runAll(edge1, "single element");
    runAll(edge2, "all negative");
    runAll(edge3, "with zero");

    std::cout << "\nComplexity comparison:" << std::endl;
    std::cout << "Map:  O(n) time, O(n) space" << std::endl;
    std::cout << "XOR:  O(n) time, O(1) space" << std::endl;
    std::cout << "Sort: O(n log n) time, O(1) space" << std::endl;

    return 0;
}