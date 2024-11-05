#include <iostream>
#include <cstdint>

const int MAX_N = 100001;

using namespace std;

int n;
const int lb = 262144 / 2, lb2 = 262144;
long long arr[MAX_N];
long long mins[lb2];

long long query(int i, int l, int r, int sz) {
    if (l >= sz || r <= 0) return INT64_MAX;
    if (l <= 0 && r >= sz) return mins[i];
    return min(query(i * 2, l, r, sz / 2), query(i * 2 + 1, l - sz / 2, r - sz / 2, sz / 2));
}

int main() {
    int ql;
    cin >> n >> ql;
    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        long long a;
        cin >> a;
        arr[i] = arr[i-1] + a;
    }
    n++;
    copy(arr, arr + n, mins + lb);
    fill(mins + (lb + n), mins + lb2, 0);
    for (int i = lb - 1; i > 0; --i) mins[i] = min(mins[i * 2], mins[i * 2 + 1]);

    for (int qi = 0; qi < ql; ++qi) {
        int l, r;
        cin >> l >> r;
        long long minv = query(1, l, r, lb);
        if (arr[l] != arr[r] || minv < arr[l]) {
            cout << "NO" << endl;
            continue;
        } else {
            cout << "MAYBE" << endl;
        }
    }

    return 0;
}