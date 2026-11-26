// binary_search_upper_bound_stl: std::upper_bound usage
// topic: easy/binary-search — C++ STL (upper bound)
// problem: demo — count elements <= x in a sorted array via upper_bound
// links:   (demo, no external problem)
// reference:
//   Author(s): cppreference contributors
//   Date: 2026-11-26 (accessed)
//   Title: std::upper_bound
//   Code version: online article
//   Type: article
//   URL: https://en.cppreference.com/w/cpp/algorithm/upper_bound.html

#include <bits/stdc++.h>
using namespace std;

// std::upper_bound returns an iterator to the first element > x.
// Everything strictly left of it is <= x, so the distance is the count.
class Solution {
public:
    int solve(const vector<int>& a, int x) {
        return (int)(upper_bound(a.begin(), a.end(), x) - a.begin());
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
