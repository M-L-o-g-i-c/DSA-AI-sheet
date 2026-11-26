// linked_list_cycle: detect a cycle with Floyd's tortoise and hare
// topic: easy/linked-lists — Floyd's cycle detection
// problem: LeetCode 141. Linked List Cycle
// links:   https://leetcode.com/problems/linked-list-cycle/
//          https://leetcode.cn/problems/linked-list-cycle/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 141. Linked List Cycle - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/linked-list-cycle/solution/

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
    // if a cycle exists, slow and fast meet inside it.
    bool solve(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    // input: n pos \n v[0] ... v[n-1]
    // pos = index of the node the tail links back to (-1 = no cycle)
    int n, pos;
    if (!(cin >> n >> pos)) return 0;
    vector<ListNode*> nodes;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nodes.push_back(new ListNode(x));
    }
    for (int i = 0; i + 1 < n; i++) nodes[i]->next = nodes[i + 1];
    if (n > 0 && pos >= 0) nodes[n - 1]->next = nodes[pos];
    Solution sol;
    ListNode* head = (n > 0) ? nodes[0] : nullptr;
    // output: true or false
    cout << (sol.solve(head) ? "true" : "false") << "\n";
    return 0;
}
