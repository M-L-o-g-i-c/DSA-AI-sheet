// divide_conquer_basic: divide, solve halves, combine by merging
// topic: tough/divide-and-conquer — divide, solve halves, combine
// problem: demo — merge two sorted halves of an array into one sorted array
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// a[0..mid) and a[mid..n) are the two sorted halves (solved subproblems);
// merging them is the combine step of divide and conquer.
class Solution {
public:
    vector<int> solve(const vector<int>& a) {
        int n = (int)a.size();
        int mid = n / 2;                    // divide
        // solve halves: both halves are already sorted
        vector<int> res;
        int i = 0, j = mid;                 // combine: merge the two halves
        while (i < mid && j < n) {
            if (a[i] <= a[j]) res.push_back(a[i++]);
            else res.push_back(a[j++]);
        }
        while (i < mid) res.push_back(a[i++]);
        while (j < n) res.push_back(a[j++]);
        return res;
    }
};

int main() {
    // input: n \n a[0] ... a[n-1]   (first half sorted, second half sorted)
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    vector<int> res = sol.solve(a);
    for (size_t i = 0; i < res.size(); i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
    return 0;
}
