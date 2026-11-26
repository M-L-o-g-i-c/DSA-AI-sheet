// linked_list_reverse: reverse a singly linked list iteratively
// topic: easy/linked-lists — iterative reverse
// problem: LeetCode 206. Reverse Linked List
// links:   https://leetcode.com/problems/reverse-linked-list/
//          https://leetcode.cn/problems/reverse-linked-list/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 206. Reverse Linked List - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/reverse-linked-list/solution/

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
    // rewire next pointers backwards; prev becomes the new head.
    ListNode* solve(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
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
    // output: values of the reversed list, space separated
    for (ListNode* p = res; p != nullptr; p = p->next) {
        if (p != res) cout << " ";
        cout << p->val;
    }
    cout << "\n";
    return 0;
}
