#include <vector>
#include <iostream>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    void eraseChars(string &str) {
        int i = 0, j;
        while (i < str.size()) {
            j = 0;
            while (str[i] == '#') {
                str.erase(i, 1);
                j++;
            }
            if (j > 0) {
                if (i > j) {
                    str.erase(i - j, j);
                    i = i - j;
                } else {
                    str.erase(0, i);
                    i = 1;
                }
                continue;
            }
            i++;
        }
    }

    bool backspaceCompare(string S, string T) {
        eraseChars(S);
        eraseChars(T);
        return S == T;
    }
};

// Stack-based: simulate typing into a buffer.
// Push chars, pop on '#'. Compare final buffers.
// Time: O(m + n). Space: O(m + n).
class Solution2 {
public:
    bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }
private:
    string build(const string &s) {
        string result;
        for (char c : s) {
            if (c == '#') {
                if (!result.empty()) result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};

// Reverse two-pointer: walk both strings from the end,
// counting '#' skips. Compare surviving characters in-place.
// Time: O(m + n). Space: O(1).
class Solution3 {
public:
    bool backspaceCompare(string S, string T) {
        int i = static_cast<int>(S.size()) - 1;
        int j = static_cast<int>(T.size()) - 1;
        while (i >= 0 || j >= 0) {
            int skipS = 0;
            while (i >= 0 && (S[i] == '#' || skipS > 0)) {
                if (S[i] == '#') { ++skipS; --i; }
                else { --skipS; --i; }
            }
            int skipT = 0;
            while (j >= 0 && (T[j] == '#' || skipT > 0)) {
                if (T[j] == '#') { ++skipT; --j; }
                else { --skipT; --j; }
            }
            if (i >= 0 && j >= 0 && S[i] != T[j]) return false;
            if ((i >= 0) != (j >= 0)) return false;
            --i;
            --j;
        }
        return true;
    }
};

int main() {
    Solution s1;
    Solution2 s2;
    Solution3 s3;

    struct Case { string a, b; bool expected; };
    vector<Case> cases = {
        {"ab#c",    "ad#c",    true},
        {"ab##",    "c#d#",    true},
        {"a##c",    "#a#c",    true},
        {"a#c",     "b",       false},
        {"",        "",        true},
        {"#a#",     "#a#",     true},
        {"a##########c", "#a#c", true},
        {"c#d#",    "ab##",    true},
        {"xy#z#",   "x",       true},
        {"xy#z#",   "xy##z",   false},
        {"abc##",   "adc##",   true},
        {"a##b",    "#b",      true},
    };

    bool allOk = true;
    for (const auto &tc : cases) {
        string a1 = tc.a, b1 = tc.b;
        string a2 = tc.a, b2 = tc.b;
        string a3 = tc.a, b3 = tc.b;
        bool r1 = s1.backspaceCompare(a1, b1);
        bool r2 = s2.backspaceCompare(a2, b2);
        bool r3 = s3.backspaceCompare(a3, b3);
        bool ok = (r1 == r2) && (r2 == r3) && (r3 == tc.expected);
        if (!ok) allOk = false;
        std::cout << "\"" << tc.a << "\" vs \"" << tc.b << "\": "
                  << "erase=" << r1 << " stack=" << r2 << " ptr=" << r3
                  << " expected=" << tc.expected
                  << (ok ? " OK" : " FAIL") << std::endl;
    }
    std::cout << (allOk ? "ALL PASSED" : "SOME FAILED") << std::endl;

    return 0;
}

// Complexity comparison:
// Solution  (in-place erase):      Time O(n^2) worst case, Space O(1).
// Solution2 (stack buffer):        Time O(n),               Space O(n).
// Solution3 (reverse two-pointer): Time O(n),               Space O(1).
// Reverse-pointer gives linear time with constant extra space.
