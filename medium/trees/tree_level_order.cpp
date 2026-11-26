// tree_level_order: BFS level-order traversal by levels
// topic: medium/trees — level-order traversal (BFS)
// problem: LeetCode 102. Binary Tree Level Order Traversal
// links:   https://leetcode.com/problems/binary-tree-level-order-traversal/
//          https://leetcode.cn/problems/binary-tree-level-order-traversal/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Binary Tree Level Order Traversal - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/binary-tree-level-order-traversal/solution/

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

// BFS; the current queue size is exactly one tree level.
class Solution {
public:
    vector<vector<int>> solve(TreeNode* root) {
        vector<vector<int>> out;
        if (!root) return out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = (int)q.size();
            vector<int> level;
            for (int i = 0; i < sz; i++) {
                TreeNode* n = q.front();
                q.pop();
                level.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            out.push_back(level);
        }
        return out;
    }
};

int main() {
    // input: n \n n level-order tokens (integer value or "null")
    // output: one line per level, values space-separated
    int n;
    if (!(cin >> n)) return 0;
    vector<string> t(n);
    for (auto& s : t) cin >> s;
    TreeNode* root = buildTree(t);
    Solution sol;
    for (const auto& level : sol.solve(root)) {
        for (size_t j = 0; j < level.size(); j++) {
            if (j) cout << ' ';
            cout << level[j];
        }
        cout << "\n";
    }
    return 0;
}
