#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    std::cout << solution.subarraySum(nums, target) << std::endl;

    return 0;
}