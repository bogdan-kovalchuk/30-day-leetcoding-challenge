#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {

    }
};

int main() {
    Solution solution = Solution();

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode *node = solution.bstFromPreorder(preorder);

    return 0;
}