#include <iostream>
#include <cstdint>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int n, ql;
    cin >> n >> ql;

    string as[n], bs[n];
    for (int i = 0; i < n; ++i) cin >> bs[i] >> as[i];
    for (int qi = 0; qi < ql; ++qi) {
        // cout << "---" << endl;
        // for (int i = 0; i < n; ++i) cout << as[i] << ':' << bs[i] << ' '; cout << endl;
        // cout << "---" << endl;
        string q;
        cin >> q;
        long long dp[q.size() + 1];
        int orig[q.size() + 1];
        dp[0] = 0;
        orig[0] = -1;
        for (int i = 1; i <= q.size(); ++i) {
            dp[i] = dp[i - 1] + 1;
            orig[i] = -1;
            for (int ni = 0; ni < n; ++ni) {
                if (i >= as[ni].size() && as[ni] == q.substr(i - as[ni].size(), as[ni].size())) {
                    if (dp[i - as[ni].size()] + (long long)bs[ni].size() + 1 < dp[i]) {
                        dp[i] = dp[i - as[ni].size()] + (long long)bs[ni].size() + 1;
                        orig[i] = ni;
                    }
                }
            }
        }
        stringstream ss;
        for (int i = q.size(); i > 0;) {
            if (orig[i] == -1) {
                // cout << q[i - 1] << " ";
                ss << q[i - 1];
                i--;
            } else {
                string cs = bs[orig[i]];
                reverse(cs.begin(), cs.end());
                // cout << orig[i] << endl;
                // cout << (char)('A' + orig[i]) << " " << bs[orig[i]] << " ";
                ss << (char)('A' + orig[i]) << cs;
                i -= as[orig[i]].size();
            }
        }
        // cout << endl;
        string res = ss.str();
        reverse(res.begin(), res.end());
        cout << res << endl;
    }

    return 0;
}