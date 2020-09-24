#include <vector>
#include <iostream>
#include <numeric>
#include <limits>
#include <algorithm>
#include <string>

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

    auto runAll = [&](vector<int> v, const std::string &label) {
        vector<int> c1(v), c2(v);
        int r1 = solution.maxProfit(v);
        int r2 = solutionOnePass.maxProfit(c1);
        int r3 = solutionSM.maxProfit(c2);
        bool ok = (r1 == r2) && (r2 == r3);
        std::cout << label << ": VP=" << r1 << " OnePass=" << r2 << " SM=" << r3
                  << (ok ? " OK" : " MISMATCH") << std::endl;
    };

    runAll({1, 2, 3, 4, 5}, "ascending");
    runAll({5, 4, 3, 2, 1}, "descending");
    runAll({7, 1, 5, 3, 6, 4}, "general");
    runAll({}, "empty");
    runAll({3}, "single");
    runAll({1, 1, 1}, "flat");

    std::cout << "\nComplexity comparison:" << std::endl;
    std::cout << "ValleyPeak:   O(n) time, O(1) space" << std::endl;
    std::cout << "OnePass:      O(n) time, O(1) space, simpler logic" << std::endl;
    std::cout << "StateMachine: O(n) time, O(1) space, extensible to k transactions" << std::endl;

    return 0;
}