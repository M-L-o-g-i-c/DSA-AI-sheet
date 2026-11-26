// arrays_basic: read an array, traverse once, compute min, max and sum
// topic: easy/arrays — array basics (traverse, min/max/sum)
// problem: demo — one-pass traversal computing min, max and sum
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // one pass keeps a running min, max and sum.
    vector<long long> solve(const vector<int>& a) {
        long long mn = a[0], mx = a[0], sum = 0;
        for (int v : a) {
            mn = min(mn, (long long)v);
            mx = max(mx, (long long)v);
            sum += v;
        }
        return {mn, mx, sum};
    }
};

int main() {
    // input: n \n a[0] ... a[n-1]   (n >= 1)
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    vector<long long> res = sol.solve(a);
    // output: min max sum
    cout << res[0] << " " << res[1] << " " << res[2] << "\n";
    return 0;
}
