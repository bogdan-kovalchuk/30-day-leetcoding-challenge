#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    string stringShift(string s, vector<vector<int>> &shift) {
        int shift_count[2] = {0, 0};
        for (auto item : shift) {
            shift_count[item[0]] += item[1];
        }
        int direction = shift_count[0] > shift_count[1] ? 0 : 1;
        int amount = (std::abs(shift_count[0] - shift_count[1])) % shift.size();

        if (direction == 0) {
            while (amount > 0){
                s.push_back(s[0]);
                s.erase(s.begin());
                amount--;
            }
        }else{
            while (amount > 0){
                s.insert(s.begin(), s.back());
                s.pop_back();
                amount--;
            }
        }
        return s;
    }
};

class SolutionSubstr {
public:
    string stringShift(string s, vector<vector<int>> &shift) {
        int net = 0;
        for (const auto &op : shift) {
            net += (op[0] == 0) ? -op[1] : op[1];
        }
        int n = s.size();
        net = ((net % n) + n) % n;
        return s.substr(n - net) + s.substr(0, n - net);
    }
};

int main() {
    Solution orig;
    SolutionSubstr substr;

    auto run = [&](string s, vector<vector<int>> shift, const char *label) {
        string r1 = orig.stringShift(s, shift);
        string r2 = substr.stringShift(s, shift);
        std::cout << label << ": orig=" << r1 << " substr=" << r2
                  << (r1 == r2 ? " [match]" : " [MISMATCH]") << std::endl;
    };

    run("wpdhhcj", {{0,7},{1,7},{1,0},{1,3},{0,3},{0,6},{1,2}}, "basic");
    run("abc", {{0,1},{1,2}}, "simple");
    run("abcdef", {{0,2},{1,1},{0,1},{1,0},{0,0},{1,2}}, "mixed");
    run("abcdef", {{0,6}}, "full_rotation");
    run("abcdef", {{0,0},{1,0}}, "zero_shift");
    run("a", {{0,5},{1,3}}, "single_char");
    run("test", {{0,1},{0,1},{0,1},{0,1}}, "multiple_left");
    run("abcd", {{1,1},{1,1},{1,1},{1,1}}, "full_right");

    return 0;
}