#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H;
    cin >> H;

    if (H < 8) {
        cout << "LESS\n";
    } else if (H == 8) {
        cout << "PERFECT\n";
    } else { // H > 8
        cout << "MORE\n";
    }

    return 0;
}