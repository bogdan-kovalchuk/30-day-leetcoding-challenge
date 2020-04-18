#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {

    }
};

int main() {
    Solution solution = Solution();

    vector<vector<int>> grid{{1, 3, 1},
                             {1, 5, 1},
                             {4, 2, 1}};

    std::cout << solution.minPathSum(grid) << std::endl;

    return 0;
}