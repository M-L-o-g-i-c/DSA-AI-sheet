// topological_sort_kahn: Kahn's BFS topological sort of courses
// topic: tough/topological-sort — Kahn (BFS)
// problem: LeetCode 210. Course Schedule II
// links:   https://leetcode.com/problems/course-schedule-ii/
//          https://leetcode.cn/problems/course-schedule-ii/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 210. Course Schedule II - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/course-schedule-ii/solution/

#include <bits/stdc++.h>
using namespace std;

// prerequisites[i] = [a, b] means b must come before a, i.e. edge b -> a.
class Solution {
public:
    vector<int> solve(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (const auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int u = 0; u < numCourses; u++)
            if (indeg[u] == 0) q.push(u);
        vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u])
                if (--indeg[v] == 0) q.push(v);
        }
        if ((int)order.size() != numCourses) return {};
        return order;
    }
};

int main() {
    // input: n m \n m lines "a b" (course a depends on b: b before a)
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> prerequisites(m, vector<int>(2));
    for (auto& p : prerequisites) cin >> p[0] >> p[1];
    Solution sol;
    vector<int> order = sol.solve(n, prerequisites);
    if (order.empty()) {
        cout << "impossible\n";
    } else {
        for (size_t i = 0; i < order.size(); i++) {
            if (i) cout << " ";
            cout << order[i];
        }
        cout << "\n";
    }
    return 0;
}
