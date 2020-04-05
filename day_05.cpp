#include <vector>
#include <iostream>
#include <numeric>
#include <limits>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {

    }
};

int main() {
    vector<int> price = {7, 1, 5, 3, 6, 4};

    Solution solution = Solution();
    int maxProfit = solution.maxProfit(price);

    std::cout << maxProfit << std::endl;

    return 0;
}