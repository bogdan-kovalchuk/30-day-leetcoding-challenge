#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        u_int step = 1;
        while (m != n) {
            m /= 2;
            n /= 2;
            step *= 2;
        }
        return step * m;
    }
};

int main() {
    Solution solution = Solution();

    int m = 5, n = 7;

    std::cout << solution.rangeBitwiseAnd(m, n) << std::endl;

    return 0;
}