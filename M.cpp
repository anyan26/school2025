#include <iostream>
#include <set>

using namespace std;

void solve(int t) {
    int n;
    cin >> n;
    int meds[n];
    for (int i = 0; i < n; ++i) cin >> meds[i];
    int cl = -2e9, cr = 2e9;
    set<int> s;
    cout << meds[0] / 2 << ' ';
    s.insert(meds[0] / 2);
    for (int i = 1; i < n; ++i) {
        int r = 0;
        if (i % 2 == 0) {
            r = meds[i] / 2;
        } else {
            r = meds[i] - meds[i-1] / 2;
        }
        if (s.count(r)) {
            if (meds[i] > meds[i-1]) {
                r = cr--;
            } else {
                r = cl++;
            }
        }
        cout << r << ' ';
        s.insert(r);
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve(t);

    return 0;
}