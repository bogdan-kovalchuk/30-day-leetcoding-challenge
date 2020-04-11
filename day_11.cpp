#include <iostream>
#include <vector>
#include <map>
#include <utility>

using std::vector;
using std::map;
using std::pair;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    static TreeNode *findNode(TreeNode *node, int val) {
        TreeNode *result = NULL;
        if (node->val == val) {
            result = node;
        }
        if (node->left != NULL) {
            auto *nodeLeft = findNode(node->left, val);
            if (nodeLeft != NULL) {
                result = nodeLeft;
            }
        }
        if (node->right != NULL) {
            auto *nodeRight = findNode(node->right, val);
            if (nodeRight != NULL) {
                result = nodeRight;
            }
        }
        return result;
    }
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        if (root != NULL){
            findLongestPath(root, diameter);
        }
        return diameter;
    }

    int findLongestPath(TreeNode *node, int &diameter) {
        int leftPath = 0, rightPath = 0;
        if (node->left != NULL) {
            leftPath = findLongestPath(node->left, diameter);
        }
        if (node->right != NULL) {
            rightPath = findLongestPath(node->right, diameter);
        }
        if (leftPath + rightPath > diameter){
            diameter = leftPath + rightPath;
        }
        return ++(leftPath > rightPath ? leftPath: rightPath);
    }
};

int main() {
    Solution solution = Solution();
    map<int, pair<int, int>> tree = {{1, {2, 3}},
                                     {2, {4, 5}},
                                     {5, {6, 7}},};

    auto *root = new TreeNode(tree.begin()->first);
    for (const auto &elem: tree) {
        auto *target_root = TreeNode::findNode(root, elem.first);
        if (elem.second.first != 0) {
            target_root->left = new TreeNode(elem.second.first);
        }
        if (elem.second.second != 0) {
            target_root->right = new TreeNode(elem.second.second);
        }
    }

    int diameter = solution.diameterOfBinaryTree(root);

    std::cout << diameter << std::endl;

    return 0;
}