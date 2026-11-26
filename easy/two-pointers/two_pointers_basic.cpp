// two_pointers_basic: how it works — same-direction and opposite-direction pointers
// topic: easy/two-pointers — how it works (same-direction + opposite-direction)
// problem: demo — opposite-direction palindrome check and same-direction max equal run
// links:   (demo, no external problem)
// reference: none (original demo)

#include <bits/stdc++.h>
using namespace std;

// Returns {is_palindrome, longest_run_of_equal_values}.
class Solution {
public:
    vector<int> solve(const vector<int>& a) {
        int n = (int)a.size();

        // Opposite-direction: start at both ends, walk inward until they disagree.
        int pal = 1;
        for (int i = 0, j = n - 1; i < j; i++, j--)
            if (a[i] != a[j]) {
                pal = 0;
                break;
            }

        // Same-direction: slow marks a run's start, fast scans to the run's end.
        int best = 0;
        for (int slow = 0; slow < n;) {
            int fast = slow;
            while (fast < n && a[fast] == a[slow]) fast++;
            best = max(best, fast - slow);
            slow = fast;
        }
        return {pal, best};
    }
};

int main() {
    // input: n \n a[0] ... a[n-1]
    // output: <is_palindrome 0/1> <longest run of equal adjacent values>
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    vector<int> res = sol.solve(a);
    cout << res[0] << " " << res[1] << "\n";
    return 0;
}
