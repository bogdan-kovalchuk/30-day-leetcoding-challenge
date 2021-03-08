#include <vector>
#include <iostream>
#include <numeric>

using std::vector;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *ptr = head;
        int i = 0;
        int j = 0;
        while (ptr != nullptr) {
            ptr = ptr->next;
            i++;
        }
        ListNode *out = head;
        while (j != i / 2) {
            out = out->next;
            j++;
        }
        return out;
    }
};

// Two-pointer (tortoise and hare): slow advances one step,
// fast advances two. When fast reaches the end, slow is at the middle.
// Time: O(n) single pass. Space: O(1).
class Solution2 {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

static ListNode *buildList(const vector<int> &nums) {
    if (nums.empty()) return nullptr;
    auto *head = new ListNode(nums[0]);
    auto *cur = head;
    for (std::size_t i = 1; i < nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

static void freeList(ListNode *head) {
    while (head) {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution s1;
    Solution2 s2;

    vector<vector<int>> cases = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6},
        {1},
        {1, 2},
        {1, 2, 3},
    };

    for (const auto &nums : cases) {
        auto *h1 = buildList(nums);
        auto *h2 = buildList(nums);
        int v1 = s1.middleNode(h1)->val;
        int v2 = s2.middleNode(h2)->val;
        std::cout << "len=" << nums.size()
                  << " two-pass=" << v1
                  << " slow-fast=" << v2
                  << (v1 == v2 ? " OK" : " MISMATCH") << std::endl;
        freeList(h1);
        freeList(h2);
    }

    return 0;
}

// Complexity comparison:
// Solution  (two-pass):     Time O(n) + O(n) = O(n), two traversals. Space O(1).
// Solution2 (slow/fast):    Time O(n), single traversal.    Space O(1).
// Both are O(n) time / O(1) space; slow/fast does half the pointer moves.
