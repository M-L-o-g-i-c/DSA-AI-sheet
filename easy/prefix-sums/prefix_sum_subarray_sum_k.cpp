// prefix_sum_subarray_sum_k: count subarrays with sum k via prefix sums + hash map
// topic: easy/prefix-sums — prefix sum + hash map
// problem: LeetCode 560. Subarray Sum Equals K
// links:   https://leetcode.com/problems/subarray-sum-equals-k/
//          https://leetcode.cn/problems/subarray-sum-equals-k/
// reference:
//   Author(s): LeetCode
//   Date: 2026-11-26 (accessed)
//   Title: 560. Subarray Sum Equals K - Solution
//   Code version: online article
//   Type: article
//   URL: https://leetcode.com/problems/subarray-sum-equals-k/solution/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // subarray sum k <=> prefix[j] - prefix[i] == k; count pairs via hash map.
    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0, ans = 0;
        for (int v : nums) {
            sum += v;
            auto it = cnt.find(sum - k);
            if (it != cnt.end()) ans += it->second;
            cnt[sum]++;
        }
        return ans;
    }
};

int main() {
    // input: n k \n nums[0] ... nums[n-1]
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    Solution sol;
    // output: number of subarrays with sum k
    cout << sol.solve(nums, k) << "\n";
    return 0;
}
