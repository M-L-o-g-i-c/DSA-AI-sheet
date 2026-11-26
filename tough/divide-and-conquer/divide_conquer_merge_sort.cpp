// divide_conquer_merge_sort: top-down merge sort (sort halves, merge)
// topic: tough/divide-and-conquer — merge sort
// problem: LeetCode 912. Sort an Array
// links:
//   https://leetcode.com/problems/sort-an-array/
//   https://leetcode.cn/problems/sort-an-array/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Sort an Array
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/sort-an-array/solution/

#include <bits/stdc++.h>
using namespace std;

// Recursively sort both halves, then merge them through an auxiliary buffer.
class Solution {
public:
    vector<int> solve(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> aux(n);
        function<void(int, int)> mergeSort = [&](int lo, int hi) {
            if (hi - lo <= 1) return;
            int mid = lo + (hi - lo) / 2;
            mergeSort(lo, mid);   // solve left half
            mergeSort(mid, hi);   // solve right half
            // combine: merge sorted halves [lo,mid) and [mid,hi)
            int i = lo, j = mid, k = lo;
            while (i < mid && j < hi) {
                if (nums[i] <= nums[j]) aux[k++] = nums[i++];
                else aux[k++] = nums[j++];
            }
            while (i < mid) aux[k++] = nums[i++];
            while (j < hi) aux[k++] = nums[j++];
            for (int t = lo; t < hi; t++) nums[t] = aux[t];
        };
        mergeSort(0, n);
        return nums;
    }
};

int main() {
    // input: n \n nums[0] ... nums[n-1]
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    Solution sol;
    vector<int> res = sol.solve(nums);
    for (size_t i = 0; i < res.size(); i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
    return 0;
}
