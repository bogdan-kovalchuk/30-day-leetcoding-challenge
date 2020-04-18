#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int min = INT_MAX;
        cumulate_sum(grid, 0, 0, 0, min);
        return min;
    }

    void cumulate_sum(const vector<vector<int>> &grid, int i, int j, int sum, int &min) {
        if (i < grid.size() - 1) {
            cumulate_sum(grid, i + 1, j, sum + grid[i][j], min);
        }
        if (j < grid[0].size() - 1) {
            cumulate_sum(grid, i, j + 1, sum + grid[i][j], min);
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1 && sum + grid[i][j] < min) {
            min = sum + grid[i][j];
        }
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