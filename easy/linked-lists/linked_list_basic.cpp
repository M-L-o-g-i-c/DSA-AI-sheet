// linked_list_basic: ListNode struct, build a list from input, print it
// topic: easy/linked-lists — linked list basics (build, traverse)
// problem: demo — build a singly linked list from values and traverse it
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // traverse once and collect node values in order.
    vector<int> solve(ListNode* head) {
        vector<int> vals;
        for (ListNode* p = head; p != nullptr; p = p->next)
            vals.push_back(p->val);
        return vals;
    }
};

int main() {
    // input: n \n v[0] ... v[n-1]   (n >= 0; n = 0 means empty list)
    int n;
    if (!(cin >> n)) return 0;
    ListNode dummy; // build helper tail, not part of the list
    ListNode* tail = &dummy;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    Solution sol;
    vector<int> vals = sol.solve(dummy.next);
    // output: the node values, space separated
    for (int i = 0; i < (int)vals.size(); i++) {
        if (i) cout << " ";
        cout << vals[i];
    }
    cout << "\n";
    return 0;
}
