// binary_search_upper_bound: own implementation of std::upper_bound
// topic: easy/binary-search — own implementation (upper bound)
// problem: demo — first index i with a[i] > x (returns n if none)
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Binary Search
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/num_methods/binary_search.html

#include <bits/stdc++.h>
using namespace std;

// upper_bound: first position where value > x could be inserted keeping order.
class Solution {
public:
    int solve(const vector<int>& a, int x) {
        int lo = 0, hi = (int)a.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] > x) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

int main() {
    // input: n x \n a[0] ... a[n-1]   (a sorted ascending)
    int n, x;
    if (!(cin >> n >> x)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    cout << sol.solve(a, x) << "\n";
    return 0;
}
