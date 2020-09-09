#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_set>
#include <string>

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
    Solution solution;
    SolutionFloyd solutionFloyd;
    SolutionSet solutionSet;
    SolutionPrecomputed solutionPrecomp;

    auto runAll = [&](int n, const std::string &label) {
        bool r1 = solution.isHappy(n);
        bool r2 = solutionFloyd.isHappy(n);
        bool r3 = solutionSet.isHappy(n);
        bool r4 = solutionPrecomp.isHappy(n);
        bool ok = (r1 == r2) && (r2 == r3) && (r3 == r4);
        std::cout << label << ": Orig=" << r1 << " Floyd=" << r2
                  << " Set=" << r3 << " Precomp=" << r4
                  << (ok ? " OK" : " MISMATCH") << std::endl;
    };

    runAll(1, "n=1");
    runAll(7, "n=7");
    runAll(19, "n=19");
    runAll(2, "n=2 (unhappy)");
    runAll(1111111, "n=1111111");

    std::cout << "\nComplexity comparison:" << std::endl;
    std::cout << "Original:  O(log n) per step, no explicit cycle tracking" << std::endl;
    std::cout << "Floyd:     O(log n) per step, O(1) space" << std::endl;
    std::cout << "Set:       O(log n) per step, O(log n) space for visited set" << std::endl;
    std::cout << "Precomp:   O(log n) per step, O(1) space, early exit on known cycle" << std::endl;

    return 0;
}