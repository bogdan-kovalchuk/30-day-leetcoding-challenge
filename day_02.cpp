#include <vector>
#include <iostream>
#include <cmath>

using std::vector;

class Solution {
public:
    bool isHappy(int n) {
        bool output = false;
        int end_number = n;
        do {
            int num = end_number;
            end_number = 0;
            while (num > 0) {
                end_number += int(pow(num % 10, 2));
                num /= 10;
            }
        } while (int(log10(end_number) + 1) > 1);

        if (end_number == 1) {
            output = true;
        }

        return output;
    }
};

int main() {
    Solution solution = Solution();
    int num = 19;

    int out = solution.isHappy(num);

    std::cout << out << std::endl;

    return 0;
}