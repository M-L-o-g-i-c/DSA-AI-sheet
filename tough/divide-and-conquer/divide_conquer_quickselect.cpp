// divide_conquer_quickselect: partition around a pivot, recurse into one side
// topic: tough/divide-and-conquer — quickselect (kth largest)
// problem: LeetCode 215. Kth Largest Element in an Array
// links:
//   https://leetcode.com/problems/kth-largest-element-in-an-array/
//   https://leetcode.cn/problems/kth-largest-element-in-an-array/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Kth Largest Element in an Array
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/kth-largest-element-in-an-array/solution/

#include <bits/stdc++.h>
using namespace std;

// Kth largest == index n-k in ascending order. Partition, then only recurse
// into the side that contains that index.
class Solution {
public:
    int solve(vector<int>& nums, int k) {
        vector<int> a = nums;
        int target = (int)a.size() - k;
        auto partition = [&](int lo, int hi) -> int {
            // pivot: middle element moved to the end (Lomuto scheme)
            int pivotIdx = lo + (hi - lo) / 2;
            int pivot = a[pivotIdx];
            swap(a[pivotIdx], a[hi]);
            int i = lo;
            for (int j = lo; j < hi; j++) {
                if (a[j] < pivot) {
                    swap(a[i], a[j]);
                    i++;
                }
            }
            swap(a[i], a[hi]);
            return i;
        };
        int lo = 0, hi = (int)a.size() - 1;
        while (lo <= hi) {
            int p = partition(lo, hi);
            if (p == target) return a[p];
            if (p < target) lo = p + 1;
            else hi = p - 1;
        }
        return -1;
    }
};

int main() {
    // input: n k \n nums[0] ... nums[n-1]
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    Solution sol;
    cout << sol.solve(nums, k) << "\n";
    return 0;
}
