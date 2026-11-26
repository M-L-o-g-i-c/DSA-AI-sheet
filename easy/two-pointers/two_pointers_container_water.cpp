// two_pointers_container_water: LeetCode 11 — greedy opposite-direction search for max area
// topic: easy/two-pointers — container with most water
// problem: LeetCode 11. Container With Most Water
// links:
//   https://leetcode.com/problems/container-with-most-water/
//   https://leetcode.cn/problems/container-with-most-water/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 11. Container With Most Water - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/container-with-most-water/solution/

#include <bits/stdc++.h>
using namespace std;

// Move the shorter side inward: it is the only way a wider-but-shorter pair could win.
class Solution {
public:
    int solve(vector<int>& height) {
        int i = 0, j = (int)height.size() - 1, best = 0;
        while (i < j) {
            best = max(best, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return best;
    }
};

int main() {
    // input: n \n h[0] ... h[n-1]
    // output: the maximum area
    int n;
    if (!(cin >> n)) return 0;
    vector<int> h(n);
    for (auto& v : h) cin >> v;
    Solution sol;
    cout << sol.solve(h) << "\n";
    return 0;
}
