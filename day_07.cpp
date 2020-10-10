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

class SolutionSingleMap {
public:
    int countElements(vector<int> &arr) {
        std::unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        int count = 0;
        for (const auto &p : freq) {
            if (freq.count(p.first + 1))
                count += p.second;
        }
        return count;
    }
};

int main() {
    Solution solution;
    SolutionSingleMap solutionSingle;
    vector<int> nums = {1, 3, 2, 3, 5, 0};

    int r1 = solution.countElements(nums);
    vector<int> c(nums);
    int r2 = solutionSingle.countElements(c);

    std::cout << "TwoMap: " << r1 << " SingleMap: " << r2 << std::endl;

    return 0;
}