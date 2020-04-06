#include <vector>
#include <iostream>
#include <numeric>
#include <limits>

using std::vector;
using std::string;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {

    }
};

int main() {
    vector<string> array_of_strings = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution solution = Solution();
    vector<vector<string>> maxProfit = solution.groupAnagrams(array_of_strings);

    return 0;
}