// tree_max_depth: recursive maximum depth
// topic: medium/trees — maximum depth (recursive)
// problem: LeetCode 104. Maximum Depth of Binary Tree
// links:   https://leetcode.com/problems/maximum-depth-of-binary-tree/
//          https://leetcode.cn/problems/maximum-depth-of-binary-tree/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Maximum Depth of Binary Tree - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/solution/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// build tree from level-order tokens ("null" marks a missing child)
TreeNode* buildTree(const vector<string>& t) {
    if (t.empty() || t[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(t[0]));
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < t.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (i < t.size()) {
            if (t[i] != "null") {
                node->left = new TreeNode(stoi(t[i]));
                q.push(node->left);
            }
            i++;
        }
        if (i < t.size()) {
            if (t[i] != "null") {
                node->right = new TreeNode(stoi(t[i]));
                q.push(node->right);
            }
            i++;
        }
    }
    return root;
}

// depth = 1 + max(depth of children); empty tree has depth 0
class Solution {
public:
    int solve(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(solve(root->left), solve(root->right));
    }
};

int main() {
    // input: n \n n level-order tokens (integer value or "null")
    int n;
    if (!(cin >> n)) return 0;
    vector<string> t(n);
    for (auto& s : t) cin >> s;
    TreeNode* root = buildTree(t);
    Solution sol;
    cout << sol.solve(root) << "\n";
    return 0;
}
