// greedy_gas_station: greedy circuit-start scan for Gas Station
// topic: medium/greedy — gas station (greedy circuit)
// problem: LeetCode 134. Gas Station
// links:   https://leetcode.com/problems/gas-station/
//          https://leetcode.cn/problems/gas-station/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: Gas Station - Official Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/gas-station/solution/

#include <bits/stdc++.h>
using namespace std;

// If total gas >= total cost a circuit exists; move the start forward
// whenever the running tank goes negative (that prefix cannot work).
class Solution {
public:
    int solve(vector<int>& gas, vector<int>& cost) {
        int total = 0, tank = 0, start = 0;
        for (int i = 0; i < (int)gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};

int main() {
    // input: n \n gas[0] ... gas[n-1] \n cost[0] ... cost[n-1]
    int n;
    if (!(cin >> n)) return 0;
    vector<int> gas(n), cost(n);
    for (auto& v : gas) cin >> v;
    for (auto& v : cost) cin >> v;
    Solution sol;
    cout << sol.solve(gas, cost) << "\n";
    return 0;
}
