#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int countElements(vector<int> &arr) {
        std::unordered_map<int, int> old_arr_map;
        std::unordered_map<int, int> new_arr_map;
        int count = 0;
        for (auto elem : arr) {
            old_arr_map[elem]++;
            new_arr_map[++elem]++;
        }

        for (const auto &elem : new_arr_map) {
            if (old_arr_map.find(elem.first) != old_arr_map.end()) {
                count += elem.second;
            }

        }
        return count;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> nums = {1, 3, 2, 3, 5, 0};
//    vector<int> nums = {1, 1, 2, 2};
//    vector<int> nums = {1, 1, 2};

    int count = solution.countElements(nums);

    std::cout << count << std::endl;

    return 0;
}