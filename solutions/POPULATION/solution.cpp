#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        // The final population is the initial population minus those who left,
        // plus those who immigrated.
        // Since X, Y, Z are up to 10, and T is up to 100, the maximum possible
        // final population would be around 100 * (10 - 1 + 10) = 1900.
        // A standard int can hold this, but using long long is a good practice
        // for competitive programming to avoid potential overflow issues,
        // especially if constraints were slightly larger.
        long long final_population = x - y + z;
        cout << final_population << "\n";
    }

    return 0;
}