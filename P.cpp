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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int gx, gy; cin >> gx >> gy;
    int x, y; cin >> x >> y;
    string s; cin >> s;
    FOR(i, 0, sz(s)){
        char c = s[i];
        if(c=='S')x--;
        if(c=='R')x++;
        if(c=='Q')y++;
        if(c=='P')y--;
        x += gx; y += gy;
        x%=gx; y%=gy;
    }
    cout << x << " " << y << "\n";
}