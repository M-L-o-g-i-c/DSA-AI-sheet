// string_stl: std::string find, substr, append, compare
// topic: easy/strings — STL usage (find/substr/append/compare)
// problem: demo — std::string find, substr, append, compare
// links:   (demo, no external problem)
// reference:
//   Author(s): cppreference contributors
//   Date: 2026-11-26 (accessed)
//   Title: std::basic_string
//   Code version: online article
//   Type: article
//   URL: https://en.cppreference.com/w/cpp/string/basic_string.html

#include <bits/stdc++.h>
using namespace std;

// Four core std::string operations, exercised on one pair of strings.
class Solution {
public:
    vector<string> solve(const string& s, const string& t) {
        vector<string> out;
        size_t pos = s.find(t);  // find: npos when t is absent
        out.push_back(pos == string::npos ? string("-1") : to_string(pos));
        out.push_back(pos == string::npos ? string("") : s.substr(pos));
        string appended = s;
        appended.append(t);  // append: t glued to the end of s
        out.push_back(appended);
        out.push_back(to_string(s.compare(t)));  // compare: <0, 0 or >0
        return out;
    }
};

int main() {
    // input: two tokens s t (no spaces inside either)
    // output: 4 lines — find pos (-1 if absent), suffix from that pos,
    //         s with t appended, and the three-way compare(s, t) result
    string s, t;
    if (!(cin >> s >> t)) return 0;
    Solution sol;
    for (const string& line : sol.solve(s, t)) cout << line << "\n";
    return 0;
}
