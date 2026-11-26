// geometry_polygon_area: shoelace formula polygon area
// topic: unhinged/geometry — shoelace formula
// problem: demo — area of a simple polygon given in vertex order
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Area of simple polygon
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/geometry/area-of-simple-polygon.html

#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

// shoelace: 2*area = |sum over edges of (x_i*y_{i+1} - y_i*x_{i+1})|
class Solution {
public:
    double solve(const vector<Point>& p) {
        int n = (int)p.size();
        long long s = 0;
        for (int i = 0; i < n; i++) {
            const Point& a = p[i];
            const Point& b = p[(i + 1) % n];
            s += a.x * b.y - a.y * b.x;
        }
        if (s < 0) s = -s;
        return 0.5 * s;
    }
};

int main() {
    // input: n \n x y (n lines)   (vertices in order, clockwise or counter-clockwise)
    int n;
    if (!(cin >> n)) return 0;
    vector<Point> p(n);
    for (auto& q : p) cin >> q.x >> q.y;
    Solution sol;
    cout << sol.solve(p) << "\n";
    return 0;
}
