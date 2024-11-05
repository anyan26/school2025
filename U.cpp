#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i]--;
    }
    long long res = 1;
    bool trav[n];
    fill(trav, trav + n, false);
    for (int s = 0; s < n; ++s) {
        if (trav[s]) continue;
        long long c = 0;
        for (int i = s; !trav[i]; i = arr[i]) {
            trav[i] = true;
            c++;
        }
        res = lcm(res, c);
    }
    cout << res - 1 << endl;

    return 0;
}