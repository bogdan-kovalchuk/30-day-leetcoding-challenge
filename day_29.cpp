#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>

using std::vector;
using std::unordered_map;
using std::string;
using std::list;
using std::cout;
using std::endl;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        if (root != NULL) {
            findLongestPath(root, maxSum);
        }
        return maxSum;
    }

    int findLongestPath(TreeNode *node, int &sum) {
        int leftPathSum = 0, rightPathSum = 0;
        if (node->left != NULL) {
            leftPathSum = findLongestPath(node->left, sum);
        }
        if (node->right != NULL) {
            rightPathSum = findLongestPath(node->right, sum);
        }

        int sumLeftRight = node->val + leftPathSum + rightPathSum;
        int sumMaxLeftRight = node->val + std::max(leftPathSum, rightPathSum);
        int maxSum = std::max(node->val, std::max(sumLeftRight, sumMaxLeftRight));

        if (maxSum > sum) sum = maxSum;

        return std::max(node->val, sumMaxLeftRight);
    }
};

int main() {
    Solution solution = Solution();
    auto *node = new TreeNode();
    node->val = 5;
    node->left = new TreeNode(4);
    node->left->left = new TreeNode(11);
    node->left->left->left = new TreeNode(7);
    node->left->left->right = new TreeNode(2);
    node->right = new TreeNode(8);
    node->right->left = new TreeNode(13);
    node->right->right = new TreeNode(4);
    node->right->right->right = new TreeNode(1);

    cout << solution.maxPathSum(node) << endl;

    return 0;
}