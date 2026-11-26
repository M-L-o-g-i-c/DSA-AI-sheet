// geometry_basic: points/vectors with dot + cross product
// topic: unhinged/geometry — basic points/vectors (dot + cross)
// problem: demo — dot and cross product of two vectors
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Basic Geometry
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/geometry/basic-geometry.html

#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

// dot(a,b) = ax*bx + ay*by ; cross(a,b) = ax*by - ay*bx
class Solution {
public:
    long long dot(const Point& a, const Point& b) {
        return a.x * b.x + a.y * b.y;
    }

    long long cross(const Point& a, const Point& b) {
        return a.x * b.y - a.y * b.x;
    }

    // returns {dot(a,b), cross(a,b)}
    pair<long long, long long> solve(const Point& a, const Point& b) {
        return {dot(a, b), cross(a, b)};
    }
};

int main() {
    // input: ax ay bx by   (two vectors a and b)
    // output: dot cross
    Point a, b;
    if (!(cin >> a.x >> a.y >> b.x >> b.y)) return 0;
    Solution sol;
    auto res = sol.solve(a, b);
    cout << res.first << " " << res.second << "\n";
    return 0;
}
