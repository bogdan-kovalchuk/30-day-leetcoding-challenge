#include <vector>
#include <iostream>
#include <numeric>
#include <limits>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int i = 0;
        int j = 0;
        int profit = 0;
        int size = prices.size();

        if (size > 0) {
            while (i < size - 1) {
                if (prices[i] < prices[i + 1]) {
                    j = i;
                    while (j < size - 1 && prices[j] < prices[j + 1]) {
                        ++j;
                    }
                    profit += prices[j] - prices[i];
                    i = j - 1;
                }
                ++i;
            }
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {1, 2, 3, 4, 5};

    Solution solution = Solution();
    int maxProfit = solution.maxProfit(prices);

    std::cout << maxProfit << std::endl;

    return 0;
}