#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    int xl, yl;
    cin >> xl >> yl;
    long long dp[xl][yl][5], dpmintl[xl][yl][5], dpminbl[xl][yl][5];
    for (int x = 0; x < xl; ++x) {
        for (int y = 0; y < yl; ++y) {
            cin >> dp[x][y][0];
            if (dp[x][y][0] == -1) dp[x][y][0] = INT64_MAX / 6;
        }
    }
    for (int y = 0; y < yl; ++y) {
        for (int x = 0; x < xl; ++x) {
            dpmintl[x][y][0] = dp[x][y][0];
            if (x > 0) dpmintl[x][y][0] = min(dpmintl[x][y][0], dpmintl[x-1][y][0]);
            if (y > 0) dpmintl[x][y][0] = min(dpmintl[x][y][0], dpmintl[x][y-1][0]);
        }
    }
    for (int x = xl - 1; x >= 0; --x) {
        for (int y = 0; y < yl; ++y) {
            dpminbl[x][y][0] = dp[x][y][0];
            if (x < xl - 1) dpminbl[x][y][0] = min(dpminbl[x][y][0], dpminbl[x+1][y][0]);
            if (y > 0) dpminbl[x][y][0] = min(dpminbl[x][y][0], dpminbl[x][y-1][0]);
        }
    }

    for (int i = 1; i < 5; ++i) {
        for (int x = 0; x < xl; ++x) {
            for (int y = 0; y < yl; ++y) {
                if (i % 2 == 1) {
                    dp[x][y][i] = (x > 0 && y > 0) ? (dpmintl[x-1][y-1][i-1] + dp[x][y][0]) : INT64_MAX / 6;
                } else {
                    dp[x][y][i] = (x < xl - 1 && y > 0) ? (dpminbl[x+1][y-1][i-1] + dp[x][y][0]) : INT64_MAX / 6;
                }
            }
        }
        for (int x = 0; x < xl; ++x) {
            for (int y = 0; y < yl; ++y) {
                dpmintl[x][y][i] = dp[x][y][i];
                if (x > 0) dpmintl[x][y][i] = min(dpmintl[x][y][i], dpmintl[x-1][y][i]);
                if (y > 0) dpmintl[x][y][i] = min(dpmintl[x][y][i], dpmintl[x][y-1][i]);
            }
        }
        for (int x = xl - 1; x >= 0; --x) {
            for (int y = 0; y < yl; ++y) {
                dpminbl[x][y][i] = dp[x][y][i];
                if (x < xl - 1) dpminbl[x][y][i] = min(dpminbl[x][y][i], dpminbl[x+1][y][i]);
                if (y > 0) dpminbl[x][y][i] = min(dpminbl[x][y][i], dpminbl[x][y-1][i]);
            }
        }
    }
    
    // for (int i = 1; i < 5; ++i) {
    //     for (int x = 0; x < xl; ++x) {
    //         for (int y = 0; y < yl; ++y) {
    //             cout << dp[x][y][i] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    long long res = INT64_MAX;
    for (int x = 0; x < xl; ++x) {
        for (int y = 0; y < yl; ++y) {
            res = min(res, dp[x][y][4]);
        }
    }
    cout << (res >= INT64_MAX / 6 ? -1 : res) << endl;

    return 0;
}