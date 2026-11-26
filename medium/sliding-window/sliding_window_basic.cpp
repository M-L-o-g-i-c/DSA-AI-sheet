// sliding_window_basic: fixed and variable window in one pass
// topic: medium/sliding-window — fixed and variable window
// problem: demo — max sum over windows of size k; longest window with sum <= x
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Fixed window slides by adding the new element and dropping the oldest.
// Variable window grows hi, shrinks lo while the constraint breaks (needs a[i] >= 0).
class Solution {
public:
    pair<long long, int> solve(const vector<int>& a, int k, int x) {
        int n = (int)a.size();
        long long sum = 0;
        for (int i = 0; i < k; ++i) sum += a[i];
        long long bestSum = sum;
        for (int i = k; i < n; ++i) {
            sum += a[i] - a[i - k];
            bestSum = max(bestSum, sum);
        }

        int lo = 0, bestLen = 0;
        sum = 0;
        for (int hi = 0; hi < n; ++hi) {
            sum += a[hi];
            while (sum > x) {
                sum -= a[lo];
                ++lo;
            }
            bestLen = max(bestLen, hi - lo + 1);
        }
        return {bestSum, bestLen};
    }
};

int main() {
    // input: n k x \n a[0] ... a[n-1]   (a[i] >= 0, 1 <= k <= n)
    int n, k, x;
    if (!(cin >> n >> k >> x)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    auto [bestSum, bestLen] = sol.solve(a, k, x);
    cout << bestSum << " " << bestLen << "\n";
    return 0;
}
