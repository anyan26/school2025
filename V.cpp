#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> tree {{-1, -1}};
unordered_map<int,char> vals;

void addto(string s, char e) {
    int v = 0;
    for (char c : s) {
        int ii = c - '0';
        if (tree[v][ii] == -1) {
            tree[v][ii] = tree.size();
            tree.push_back({-1, -1});
        }
        v = tree[v][ii];
    }
    vals[v] = e;
}

void solve() {
    int n;
    cin >> n;
    bool arr[n];
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        arr[i] = a <= 127;
    }
    string res = "";
    int v = 0;
    for (int i = 0; i < n; ++i) {
        v = tree[v][arr[i]];
        if (v < 0) {
            cout << "INVALID" << endl;
            return;
        }
        if (vals.count(v)) {
            res += (char)vals[v];
            v = 0;
        }
    }
    // cout << res << endl;
    if (v != 7 || res.size() < 2 || res[0] != 's') {
        cout << "INVALID" << endl;
        return;
    }
    for (int i = 1; i < res.size() - 1; ++i) {
        if (res[i] == 's') {
            cout << "INVALID" << endl;
            return;
        }
    }
    cout << res.substr(1) << endl;
}

int main() {
    addto("10110010", 's');
    addto("1010110", '0');
    addto("11010110", '1');
    addto("10010110", '2');
    addto("11001010", '3');
    addto("10110110", '4');
    addto("11011010", '5');
    addto("10011010", '6');
    addto("10100110", '7');
    addto("11010010", '8');
    addto("1101010", '9');
    addto("1011010", '-');
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}