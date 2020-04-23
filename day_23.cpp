#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int out = m;
        for (int i = m; i <= n; i++) {
            out = out & i;
        }
        return out;
    }
};

int main() {
    Solution solution = Solution();

    int m = 5, n = 7;

    std::cout << solution.rangeBitwiseAnd(m, n) << std::endl;

    return 0;
}