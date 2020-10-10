#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <algorithm>

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

class SolutionSort {
public:
    int countElements(vector<int> &arr) {
        if (arr.empty()) return 0;
        sort(arr.begin(), arr.end());
        int count = 0;
        int runLen = 1;
        for (size_t i = 1; i <= arr.size(); ++i) {
            if (i < arr.size() && arr[i] == arr[i - 1]) {
                ++runLen;
            } else {
                if (i < arr.size() && arr[i] == arr[i - 1] + 1)
                    count += runLen;
                runLen = 1;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    SolutionSingleMap solutionSingle;
    SolutionSort solutionSort;
    vector<int> nums = {1, 3, 2, 3, 5, 0};

    int r1 = solution.countElements(nums);
    vector<int> c1(nums.begin(), nums.end());
    int r2 = solutionSingle.countElements(c1);
    vector<int> c2(nums.begin(), nums.end());
    int r3 = solutionSort.countElements(c2);

    std::cout << "TwoMap: " << r1 << " SingleMap: " << r2 << " Sort: " << r3 << std::endl;

    return 0;
}