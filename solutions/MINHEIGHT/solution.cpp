#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int x, h;
        cin >> x >> h;
        if (x >= h) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}