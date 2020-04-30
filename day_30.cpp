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
    bool isValidSequence(TreeNode *root, vector<int> &arr) {
        int i = 0, out = 0;
        if (root != NULL) {
            out = checkValid(root, arr, i);
        }
        return out;
    }
    bool checkValid(TreeNode *node, vector<int> &arr, int i) {
        bool left = false, right = false;
        if (i < arr.size() - 1 && node->val == arr[i]){
            ++i;
            if (node->left != nullptr) left = checkValid(node->left, arr, i);
            if (node->right != nullptr) right = checkValid(node->right, arr, i);
        }

        if (left || right) return true;

        return i == arr.size() - 1 && node->val == arr[i] && node->left == nullptr && node->right == nullptr;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> arr = {0, 1, 0, 1};

    auto *node = new TreeNode();
    node->val = 0;
    node->left = new TreeNode(1);
    node->left->left = new TreeNode(0);
    node->left->left->left = new TreeNode(1);
    node->left->right = new TreeNode(1);
    node->left->right->left = new TreeNode(0);
    node->left->right->right = new TreeNode(0);
    node->right = new TreeNode(0);
    node->right->right = new TreeNode(0);

    cout << solution.isValidSequence(node, arr) << endl;

    return 0;
}