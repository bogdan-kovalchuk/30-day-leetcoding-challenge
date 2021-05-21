#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> num_map;
        int sum = 0, max_sub_arr = 0;
        num_map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            if (num_map.find(sum) != num_map.end()) {
                max_sub_arr = std::max(max_sub_arr, i - num_map[sum]);
            } else {
                num_map[sum] = i;
            }
        }
        return max_sub_arr;
    }
};

// Brute force: check every subarray, count 0s and 1s.
// Time: O(n^2). Space: O(1).
class Solution2 {
public:
    int findMaxLength(vector<int> &nums) {
        int best = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int zeros = 0, ones = 0;
            for (int j = i; j < static_cast<int>(nums.size()); ++j) {
                if (nums[j] == 0) ++zeros; else ++ones;
                if (zeros == ones) best = std::max(best, j - i + 1);
            }
        }
        return best;
    }
};

int main() {
    Solution s1;
    Solution2 s2;

    vector<vector<int>> cases = {
        {0, 1},
        {0, 1, 0},
        {0, 1, 1},
        {0, 0, 1, 1, 0, 1, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {},
        {0, 1, 0, 1, 0, 1},
        {1, 0, 0, 1, 1, 0},
    };

    for (const auto &nums : cases) {
        auto v1 = nums, v2 = nums;
        int r1 = s1.findMaxLength(v1);
        int r2 = s2.findMaxLength(v2);
        std::cout << "map=" << r1 << " brute=" << r2
                  << (r1 == r2 ? " OK" : " MISMATCH") << std::endl;
    }

    return 0;
}

// Complexity comparison:
// Solution  (prefix sum + hash map): Time O(n), Space O(n).
// Solution2 (brute force):           Time O(n^2), Space O(1).
// Hash-map approach is optimal; brute force useful as reference for small inputs.
