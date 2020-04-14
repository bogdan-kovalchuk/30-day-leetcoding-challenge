#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {

    }
};

int main() {
    Solution solution = Solution();

    string s = "abc";
    vector<vector<int>> shift = {{0,1},{1,2}};

    string str = solution.stringShift(s, shift);

    std::cout << str << std::endl;

    return 0;
}