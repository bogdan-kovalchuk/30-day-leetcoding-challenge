#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_set>

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

        if (end_number == 1 || end_number == 7) {
            output = true;
        }

        return output;
    }
};

class SolutionFloyd {
public:
    int digitSquareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
        } while (slow != fast);
        return slow == 1;
    }
};

class SolutionSet {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            int sum = 0;
            while (n > 0) {
                int d = n % 10;
                sum += d * d;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};

class SolutionPrecomputed {
public:
    bool isHappy(int n) {
        const std::unordered_set<int> cycle = {4, 16, 37, 58, 89, 145, 42, 20};
        while (n != 1 && cycle.find(n) == cycle.end()) {
            int sum = 0;
            while (n > 0) {
                int d = n % 10;
                sum += d * d;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};

int main() {
    Solution solution = Solution();
    SolutionFloyd solutionFloyd = SolutionFloyd();
    SolutionSet solutionSet = SolutionSet();
    SolutionPrecomputed solutionPrecomp = SolutionPrecomputed();
    int num = 1111111;

    int out = solution.isHappy(num);
    int outFloyd = solutionFloyd.isHappy(num);
    int outSet = solutionSet.isHappy(num);
    int outPrecomp = solutionPrecomp.isHappy(num);

    std::cout << "Original: " << out << " Floyd: " << outFloyd
              << " Set: " << outSet << " Precomp: " << outPrecomp << std::endl;

    return 0;
}