#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    if (x + y >= 2000) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}