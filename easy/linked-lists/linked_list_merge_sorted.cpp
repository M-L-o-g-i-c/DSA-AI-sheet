// linked_list_merge_sorted: merge two sorted linked lists
// topic: easy/linked-lists — dummy-head merge
// problem: LeetCode 21. Merge Two Sorted Lists
// links:   https://leetcode.com/problems/merge-two-sorted-lists/
//          https://leetcode.cn/problems/merge-two-sorted-lists/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 21. Merge Two Sorted Lists - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/merge-two-sorted-lists/solution/

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
    // dummy head avoids a special case for the first node.
    ListNode* solve(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = (list1 != nullptr) ? list1 : list2;
        return dummy.next;
    }
};

// read n values from stdin and build a linked list from them
ListNode* buildList(int n) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}

int main() {
    // input: n1 \n v1[0] ... v1[n1-1] \n n2 \n v2[0] ... v2[n2-1]
    // (both lists sorted ascending)
    int n1, n2;
    if (!(cin >> n1)) return 0;
    ListNode* list1 = buildList(n1);
    cin >> n2;
    ListNode* list2 = buildList(n2);
    Solution sol;
    ListNode* res = sol.solve(list1, list2);
    // output: merged list values, space separated
    for (ListNode* p = res; p != nullptr; p = p->next) {
        if (p != res) cout << " ";
        cout << p->val;
    }
    cout << "\n";
    return 0;
}
