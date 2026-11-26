// topological_sort_dfs: DFS cycle detection for course scheduling
// topic: tough/topological-sort — DFS (cycle detection)
// problem: LeetCode 207. Course Schedule
// links:   https://leetcode.com/problems/course-schedule/
//          https://leetcode.cn/problems/course-schedule/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 207. Course Schedule - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/course-schedule/solution/

#include <bits/stdc++.h>
using namespace std;

// Courses can be finished iff the prerequisite graph is a DAG.
// Gray node revisited = back edge = cycle.
class Solution {
    bool dfs(int u, const vector<vector<int>>& adj, vector<int>& color) {
        color[u] = 1;
        for (int v : adj[u]) {
            if (color[v] == 1) return true;
            if (color[v] == 0 && dfs(v, adj, color)) return true;
        }
        color[u] = 2;
        return false;
    }

public:
    bool solve(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& p : prerequisites) adj[p[1]].push_back(p[0]);
        vector<int> color(numCourses, 0);
        for (int u = 0; u < numCourses; u++)
            if (color[u] == 0 && dfs(u, adj, color)) return false;
        return true;
    }
};

int main() {
    // input: n m \n m lines "a b" (course a depends on b: b before a)
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> prerequisites(m, vector<int>(2));
    for (auto& p : prerequisites) cin >> p[0] >> p[1];
    Solution sol;
    cout << (sol.solve(n, prerequisites) ? 1 : 0) << "\n";
    return 0;
}
