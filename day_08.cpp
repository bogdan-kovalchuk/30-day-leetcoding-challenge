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

int main() {
    Solution solution = Solution();
//    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    auto *head = new ListNode(nums[0]);
    auto *next = head;
    for (int i = 1; i < nums.size(); ++i) {
        next->next = new ListNode(nums[i]);
        next = next->next;
    }

    ListNode *middle_node = solution.middleNode(head);

    std::cout << middle_node->val << std::endl;

    return 0;
}