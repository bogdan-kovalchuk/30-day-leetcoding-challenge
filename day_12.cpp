#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>

using std::vector;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        while (stones.size() > 1) {
            std::sort(stones.begin(), stones.end(), std::greater<int>());
            if (stones[0] > stones[1]) {
                stones[0] -= stones[1];
                stones.erase(stones.begin() + 1);

            } else if (stones[0] < stones[1]) {
                stones[1] -= stones[0];
                stones.erase(stones.begin());
            } else {
                stones.erase(stones.begin(), stones.begin() + 2);
            }
        }
        if (stones.size() == 1) {
            return stones[0];
        } else {
            return 0;
        }
    }
};

// Max-heap: push all stones into priority_queue, pop two heaviest,
// smash them, push remainder if nonzero. Repeat until 0 or 1 left.
// Time: O(n log n). Space: O(n).
class Solution2 {
public:
    int lastStoneWeight(vector<int> &stones) {
        std::priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if (a != b) pq.push(a - b);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

// Multiset: keeps stones sorted. Extract two largest via rbegin,
// erase them, insert difference if nonzero.
// Time: O(n log n). Space: O(n).
class Solution3 {
public:
    int lastStoneWeight(vector<int> &stones) {
        std::multiset<int> ms(stones.begin(), stones.end());
        while (ms.size() > 1) {
            auto it = ms.rbegin();
            int a = *it; ms.erase(std::next(it).base());
            int b = *ms.rbegin(); ms.erase(std::next(ms.rbegin()).base());
            if (a != b) ms.insert(a - b);
        }
        return ms.empty() ? 0 : *ms.begin();
    }
};

// Counting sort / bucket: count occurrences of each weight (1..1000).
// Scan from max weight down to find two heaviest, smash, update counts.
// Time: O(W + n) where W = max weight. Space: O(W).
class Solution4 {
public:
    int lastStoneWeight(vector<int> &stones) {
        int count[1001] = {0};
        int maxW = 0;
        for (int s : stones) {
            count[s]++;
            if (s > maxW) maxW = s;
        }
        int remaining = static_cast<int>(stones.size());
        while (remaining > 1) {
            int a = 0, b = 0;
            for (int w = maxW; w >= 1 && (a == 0 || b == 0); --w) {
                while (count[w] > 0 && (a == 0 || b == 0)) {
                    if (a == 0) a = w;
                    else b = w;
                    count[w]--;
                    remaining--;
                }
            }
            if (a != b) {
                int diff = a - b;
                count[diff]++;
                remaining++;
                if (diff > maxW) maxW = diff;
            }
        }
        for (int w = maxW; w >= 1; --w) {
            if (count[w] > 0) return w;
        }
        return 0;
    }
};

int main() {
    Solution s1;
    Solution2 s2;
    Solution3 s3;
    Solution4 s4;

    vector<vector<int>> cases = {
        {2, 7, 4, 1, 8, 1},
        {1},
        {2, 2},
        {1, 3},
        {10, 4, 2, 10},
        {1, 1, 1, 1},
        {5, 5, 5, 5},
        {3, 7, 2, 9},
    };

    for (const auto &nums : cases) {
        auto v1 = nums, v2 = nums, v3 = nums, v4 = nums;
        int r1 = s1.lastStoneWeight(v1);
        int r2 = s2.lastStoneWeight(v2);
        int r3 = s3.lastStoneWeight(v3);
        int r4 = s4.lastStoneWeight(v4);
        std::cout << "sort=" << r1 << " heap=" << r2 << " mset=" << r3 << " bucket=" << r4
                  << ((r1 == r2 && r2 == r3 && r3 == r4) ? " OK" : " MISMATCH") << std::endl;
    }

    return 0;
}

// Complexity comparison:
// Solution  (sort + erase):   Time O(n^2 log n) worst, Space O(1) extra.
// Solution2 (priority_queue): Time O(n log n),         Space O(n).
// Solution3 (multiset):       Time O(n log n),         Space O(n).
// Solution4 (counting):       Time O(W + n),           Space O(W).
// Counting is fastest when weight range W is small relative to n.
