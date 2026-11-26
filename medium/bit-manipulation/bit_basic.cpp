// bit_basic: the six bitwise operators and get/set/clear bit
// topic: medium/bit-manipulation — how it works (ops, get/set/clear bit)
// problem: demo — evaluate & | ^ ~ << >> on a and b; get/set/clear bit i of a
// links:   (demo, no external problem)
// reference:
//   Author(s): CP-Algorithms
//   Date: 2026-11-26 (accessed)
//   Title: Bit Manipulation
//   Code version: online article
//   Type: article
//   URL: https://cp-algorithms.com/algebra/bit-manipulation.html

#include <bits/stdc++.h>
using namespace std;

// Returns the nine basic results in a fixed order (see return list below).
class Solution {
public:
    vector<long long> solve(long long a, long long b, int i) {
        long long set = a | (1LL << i);    // force bit i to 1
        long long clr = a & ~(1LL << i);   // force bit i to 0
        return {
            a & b,           // AND: 1 only if both bits are 1
            a | b,           // OR:  1 if at least one bit is 1
            a ^ b,           // XOR: 1 if the bits differ
            ~a,              // NOT: flip every bit
            a << 1,          // shift left:  x2 (drops the top bit)
            a >> 1,          // shift right: /2
            (a >> i) & 1LL,  // get bit i
            set,
            clr
        };
    }
};

int main() {
    // input: a b i   (two integers and a bit index 0..62)
    long long a, b;
    int i;
    if (!(cin >> a >> b >> i)) return 0;
    Solution sol;
    vector<long long> r = sol.solve(a, b, i);
    const char* names[9] = {"a&b", "a|b", "a^b", "~a", "a<<1", "a>>1",
                            "getBit(a,i)", "setBit(a,i)", "clearBit(a,i)"};
    for (int j = 0; j < 9; ++j) cout << names[j] << " = " << r[j] << "\n";
    return 0;
}
