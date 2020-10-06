#include <vector>
#include <iostream>
#include <numeric>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

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

class SolutionCountKey {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        std::unordered_map<string, vector<string>> grouped;
        for (const auto &str : strs) {
            string key(26, '0');
            for (char c : str) key[c - 'a']++;
            grouped[key].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto &item : grouped) result.push_back(item.second);
        return result;
    }
};

int main() {
    vector<string> array_of_strings = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution solution;
    SolutionCountKey solutionCount;
    auto r1 = solution.groupAnagrams(array_of_strings);
    auto r2 = solutionCount.groupAnagrams(array_of_strings);

    std::cout << "SortKey groups: " << r1.size() << " CountKey groups: " << r2.size() << std::endl;

    return 0;
}