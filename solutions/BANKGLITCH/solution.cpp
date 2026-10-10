#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, x, y;
        std::cin >> a >> b >> x >> y;

        // The problem states that 1 unit of currency 1 is worth 1 unit of currency 2 normally.
        // The glitch allows trading X units of currency 1 for Y units of currency 2, where X < Y.
        // This means for every X units of currency 1 spent, Chef gains Y units of currency 2.
        // The net gain in total value is Y - X.
        // Chef wants to maximize his total money, which is the sum of currency 1 and currency 2.
        // Since the trade is always beneficial (Y > X), Chef should make as many trades as possible.
        // The number of trades is limited by the amount of currency 1 he has.
        // He can make at most floor(A / X) trades.

        long long num_trades = a / x;
        
        // After making num_trades:
        // Currency 1 remaining = A - (num_trades * X)
        // Currency 2 gained = num_trades * Y
        // Total currency 2 = B + (num_trades * Y)
        
        // Total money = (Currency 1 remaining) + (Total currency 2)
        // Total money = (A - num_trades * X) + (B + num_trades * Y)
        // Total money = A + B + num_trades * (Y - X)

        long long max_money = a + b + num_trades * (y - x);
        
        std::cout << max_money << "\n";
    }
    return 0;
}