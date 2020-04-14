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

int main() {
    Solution solution = Solution();

//    string s = "abc";
//    vector<vector<int>> shift = {{0,1},{1,2}};
//    vector<vector<int>> shift = {{1, 1},
//                                 {1, 1},
//                                 {0, 2},
//                                 {1, 3}};

    string s = "wpdhhcj";
    vector<vector<int>> shift = {{0,7},{1,7},{1,0},{1,3},{0,3},{0,6},{1,2}};

    string str = solution.stringShift(s, shift);

    std::cout << str << std::endl;

    return 0;
}