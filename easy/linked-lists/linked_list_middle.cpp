// linked_list_middle: find the middle node with slow/fast pointers
// topic: easy/linked-lists — slow/fast pointers
// problem: LeetCode 876. Middle of the Linked List
// links:   https://leetcode.com/problems/middle-of-the-linked-list/
//          https://leetcode.cn/problems/middle-of-the-linked-list/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 876. Middle of the Linked List - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/middle-of-the-linked-list/solution/

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
    // slow moves 1 step, fast moves 2; slow lands on the middle
    // (second middle when the length is even, as the problem asks).
    ListNode* solve(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    // input: n \n v[0] ... v[n-1]
    int n;
    if (!(cin >> n)) return 0;
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    Solution sol;
    ListNode* res = sol.solve(dummy.next);
    // output: values from the middle node to the end, space separated
    for (ListNode* p = res; p != nullptr; p = p->next) {
        if (p != res) cout << " ";
        cout << p->val;
    }
    cout << "\n";
    return 0;
}
