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
        int index = 0;

        return createNode(preorder, index, INT_MIN, INT_MAX);
    }

    TreeNode *createNode(vector<int> &preorder, int &index, int min, int max){
        if (index == preorder.size()) return nullptr;

        int number = preorder[index];
        if(number < min || number > max) return nullptr;

        auto *root = new TreeNode(number);
        index++;

        root->left = createNode(preorder, index, min, number - 1);
        root->right = createNode(preorder, index, number + 1, max);

        return root;
    }
};

int main() {
    Solution solution = Solution();

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode *root = solution.bstFromPreorder(preorder);

    return 0;
}