#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, K;
    cin >> X >> Y >> K;

    if (abs(X - Y) <= K) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}