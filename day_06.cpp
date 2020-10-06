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
    Solution solution;
    SolutionCountKey solutionCount;

    auto runAll = [&](vector<string> v, const std::string &label) {
        vector<string> c(v);
        auto r1 = solution.groupAnagrams(v);
        auto r2 = solutionCount.groupAnagrams(c);
        bool ok = (r1.size() == r2.size());
        std::cout << label << ": SortKey=" << r1.size() << " CountKey=" << r2.size()
                  << (ok ? " OK" : " MISMATCH") << std::endl;
    };

    runAll({"eat", "tea", "tan", "ate", "nat", "bat"}, "general");
    runAll({""}, "single empty");
    runAll({"a"}, "single char");
    runAll({"", ""}, "two empties");
    runAll({"abc", "bca", "cab", "xyz"}, "with non-anagram");

    std::cout << "\nComplexity comparison:" << std::endl;
    std::cout << "SortKey:  O(n * k log k) time, O(nk) space" << std::endl;
    std::cout << "CountKey: O(n * k) time, O(nk) space, k = max string length" << std::endl;

    return 0;
}