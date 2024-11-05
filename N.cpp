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

const int maxn = 2 * 1e6;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n; 
    vector<ll> sumsq;
    sumsq.push_back(0);
    for (ll i = 1; i < maxn; i++) {
        ll curval = i * (i+1) / 2;
        curval = curval * (2*i+1) / 3;
        if (curval > n) break;
        sumsq.push_back(curval);
    }
    for (int i = sumsq.size()-1; i > 0; i--) {
        if (n % sumsq[i] && n != sumsq[i]) continue;
        ll sq = n/sumsq[i];
        ll sqsq = sqrt(sq);
        if (sqsq * sqsq == sq) {
            cout << "YES\n";
            cout << sqsq << " " << i << "\n";
            return 0;
        }
    }
    cout << "NO\n";
}