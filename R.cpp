#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    int a = 1, b = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            {
                int k = n - i;
                while (k % 3 == 0) {
                    k /= 3;
                    b++;
                }
                a = a * k % 3;
            }
            {
                int k = i;
                while (k % 3 == 0) {
                    k /= 3;
                    b--;
                }
                a = a * k % 3;
            }
        }
        int cv = s[i] == 'B' ? 0 : s[i] == 'R' ? 1 : 2;
        if (b == 0) {
            res += a * cv;
        }
        res %= 3;
    }
    if (n % 2 == 0) res = (-res + 3) % 3;
    cout << "BRG"[res];
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    cout << endl;

    return 0;
}