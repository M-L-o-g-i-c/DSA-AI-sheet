// geometry_convex_hull: Andrew's monotone chain convex hull
// topic: unhinged/geometry — Andrew's monotone chain
// problem: demo — convex hull of a point set (vertices in CCW order)
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Convex hull construction
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/geometry/convex-hull.html

#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

// cross(o,a,b) = (a-o) x (b-o)
long long cross(const Point& o, const Point& a, const Point& b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

// monotone chain: lower hull + upper hull, merged CCW; collinear points dropped
class Solution {
public:
    vector<Point> solve(vector<Point> p) {
        sort(p.begin(), p.end());
        int n = (int)p.size();
        if (n <= 1) return p;
        vector<Point> h(2 * n);
        int k = 0;
        for (int i = 0; i < n; i++) {                       // lower hull
            while (k >= 2 && cross(h[k - 2], h[k - 1], p[i]) <= 0) k--;
            h[k++] = p[i];
        }
        int lower = k + 1;
        for (int i = n - 2; i >= 0; i--) {                  // upper hull
            while (k >= lower && cross(h[k - 2], h[k - 1], p[i]) <= 0) k--;
            h[k++] = p[i];
        }
        h.resize(k - 1);   // last point repeats the first
        return h;
    }
};

int main() {
    // input: n \n x y (n lines)   (distinct points)
    // output: k \n x y (k lines)  — hull vertices CCW, first = leftmost-lowest
    int n;
    if (!(cin >> n)) return 0;
    vector<Point> p(n);
    for (auto& q : p) cin >> q.x >> q.y;
    Solution sol;
    vector<Point> hull = sol.solve(p);
    cout << hull.size() << "\n";
    for (auto& q : hull) cout << q.x << " " << q.y << "\n";
    return 0;
}
