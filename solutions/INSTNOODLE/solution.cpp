#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X stoves.
 * Each stove can cook 1 packet per minute.
 * In Y minutes, each stove can cook Y packets.
 * With X stoves, the total number of packets that can be cooked is X * Y.
 * Since each customer orders 1 packet, the total number of customers served is X * Y.
 * 
 * Constraints: 1 <= X, Y <= 1000.
 * The maximum possible value is 1000 * 1000 = 1,000,000, which fits in a standard 32-bit integer.
 * However, using long long is good practice to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    // The problem description implies a single test case per run based on the input format,
    // but we handle input reading as per standard competitive programming practices.
    if (cin >> X >> Y) {
        cout << (X * Y) << "\n";
    }

    return 0;
}