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

int main() {
    Solution solution = Solution();
//    string S = "a##########c";
//    string T = "#a#c";

    string S = "c#d#";
    string T = "ab##";
//
//    string S = "#a#c";
//    string T = "a##c";

//    string S = "e##e#fq##o##oyof##q" ;
//    string T = "e##e#o##oyof##q";
//
//    string S = "mdamdluynq###########m#epymatjzksasf#";
//    string T = "mc#di#amdluynqq############m#epf#ymaw#tt#jzksasf#";

    string p = "oyq";

    std::cout << solution.backspaceCompare(S, T) << std::endl;

    return 0;
}