// monotonic_queue_max_value_equation: maximize yi + yj + |xi - xj|
// topic: medium/monotonic-queue — deque on (y - x)
// problem: LeetCode 1499. Max Value of Equation
// links:
//   https://leetcode.com/problems/max-value-of-equation/
//   https://leetcode.cn/problems/max-value-of-equation/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Max Value of Equation
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/max-value-of-equation/solution/

#include <bits/stdc++.h>
using namespace std;

// For xj >= xi the value is (yi - xi) + (yj + xj); keep (y - x) candidates in a
// deque, dropping those too far left (xj - xi > k) and those beaten at the back.
class Solution {
public:
    int solve(vector<vector<int>>& points, int k) {
        deque<int> dq;
        int best = INT_MIN;
        for (int j = 0; j < (int)points.size(); ++j) {
            while (!dq.empty() && points[j][0] - points[dq.front()][0] > k)
                dq.pop_front();
            if (!dq.empty())
                best = max(best, points[dq.front()][1] - points[dq.front()][0]
                                     + points[j][1] + points[j][0]);
            int val = points[j][1] - points[j][0];
            while (!dq.empty() && points[dq.back()][1] - points[dq.back()][0] <= val)
                dq.pop_back();
            dq.push_back(j);
        }
        return best;
    }
};

int main() {
    // input: n k \n x0 y0 \n x1 y1 ... \n xn-1 yn-1   (points sorted by x)
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<vector<int>> pts(n, vector<int>(2));
    for (auto& p : pts) cin >> p[0] >> p[1];
    Solution sol;
    cout << sol.solve(pts, k) << "\n";
    return 0;
}
