// tree_validate_bst: range-bounds validation of a BST
// topic: medium/trees — validate BST (min/max bounds)
// problem: LeetCode 98. Validate Binary Search Tree
// links:   https://leetcode.com/problems/validate-binary-search-tree/
//          https://leetcode.cn/problems/validate-binary-search-tree/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Validate Binary Search Tree - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/validate-binary-search-tree/solution/

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

// Every node must lie strictly inside the (lo, hi) range inherited from
// its ancestors; 64-bit bounds handle INT_MIN/INT_MAX values.
class Solution {
public:
    bool solve(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool valid(TreeNode* n, long long lo, long long hi) {
        if (!n) return true;
        if (n->val <= lo || n->val >= hi) return false;
        return valid(n->left, lo, n->val) && valid(n->right, n->val, hi);
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
    cout << (sol.solve(root) ? "true" : "false") << "\n";
    return 0;
}
