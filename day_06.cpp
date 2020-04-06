#include <vector>
#include <iostream>
#include <numeric>
#include <map>

using std::vector;
using std::string;
using std::map;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> groupedAnagrams;
        map<string, vector<string>> grouped;
        for(const auto& str: strs){
            auto s = str;
            sort(s.begin(), s.end());
            grouped[s].push_back(str);
        }
        for (const auto& item : grouped){
            groupedAnagrams.push_back(item.second);
        }
        return groupedAnagrams;
    }
};

int main() {
    vector<string> array_of_strings = {"eat", "tea", "tan", "ate", "nat", "bat"};


    Solution solution = Solution();
    vector<vector<string>> maxProfit = solution.groupAnagrams(array_of_strings);

    return 0;
}