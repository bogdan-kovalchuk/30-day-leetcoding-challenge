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

// Prefix sum + vector offset: sum ranges from -n to +n,
// so use vector of size 2n+1 with offset n. O(1) lookups vs hash map.
// Time: O(n). Space: O(n).
class Solution3 {
public:
    int findMaxLength(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        vector<int> first_seen(2 * n + 1, -2);
        int offset = n;
        first_seen[0 + offset] = -1;
        int sum = 0, best = 0;
        for (int i = 0; i < n; ++i) {
            sum += (nums[i] == 1 ? 1 : -1);
            int idx = sum + offset;
            if (first_seen[idx] >= -1) {
                best = std::max(best, i - first_seen[idx]);
            } else {
                first_seen[idx] = i;
            }
        }
        return best;
    }
};

int main() {
    Solution s1;
    Solution2 s2;
    Solution3 s3;

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
        auto v1 = nums, v2 = nums, v3 = nums;
        int r1 = s1.findMaxLength(v1);
        int r2 = s2.findMaxLength(v2);
        int r3 = s3.findMaxLength(v3);
        std::cout << "map=" << r1 << " brute=" << r2 << " vec=" << r3
                  << ((r1 == r2 && r2 == r3) ? " OK" : " MISMATCH") << std::endl;
    }

    return 0;
}

// Complexity comparison:
// Solution  (prefix sum + hash map):  Time O(n) avg, Space O(n).
// Solution2 (brute force):            Time O(n^2),     Space O(1).
// Solution3 (prefix sum + vec offset): Time O(n),       Space O(n).
// Vector offset avoids hash collisions and gives predictable O(1) lookups.
