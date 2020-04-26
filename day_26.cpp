#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int longestCommonSubsequence(const string &text1, const string &text2) {
        int len1 = text1.size();
        int len2 = text2.size();

        vector<vector<int>> store(len1 + 1, vector<int>(len2 + 1));

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (text1[i] == text2[j]) {
                    store[i + 1][j + 1] = store[i][j] + 1;
                } else {
                    store[i + 1][j + 1] = std::max(store[i][j + 1], store[i + 1][j]);
                }
            }
        }

        return store[len1][len2];
    }
};

int main() {
    Solution solution = Solution();

    string text1 = "abc", text2 = "def";

    std::cout << solution.longestCommonSubsequence(text1, text2) << std::endl;

    return 0;
}