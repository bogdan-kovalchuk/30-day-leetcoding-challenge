#include <vector>
#include <iostream>
#include <map>

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

int main() {
    Solution solution = Solution();
    vector<int> nums = {2, 2, 5, 8, 9, 5, 1, 1, 9};

    int out = solution.singleNumber(nums);

    std::cout << out << std::endl;

    return 0;
}