#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int left_count = 0;
        int right_count = 0;
        if (a == 0) {
            left_count++;
        } else {
            right_count++;
        }
        if (b == 0) {
            left_count++;
        } else {
            right_count++;
        }
        if (c == 0) {
            left_count++;
        } else {
            right_count++;
        }

        if (left_count >= 1 && right_count >= 1) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}