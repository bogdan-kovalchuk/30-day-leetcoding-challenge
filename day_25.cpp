#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        for (const auto &num : nums){
            num >= max_jump - 1 ? max_jump = num : --max_jump;

            if(num == 0 && max_jump == 0 && &nums.back() != &num){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums = {2,3,1,1,1,0};

    std::cout << solution.canJump(nums) << std::endl;

    return 0;
}