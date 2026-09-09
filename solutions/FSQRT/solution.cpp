#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        // The problem statement guarantees N >= 1.
        // We need to find the integer part of the square root.
        // The sqrt function from cmath returns a double.
        // Casting to long long will truncate the decimal part,
        // effectively rounding down.
        long long result = sqrt(n);
        cout << result << "\n";
    }

    return 0;
}