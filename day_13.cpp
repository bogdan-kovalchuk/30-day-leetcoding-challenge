#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {0,1,0};
//    vector<int> nums = {1, 1, 2, 2};
//    vector<int> nums = {1, 1, 2};

    int max_length = solution.findMaxLength(nums);

    std::cout << max_length << std::endl;

    return 0;
}