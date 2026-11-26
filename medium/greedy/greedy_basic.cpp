// greedy_basic: activity selection by earliest finish time
// topic: medium/greedy — activity selection (earliest finish time)
// problem: demo — maximum number of non-overlapping activities
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Greedy choice: always take the activity that finishes earliest and
// does not overlap the last taken one; this maximizes the count.
class Solution {
public:
    int solve(vector<pair<int, int>>& a) {
        sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.second < y.second;
        });
        int count = 0;
        int lastFinish = INT_MIN;
        for (const auto& [s, f] : a) {
            if (s >= lastFinish) {
                count++;
                lastFinish = f;
            }
        }
        return count;
    }
};

int main() {
    // input: n \n then n lines of "start finish" (finish > start)
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<int, int>> a(n);
    for (auto& [s, f] : a) cin >> s >> f;
    Solution sol;
    cout << sol.solve(a) << "\n";
    return 0;
}
