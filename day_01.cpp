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

int main() {
    Solution solution = Solution();
    SolutionXOR solutionXOR = SolutionXOR();
    vector<int> nums = {2, 2, 5, 8, 9, 5, 1, 1, 9};

    int out = solution.singleNumber(nums);
    int outXOR = solutionXOR.singleNumber(nums);

    std::cout << "Map: " << out << " XOR: " << outXOR << std::endl;

    return 0;
}