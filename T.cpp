#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef vector<int> vi;
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


int timeToMinutes(string time_str) {
    int ans = 0, laststr = -1;
    for(int i = 0; i < time_str.size(); i++) {
        if (time_str[i] == 'd') {
            ans += 1440 * stoi(time_str.substr(laststr + 1, i - laststr - 1));
            laststr = i;
        }
        else if (time_str[i] == 'h') {
            ans += 60 * stoi(time_str.substr(laststr + 1, i - laststr - 1));
            laststr = i;
        }
        else if (time_str[i] == 'm') {
            ans += stoi(time_str.substr(laststr + 1, i - laststr - 1));
            laststr = i;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    vector<pair<ll, ll>> coins(n);
    vector<ll> ans(q);
    
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        ll cost; cin >> cost;
        coins[i] = {cost, timeToMinutes(s)};
    }

    for (int i = 0; i < q; i++) {
        string s; cin >> s;
        ans[i] = timeToMinutes(s);
    }

    long long maxele = 4e6; 
    vector<ll> dp(maxele + 1, (long long)1e18);
    dp[0] = 0;
    for (int cur = 1; cur <= maxele; cur++) {
        for (pair<ll, ll> c : coins) {
            if (cur - c.second < 0) continue;
            dp[cur] = min(dp[cur], dp[cur - c.second] + c.first);
        }
    }

    for (int cur = maxele - 1; cur >= 0; cur--) {
        dp[cur] = min(dp[cur], dp[cur + 1]);
    }

    for (int i : ans) {
        cout << "$" << fixed << setprecision(2) << (double)dp[i] / 100 << "\n";
    }

    return 0;
}
