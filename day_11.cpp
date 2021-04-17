#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <stack>

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

// BFS-based: collect nodes level-by-level, then process bottom-up.
// For each node compute depth from children; diameter = max(left+right).
// Time: O(n). Space: O(n) for queue + depth map.
class Solution2 {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        std::vector<TreeNode*> order;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            order.push_back(node);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        std::unordered_map<TreeNode*, int> depth;
        int diameter = 0;
        for (int i = static_cast<int>(order.size()) - 1; i >= 0; --i) {
            TreeNode *node = order[i];
            int ld = node->left  ? depth[node->left]  + 1 : 0;
            int rd = node->right ? depth[node->right] + 1 : 0;
            depth[node] = std::max(ld, rd);
            diameter = std::max(diameter, ld + rd);
        }
        return diameter;
    }
};

// Iterative post-order with explicit stack.
// Avoids recursion by manually managing traversal state.
// Time: O(n). Space: O(h) for stack + depth map.
class Solution3 {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        std::stack<TreeNode*> stk;
        std::unordered_map<TreeNode*, int> depth;
        TreeNode *prev = nullptr;
        int diameter = 0;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *curr = stk.top();
            bool goingDown = false;
            if (curr->right && curr->right != prev && curr->left != prev) {
                stk.push(curr->right);
                goingDown = true;
            }
            if (curr->left && curr->left != prev && !goingDown) {
                stk.push(curr->left);
                goingDown = true;
            }
            if (!goingDown) {
                stk.pop();
                int ld = curr->left  ? depth[curr->left]  + 1 : 0;
                int rd = curr->right ? depth[curr->right] + 1 : 0;
                depth[curr] = std::max(ld, rd);
                diameter = std::max(diameter, ld + rd);
                prev = curr;
            }
        }
        return diameter;
    }
};

// Divide and conquer: return pair<depth, diameter>.
// Each call returns both the height and best diameter in the subtree,
// avoiding any side-effect reference parameter.
// Time: O(n). Space: O(h) call-stack.
class Solution4 {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        return solve(root).second;
    }
private:
    std::pair<int,int> solve(TreeNode *node) {
        if (!node) return {0, 0};
        auto l = solve(node->left);
        auto r = solve(node->right);
        int depth = std::max(l.first, r.first) + 1;
        int thru = l.first + r.first;
        int diam = std::max({l.second, r.second, thru});
        return {depth, diam};
    }
};

static TreeNode *buildTree(const map<int, pair<int,int>> &spec) {
    auto *root = new TreeNode(spec.begin()->first);
    for (const auto &elem : spec) {
        auto *target = TreeNode::findNode(root, elem.first);
        if (elem.second.first != 0)
            target->left = new TreeNode(elem.second.first);
        if (elem.second.second != 0)
            target->right = new TreeNode(elem.second.second);
    }
    return root;
}

static void freeTree(TreeNode *node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main() {
    Solution s1;
    Solution2 s2;
    Solution3 s3;
    Solution4 s4;

    vector<map<int, pair<int,int>>> trees = {
        {{1, {2, 3}}, {2, {4, 5}}},
        {{1, {2, 0}}},
        {{1, {2, 3}}, {2, {4, 5}}, {5, {6, 7}}},
        {{1, {0, 0}}},
        {{1, {2, 3}}, {3, {4, 0}}},
    };

    for (const auto &spec : trees) {
        auto *r1 = buildTree(spec);
        auto *r2 = buildTree(spec);
        auto *r3 = buildTree(spec);
        auto *r4 = buildTree(spec);
        int d1 = s1.diameterOfBinaryTree(r1);
        int d2 = s2.diameterOfBinaryTree(r2);
        int d3 = s3.diameterOfBinaryTree(r3);
        int d4 = s4.diameterOfBinaryTree(r4);
        std::cout << "dfs=" << d1 << " bfs=" << d2 << " iter=" << d3 << " pair=" << d4
                  << ((d1 == d2 && d2 == d3 && d3 == d4) ? " OK" : " MISMATCH") << std::endl;
        freeTree(r1);
        freeTree(r2);
        freeTree(r3);
        freeTree(r4);
    }

    return 0;
}

// Complexity comparison:
// Solution  (recursive DFS):          Time O(n), Space O(h) call-stack.
// Solution2 (BFS + bottom-up map):    Time O(n), Space O(n) queue + map.
// Solution3 (iterative post-order):   Time O(n), Space O(h) stack + map.
// Solution4 (pair return):            Time O(n), Space O(h) call-stack.
// All linear; pair-return is pure functional style with no side effects.
