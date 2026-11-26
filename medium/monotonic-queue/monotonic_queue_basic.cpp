// monotonic_queue_basic: window maximum and minimum with a deque
// topic: medium/monotonic-queue — deque keeping window max/min
// problem: demo — max and min of every window of size k
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Deque holds indices; values go decreasing (max) / increasing (min) front to back.
// The front is always the current window answer; expire indices that slid out.
class Solution {
public:
    pair<vector<int>, vector<int>> solve(const vector<int>& a, int k) {
        deque<int> mx, mn;
        vector<int> maxs, mins;
        for (int i = 0; i < (int)a.size(); ++i) {
            while (!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
            mx.push_back(i);
            while (!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
            mn.push_back(i);
            if (mx.front() <= i - k) mx.pop_front();
            if (mn.front() <= i - k) mn.pop_front();
            if (i >= k - 1) {
                maxs.push_back(a[mx.front()]);
                mins.push_back(a[mn.front()]);
            }
        }
        return {maxs, mins};
    }
};

int main() {
    // input: n k \n a[0] ... a[n-1]   (1 <= k <= n)
    // output: window maxima, then window minima
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    auto [maxs, mins] = sol.solve(a, k);
    for (int i = 0; i < (int)maxs.size(); ++i)
        cout << maxs[i] << (i + 1 == (int)maxs.size() ? "\n" : " ");
    for (int i = 0; i < (int)mins.size(); ++i)
        cout << mins[i] << (i + 1 == (int)mins.size() ? "\n" : " ");
    return 0;
}
