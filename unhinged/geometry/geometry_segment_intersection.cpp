// geometry_segment_intersection: segment intersection test
// topic: unhinged/geometry — segment intersection test
// problem: demo — do closed segments AB and CD intersect
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Check if two segments intersect
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/geometry/check-segments-intersection.html

#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

// orientation + bounding-box test, handles proper crossings and touching ends
class Solution {
    long long cross(const Point& o, const Point& a, const Point& b) {
        return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
    }

    static int sign(long long v) { return (v > 0) - (v < 0); }

    // p is collinear with a-b and lies inside the bounding box of a-b
    bool onSegment(const Point& a, const Point& b, const Point& p) {
        return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
            && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
    }

public:
    bool solve(const Point& a, const Point& b, const Point& c, const Point& d) {
        long long d1 = cross(c, d, a);
        long long d2 = cross(c, d, b);
        long long d3 = cross(a, b, c);
        long long d4 = cross(a, b, d);
        if (sign(d1) * sign(d2) < 0 && sign(d3) * sign(d4) < 0) return true;
        if (d1 == 0 && onSegment(c, d, a)) return true;
        if (d2 == 0 && onSegment(c, d, b)) return true;
        if (d3 == 0 && onSegment(a, b, c)) return true;
        if (d4 == 0 && onSegment(a, b, d)) return true;
        return false;
    }
};

int main() {
    // input: ax ay bx by cx cy dx dy   (segments AB and CD)
    Point a, b, c, d;
    if (!(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y)) return 0;
    Solution sol;
    cout << (sol.solve(a, b, c, d) ? "yes" : "no") << "\n";
    return 0;
}
