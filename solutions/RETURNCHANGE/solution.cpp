#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        int rounded_cost;
        int remainder = x % 10;

        if (remainder == 0) {
            rounded_cost = x;
        } else {
            int lower_multiple = x - remainder;
            int upper_multiple = lower_multiple + 10;

            if (remainder < 5) {
                rounded_cost = lower_multiple;
            } else { // remainder >= 5, round up
                rounded_cost = upper_multiple;
            }
        }
        
        // Special case: if x is a multiple of 10, it's already rounded.
        // The logic above handles this correctly, but let's be explicit.
        // If x is already a multiple of 10, remainder is 0, rounded_cost = x.
        // If x is not a multiple of 10, we calculate the nearest multiple.
        // The problem states "cost not a multiple of 10, then, he will be charged the cost that is the nearest multiple of 10".
        // If x is already a multiple of 10, it is its own nearest multiple.
        // The logic `if (remainder == 0) rounded_cost = x;` handles this.
        // The problem statement also says "If the cost is equally distant from two nearest multiples of 10, then the cost is rounded up."
        // This applies to numbers ending in 5. For example, 35 is equally distant from 30 and 40. It rounds up to 40.
        // Our logic `if (remainder < 5)` correctly handles this:
        // if remainder is 1, 2, 3, 4, it rounds down.
        // if remainder is 5, 6, 7, 8, 9, it rounds up.

        cout << 100 - rounded_cost << "\n";
    }
    return 0;
}