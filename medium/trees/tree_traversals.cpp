// tree_traversals: pre/in/post-order traversals, recursive and iterative
// topic: medium/trees — pre/in/post-order (recursive + iterative)
// problem: LeetCode 94. Binary Tree Inorder Traversal
// links:   https://leetcode.com/problems/binary-tree-inorder-traversal/
//          https://leetcode.cn/problems/binary-tree-inorder-traversal/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Binary Tree Inorder Traversal - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/binary-tree-inorder-traversal/solution/

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

// All three orders in both styles. solve = iterative inorder (LC 94 follow-up).
class Solution {
public:
    // inorder: left, node, right — walk left spine, then visit, then go right
    vector<int> solve(TreeNode* root) {
        vector<int> out;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            out.push_back(cur->val);
            cur = cur->right;
        }
        return out;
    }

    vector<int> preorderRecursive(TreeNode* root) {
        vector<int> out;
        preorderRec(root, out);
        return out;
    }

    vector<int> inorderRecursive(TreeNode* root) {
        vector<int> out;
        inorderRec(root, out);
        return out;
    }

    vector<int> postorderRecursive(TreeNode* root) {
        vector<int> out;
        postorderRec(root, out);
        return out;
    }

    // preorder: node, left, right — push right before left
    vector<int> preorderIterative(TreeNode* root) {
        vector<int> out;
        if (!root) return out;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* n = st.top();
            st.pop();
            out.push_back(n->val);
            if (n->right) st.push(n->right);
            if (n->left) st.push(n->left);
        }
        return out;
    }

    // postorder: left, right, node — root-right-left order reversed
    vector<int> postorderIterative(TreeNode* root) {
        vector<int> out;
        if (!root) return out;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* n = st.top();
            st.pop();
            out.push_back(n->val);
            if (n->left) st.push(n->left);
            if (n->right) st.push(n->right);
        }
        reverse(out.begin(), out.end());
        return out;
    }

private:
    void preorderRec(TreeNode* n, vector<int>& out) {
        if (!n) return;
        out.push_back(n->val);
        preorderRec(n->left, out);
        preorderRec(n->right, out);
    }

    void inorderRec(TreeNode* n, vector<int>& out) {
        if (!n) return;
        inorderRec(n->left, out);
        out.push_back(n->val);
        inorderRec(n->right, out);
    }

    void postorderRec(TreeNode* n, vector<int>& out) {
        if (!n) return;
        postorderRec(n->left, out);
        postorderRec(n->right, out);
        out.push_back(n->val);
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
    vector<int> out = sol.solve(root);
    for (size_t i = 0; i < out.size(); i++) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << "\n";
    return 0;
}
