#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int reversed_n = 0;
        while (n > 0) {
            int digit = n % 10;
            reversed_n = reversed_n * 10 + digit;
            n /= 10;
        }
        cout << reversed_n << "\n";
    }

    return 0;
}