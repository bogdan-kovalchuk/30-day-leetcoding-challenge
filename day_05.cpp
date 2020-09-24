#include <vector>
#include <iostream>
#include <numeric>
#include <limits>
#include <algorithm>

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

class SolutionOnePass {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};

class SolutionStateMachine {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int hold = -prices[0];
        int cash = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            int prevCash = cash;
            cash = std::max(cash, hold + prices[i]);
            hold = std::max(hold, prevCash - prices[i]);
        }
        return cash;
    }
};

int main() {
    Solution solution;
    SolutionOnePass solutionOnePass;
    SolutionStateMachine solutionSM;
    vector<int> prices = {1, 2, 3, 4, 5};

    int r1 = solution.maxProfit(prices);
    vector<int> c(prices.begin(), prices.end());
    int r2 = solutionOnePass.maxProfit(c);
    vector<int> c2(prices.begin(), prices.end());
    int r3 = solutionSM.maxProfit(c2);

    std::cout << "ValleyPeak: " << r1 << " OnePass: " << r2 << " StateMachine: " << r3 << std::endl;

    return 0;
}