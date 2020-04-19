#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int out = -1;
        for(int i = 0; i < nums.size(); ++i){
            if (nums[i] == target){
                out = i;
                break;
            }
        }
        return out;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    std::cout << solution.search(nums, target) << std::endl;

    return 0;
}