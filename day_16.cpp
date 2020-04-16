#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
    bool checkValidString(const string &s) {
        if (s.empty()) return true;

        vector<int> left_par, star;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                left_par.emplace_back(i);
            } else if (s[i] == '*') {
                star.emplace_back(i);
            } else {
                if (!left_par.empty()) {
                    left_par.pop_back();
                } else if (!star.empty()) {
                    star.pop_back();
                } else {
                    return false;
                }
            }
        }

        while (!left_par.empty()) {
            if (star.empty()) return false;
            if (left_par.back() < star.back()) {
                left_par.pop_back();
                star.pop_back();
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution = Solution();
    string str = "(((()*()()()))()((()()(*()())))))))))))))))))))))(((*)()";

    std::cout << solution.checkValidString(str) << std::endl;

    return 0;
}