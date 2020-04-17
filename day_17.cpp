#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int number_of_islands = 0;
        int num_rows = grid.size();
        if (num_rows == 0) return number_of_islands;
        int num_columns = grid[0].size();

        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_columns; ++j) {
                if (grid[i][j] == '1') {
                    searchForNeighbors(grid, i, j);
                    number_of_islands++;
                }
            }
        }
        return number_of_islands;
    }

    void searchForNeighbors(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        searchForNeighbors(grid, i + 1, j);
        searchForNeighbors(grid, i - 1, j);
        searchForNeighbors(grid, i, j + 1);
        searchForNeighbors(grid, i, j - 1);
    }
};

int main() {
    Solution solution = Solution();

    vector<vector<char>> map{{'1', '1', '0', '0', '0'},
                             {'1', '1', '0', '0', '0'},
                             {'0', '0', '1', '0', '0'},
                             {'0', '0', '0', '1', '1'}};

    std::cout << solution.numIslands(map) << std::endl;

    return 0;
}