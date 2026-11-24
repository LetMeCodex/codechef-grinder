#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int odd_count = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            std::cin >> a;
            if (a % 2 != 0) {
                odd_count++;
            }
        }

        // The parity of the sum depends on the number of odd numbers and the signs assigned to them.
        // Even numbers do not affect the parity of the sum, regardless of their sign.
        // Let S be the final sum. S = sum(sign_i * A_i).
        // S mod 2 = (sum(sign_i * (A_i mod 2))) mod 2.
        // This simplifies to S mod 2 = (sum(sign_i * (A_i mod 2))) mod 2, where A_i mod 2 is 0 or 1.
        // So, S mod 2 = (sum of signs for odd numbers) mod 2.

        // Player 1 wins if the sum is even. Player 2 wins if the sum is odd.
        // Player 1 wants to make the sum even. Player 2 wants to make the sum odd.
        // They take turns assigning signs.

        // Consider the odd numbers. There are 'odd_count' odd numbers.
        // Each odd number can be assigned a + or - sign.
        // The sum of signs for these odd numbers determines the parity of the total sum.
        // Let k be the number of odd numbers assigned a '+' sign.
        // Then (odd_count - k) odd numbers are assigned a '-' sign.
        // The contribution of odd numbers to the sum's parity is (k * 1 + (odd_count - k) * (-1)) mod 2.
        // This is (k - odd_count + k) mod 2 = (2k - odd_count) mod 2 = (-odd_count) mod 2 = odd_count mod 2.
        // So, the parity of the final sum is determined solely by the parity of 'odd_count'.

        // If 'odd_count' is even, the sum of signs for odd numbers will always be even, regardless of how signs are assigned.
        // For example, if odd_count = 2, we can have (+1) + (+1) = 2 (even), (+1) + (-1) = 0 (even), (-1) + (-1) = -2 (even).
        // If 'odd_count' is odd, the sum of signs for odd numbers will always be odd.
        // For example, if odd_count = 3, we can have (+1) + (+1) + (+1) = 3 (odd), (+1) + (+1) + (-1) = 1 (odd), (+1) + (-1) + (-1) = -1 (odd), (-1) + (-1) + (-1) = -3 (odd).

        // The players take turns assigning signs.
        // If 'odd_count' is even:
        // The final sum will always be even. Player 1 wins.
        // Player 1 can always ensure the sum is even. Player 2 cannot force it to be odd.
        // If 'odd_count' is odd:
        // The final sum will always be odd. Player 2 wins.
        // Player 2 can always ensure the sum is odd. Player 1 cannot force it to be even.

        // The number of turns is N.
        // Player 1 makes ceil(N/2) moves. Player 2 makes floor(N/2) moves.
        // However, the parity of the sum is independent of who assigns which sign to which odd number.
        // The crucial observation is that the parity of the sum is determined by the parity of the count of odd numbers.
        // If odd_count is even, the sum will be even. Player 1 wins.
        // If odd_count is odd, the sum will be odd. Player 2 wins.

        if (odd_count % 2 == 0) {
            std::cout << "1\n";
        } else {
            std::cout << "2\n";
        }
    }
    return 0;
}