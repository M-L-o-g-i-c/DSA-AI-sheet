// tree_basic: TreeNode struct, level-order build and print
// topic: medium/trees — tree build/print (level-order)
// problem: demo — build a binary tree from level-order tokens and print it back
// links:   (demo, no external problem)
// reference: none (original demo)

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

class Solution {
public:
    // serialize back to level-order tokens, trailing "null"s trimmed
    vector<string> solve(TreeNode* root) {
        vector<string> out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            if (!n) {
                out.push_back("null");
                continue;
            }
            out.push_back(to_string(n->val));
            q.push(n->left);
            q.push(n->right);
        }
        while (!out.empty() && out.back() == "null") out.pop_back();
        return out;
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
    vector<string> out = sol.solve(root);
    for (size_t i = 0; i < out.size(); i++) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << "\n";
    return 0;
}
