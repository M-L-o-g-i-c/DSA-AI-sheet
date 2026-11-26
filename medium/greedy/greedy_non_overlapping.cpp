// greedy_non_overlapping: earliest-finish greedy for Non-overlapping Intervals
// topic: medium/greedy — non-overlapping intervals (earliest finish)
// problem: LeetCode 435. Non-overlapping Intervals
// links:   https://leetcode.com/problems/non-overlapping-intervals/
//          https://leetcode.cn/problems/non-overlapping-intervals/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Non-overlapping Intervals - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/non-overlapping-intervals/solution/

#include <bits/stdc++.h>
using namespace std;

// Keep a maximum set of non-overlapping intervals (earliest finish first);
// the answer is total minus kept.
class Solution {
public:
    int solve(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int kept = 0;
        long long last = LLONG_MIN;
        for (const auto& iv : intervals) {
            if (iv[0] >= last) {
                kept++;
                last = iv[1];
            }
        }
        return (int)intervals.size() - kept;
    }
};

int main() {
    // input: n \n then n lines of "start end" (start < end)
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> a(n, vector<int>(2));
    for (auto& iv : a) cin >> iv[0] >> iv[1];
    Solution sol;
    cout << sol.solve(a) << "\n";
    return 0;
}
