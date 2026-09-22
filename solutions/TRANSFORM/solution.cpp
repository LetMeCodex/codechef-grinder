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

        // Mario's initial size is 'normal'.
        // The transformations cycle through: normal -> huge -> small -> normal ...
        // This is a cycle of length 3.
        // We can represent the states numerically:
        // normal: 0
        // huge: 1
        // small: 2
        //
        // Initial state: normal (0)
        // After 1 mushroom: huge (1)
        // After 2 mushrooms: small (2)
        // After 3 mushrooms: normal (0)
        // After 4 mushrooms: huge (1)
        //
        // The state after X mushrooms is (initial_state + X) mod 3.
        // Since initial_state is normal (0), the state is X mod 3.

        int final_state = x % 3;

        if (final_state == 0) {
            cout << "NORMAL\n";
        } else if (final_state == 1) {
            cout << "HUGE\n";
        } else { // final_state == 2
            cout << "SMALL\n";
        }
    }
    return 0;
}