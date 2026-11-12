#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a % b == 0) {
            cout << 0 << "\n";
        } else {
            // Option 1: Chef gives marbles to friend
            // Chef wants to reach a state where chef_new % friend_new == 0
            // Let chef_new = a - x, friend_new = b + x
            // (a - x) % (b + x) == 0
            // The smallest positive x such that a - x is a multiple of b + x.
            // This means a - x = k * (b + x) for some integer k >= 1.
            // a - x = kb + kx
            // a - kb = x(1 + k)
            // x = (a - kb) / (1 + k)
            // We need x >= 1 and a - x >= 1 and b + x >= 1.
            // Since b >= 1, b + x >= 1 is guaranteed if x >= 0.
            // We need a - x >= 1, so x <= a - 1.
            // We need x >= 1.
            // The smallest number of marbles Chef can give is such that his new total is a multiple of his friend's new total.
            // The friend's total will be b + x. Chef's total will be a - x.
            // We want a - x = k * (b + x) for some integer k >= 1.
            // The smallest possible value for b + x is b + 1 (if x=1).
            // The largest possible value for b + x is a - 1 (if chef has 1 marble).
            // The target for Chef's marbles (a-x) must be a multiple of friend's marbles (b+x).
            // The smallest possible value for friend's marbles is b+1 (if chef gives 1 marble).
            // The largest possible value for friend's marbles is a-1 (if chef has 1 marble).
            // The smallest possible value for chef's marbles is 1.
            // The largest possible value for chef's marbles is a-1.
            //
            // Let's consider the target state: Chef has C marbles, Friend has F marbles.
            // C % F == 0, C >= 1, F >= 1.
            // Total marbles = A + B. So C + F = A + B.
            // We want to minimize |A - C| (marbles transferred).
            //
            // Case 1: Chef gives x marbles to Friend.
            // New state: Chef has A - x, Friend has B + x.
            // We need (A - x) % (B + x) == 0, and A - x >= 1, B + x >= 1.
            // Since B >= 1, B + x >= 1 is true if x >= 0.
            // We need A - x >= 1, so x <= A - 1.
            // We need x >= 1 for transfer.
            // So, 1 <= x <= A - 1.
            // Let A - x = k * (B + x) for some integer k >= 1.
            // A - x = kB + kx
            // A - kB = x(1 + k)
            // x = (A - kB) / (1 + k)
            // We need to find the minimum x >= 1 such that A - x is a multiple of B + x.
            // The smallest possible value for B + x is B + 1.
            // The largest possible value for B + x is A - 1.
            //
            // Let's iterate through possible values of friend's new marble count (F).
            // F must be at least B + 1 (if Chef gives 1 marble).
            // F can be at most A - 1 (if Chef has 1 marble).
            // For each F, the Chef's new marble count C must be a multiple of F.
            // C + F = A + B. So C = A + B - F.
            // We need (A + B - F) % F == 0.
            // This simplifies to (A + B) % F == 0.
            // So, F must be a divisor of A + B.
            // Also, we need C >= 1, so A + B - F >= 1, which means F <= A + B - 1.
            // And we need F >= 1.
            // The number of marbles transferred is |A - C| = |A - (A + B - F)| = |F - B|.
            // We want to minimize |F - B| such that F is a divisor of A + B, and 1 <= F <= A + B - 1.
            //
            // The possible values for F are divisors of A + B.
            // We are looking for a divisor F of A + B such that F >= 1 and F <= A + B - 1.
            // The number of marbles transferred is |F - B|.
            // We want to minimize this value.
            //
            // Let's consider the target state: Chef has C, Friend has F. C+F = A+B. C%F == 0. C>=1, F>=1.
            //
            // Option 1: Chef gives marbles to Friend.
            // Chef's new count C = A - x, Friend's new count F = B + x.
            // C % F == 0. C >= 1, F >= 1. x >= 1.
            // C + F = A + B.
            // We want to minimize x.
            // This means we want to minimize F - B (since F = B + x).
            // So we want to find the smallest F > B such that F is a divisor of A + B.
            // If such F exists, then C = A + B - F.
            // We need C >= 1, so A + B - F >= 1, which means F <= A + B - 1.
            // If we find a divisor F of A + B such that F > B and F <= A + B - 1,
            // then the number of marbles transferred is F - B.
            //
            // Option 2: Friend gives marbles to Chef.
            // Chef's new count C = A + x, Friend's new count F = B - x.
            // C % F == 0. C >= 1, F >= 1. x >= 1.
            // C + F = A + B.
            // We want to minimize x.
            // This means we want to minimize B - F (since F = B - x).
            // So we want to find the largest F < B such that F is a divisor of A + B.
            // If such F exists, then C = A + B - F.
            // We need C >= 1, so A + B - F >= 1, which means F <= A + B - 1.
            // We need F >= 1.
            // If we find a divisor F of A + B such that F < B and F >= 1,
            // then the number of marbles transferred is B - F.
            //
            // So, we need to find divisors F of A + B.
            // For each divisor F, we check if it's valid (F >= 1 and C = A + B - F >= 1).
            // If valid, the cost is |F - B|. We want to minimize this cost.
            //
            // Let S = A + B.
            // We need to find divisors F of S.
            // For each divisor F, the number of marbles transferred is |F - B|.
            // We need to find min(|F - B|) over all divisors F of S, such that F >= 1 and S - F >= 1.
            // The condition S - F >= 1 means F <= S - 1.
            // So we need min(|F - B|) over all divisors F of S, such that 1 <= F <= S - 1.
            //
            // Example 1: A=7, B=2. S = 9. Divisors of 9 are 1, 3, 9.
            // Valid F: 1, 3 (since F <= S-1 = 8).
            // If F=1: cost = |1 - 2| = 1. Chef has 9-1=8. Friend has 1. 8%1==0. Valid.
            // If F=3: cost = |3 - 2| = 1. Chef has 9-3=6. Friend has 3. 6%3==0. Valid.
            // Minimum cost = 1.

            // Example 3: A=6, B=5. S = 11. Divisors of 11 are 1, 11.
            // Valid F: 1 (since F <= S-1 = 10).
            // If F=1: cost = |1 - 5| = 4. Chef has 11-1=10. Friend has 1. 10%1==0. Valid.
            // Minimum cost = 4.

            // Example 4: A=5, B=6. S = 11. Divisors of 11 are 1, 11.
            // Valid F: 1 (since F <= S-1 = 10).
            // If F=1: cost = |1 - 6| = 5. Chef has 11-1=10. Friend has 1. 10%1==0. Valid.
            // Minimum cost = 5.

            int total_marbles = a + b;
            int min_transfers = INT_MAX;

            // Iterate through all possible divisors of total_marbles
            for (int f = 1; f * f <= total_marbles; ++f) {
                if (total_marbles % f == 0) {
                    // f is a divisor
                    int divisor1 = f;
                    int divisor2 = total_marbles / f;

                    // Check divisor1
                    // Friend's new count is divisor1. Chef's new count is total_marbles - divisor1.
                    // Conditions: divisor1 >= 1 and total_marbles - divisor1 >= 1.
                    // The second condition means divisor1 <= total_marbles - 1.
                    if (divisor1 >= 1 && divisor1 <= total_marbles - 1) {
                        min_transfers = min(min_transfers, abs(divisor1 - b));
                    }

                    // Check divisor2
                    // Friend's new count is divisor2. Chef's new count is total_marbles - divisor2.
                    // Conditions: divisor2 >= 1 and total_marbles - divisor2 >= 1.
                    // The second condition means divisor2 <= total_marbles - 1.
                    if (divisor2 >= 1 && divisor2 <= total_marbles - 1) {
                        min_transfers = min(min_transfers, abs(divisor2 - b));
                    }
                }
            }
            cout << min_transfers << "\n";
        }
    }
    return 0;
}