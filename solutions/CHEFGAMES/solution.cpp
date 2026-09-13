#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int r1, r2, r3, r4;
        cin >> r1 >> r2 >> r3 >> r4;
        if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0) {
            cout << "IN\n";
        } else {
            cout << "OUT\n";
        }
    }
    return 0;
}