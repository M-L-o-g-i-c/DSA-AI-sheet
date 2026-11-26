// tree_lca: recursive lowest common ancestor
// topic: medium/trees — lowest common ancestor (recursive)
// problem: LeetCode 236. Lowest Common Ancestor of a Binary Tree
// links:   https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
//          https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Lowest Common Ancestor of a Binary Tree - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/

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

// plumbing: locate a node by value (values unique; p and q exist in the tree)
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    return left ? left : findNode(root->right, val);
}

// If p and q sit in different subtrees of root, root is the LCA;
// otherwise the LCA is in the subtree that contains both.
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* L = solve(root->left, p, q);
        TreeNode* R = solve(root->right, p, q);
        if (L && R) return root;
        return L ? L : R;
    }
};

int main() {
    // input: n \n n level-order tokens (integer value or "null") \n p q
    int n;
    if (!(cin >> n)) return 0;
    vector<string> t(n);
    for (auto& s : t) cin >> s;
    int pv, qv;
    if (!(cin >> pv >> qv)) return 0;
    TreeNode* root = buildTree(t);
    Solution sol;
    TreeNode* lca = sol.solve(root, findNode(root, pv), findNode(root, qv));
    cout << lca->val << "\n";
    return 0;
}
