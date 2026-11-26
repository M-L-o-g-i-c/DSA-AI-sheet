// arrays_reverse: in-place array reversal with two pointers
// topic: easy/arrays — two pointers (in-place reverse)
// problem: demo — reverse an array in place with two pointers
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // swap inward from both ends until the pointers meet.
    void solve(vector<int>& a) {
        int i = 0, j = (int)a.size() - 1;
        while (i < j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
};

int main() {
    // input: n \n a[0] ... a[n-1]
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    sol.solve(a);
    // output: reversed a[0] ... a[n-1]
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
