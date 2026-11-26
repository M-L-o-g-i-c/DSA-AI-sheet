// two_pointers_two_sum_sorted: LeetCode 167 — opposite-direction pair search on sorted input
// topic: easy/two-pointers — two sum on sorted input
// problem: LeetCode 167. Two Sum II - Input Array Is Sorted
// links:
//   https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//   https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 167. Two Sum II - Input Array Is Sorted - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/solution/

#include <bits/stdc++.h>
using namespace std;

// Sorted input lets both ends steer: sum too small -> advance lo, else retreat hi.
class Solution {
public:
    vector<int> solve(vector<int>& numbers, int target) {
        int lo = 0, hi = (int)numbers.size() - 1;
        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if (sum == target) return {lo + 1, hi + 1};  // 1-based indices
            if (sum < target) lo++;
            else hi--;
        }
        return {};
    }
};

int main() {
    // input: n target \n a[0] ... a[n-1]   (a sorted ascending, exactly one pair exists)
    // output: the 1-based indices i j
    int n, target;
    if (!(cin >> n >> target)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    vector<int> res = sol.solve(a, target);
    cout << res[0] << " " << res[1] << "\n";
    return 0;
}
