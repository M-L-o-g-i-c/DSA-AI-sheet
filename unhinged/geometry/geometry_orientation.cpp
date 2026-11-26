// geometry_orientation: orientation test (left/right/collinear)
// topic: unhinged/geometry — orientation test (left/right/collinear)
// problem: demo — turn direction of the path a -> b -> c
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Oriented area of a triangle
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/geometry/oriented-triangle-area.html

#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

// sign of cross((b-a),(c-a)): >0 left turn, <0 right turn, 0 collinear
class Solution {
public:
    // 1 = left turn (counter-clockwise), -1 = right turn (clockwise), 0 = collinear
    int solve(const Point& a, const Point& b, const Point& c) {
        long long v = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        if (v > 0) return 1;
        if (v < 0) return -1;
        return 0;
    }
};

int main() {
    // input: ax ay bx by cx cy   (three points along the path a -> b -> c)
    Point a, b, c;
    if (!(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y)) return 0;
    Solution sol;
    int res = sol.solve(a, b, c);
    if (res == 1) cout << "left\n";
    else if (res == -1) cout << "right\n";
    else cout << "collinear\n";
    return 0;
}
