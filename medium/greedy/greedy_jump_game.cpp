// greedy_jump_game: greedy farthest-reach scan for Jump Game
// topic: medium/greedy — jump game (greedy reach)
// problem: LeetCode 55. Jump Game
// links:   https://leetcode.com/problems/jump-game/
//          https://leetcode.cn/problems/jump-game/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Jump Game - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/jump-game/solution/

#include <bits/stdc++.h>
using namespace std;

// Track the farthest reachable index; fail as soon as an index is out of reach.
class Solution {
public:
    bool solve(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > reach) return false;
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};

int main() {
    // input: n \n n space-separated jump lengths
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (auto& v : a) cin >> v;
    Solution sol;
    cout << (sol.solve(a) ? "true" : "false") << "\n";
    return 0;
}
