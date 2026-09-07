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

        // The last digit is simply n % 10
        int last_digit = n % 10;

        // To get the first digit, we repeatedly divide n by 10
        // until it becomes a single digit number.
        int first_digit = n;
        while (first_digit >= 10) {
            first_digit /= 10;
        }

        cout << first_digit + last_digit << "\n";
    }

    return 0;
}