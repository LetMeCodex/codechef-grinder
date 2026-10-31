#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int d, x, y;
        std::cin >> d >> x >> y;

        // If Chef's budget is already enough for the membership, 0 sessions are needed.
        if (y >= x) {
            std::cout << 0 << "\n";
            continue;
        }

        // The maximum possible discount is 5% per session, and D is at most 5.
        // The maximum discount percentage is 5 * 5 = 25%.
        // If the initial budget Y is less than the minimum possible price of the membership
        // even with maximum discount, then it's impossible.
        // The minimum price is X * (100 - 5*D) / 100.
        // Since D <= 5, the maximum discount is 25%.
        // The minimum price is X * (100 - 25) / 100 = X * 0.75.
        // If Y < X * 0.75, it might be impossible.
        // More precisely, if Y is less than the price after maximum possible discount,
        // and Y is also less than the cost of trial sessions needed to reach that discount,
        // it's impossible.
        // The maximum discount is D * 5.
        // The price after maximum discount is X * (100 - D*5) / 100.
        // If Y < X * (100 - D*5) / 100, and Y is also less than the cost of 5 trial sessions (5 coins),
        // it's impossible.
        // However, the problem constraints are small (X, Y <= 50, D <= 5).
        // The maximum number of sessions we might need to consider is relatively small.
        // If Chef takes 's' sessions, he spends 's' coins and gets 's * D' percent discount.
        // The remaining budget is Y - s.
        // The membership cost becomes X * (100 - s * D) / 100.
        // We need Y - s >= X * (100 - s * D) / 100.
        // This can be rewritten as:
        // (Y - s) * 100 >= X * (100 - s * D)
        // 100*Y - 100*s >= 100*X - s*D*X
        // s*D*X - 100*s >= 100*X - 100*Y
        // s * (D*X - 100) >= 100 * (X - Y)

        // Case 1: D*X - 100 > 0 (i.e., D*X > 100)
        // This means the discount per session is large enough that the price reduction
        // can potentially overcome the cost of the session.
        // s >= 100 * (X - Y) / (D*X - 100)
        // Since s must be an integer, s = ceil(100 * (X - Y) / (D*X - 100))
        // However, the maximum discount is capped at 100%.
        // The effective discount percentage is min(s * D, 100).
        // The price becomes X * (100 - min(s * D, 100)) / 100.
        // We need Y - s >= X * (100 - min(s * D, 100)) / 100.

        // Given the constraints X <= 50, D <= 5, the maximum discount percentage
        // from sessions is D * 5 <= 25%. So the discount will never reach 100%.
        // The effective discount is always s * D.
        // We need Y - s >= X * (100 - s * D) / 100.
        // (Y - s) * 100 >= X * (100 - s * D)
        // 100*Y - 100*s >= 100*X - s*D*X
        // s*D*X - 100*s >= 100*X - 100*Y
        // s * (D*X - 100) >= 100 * (X - Y)

        // If D*X - 100 == 0, then 0 >= 100 * (X - Y). Since X > Y, X-Y > 0.
        // This means 0 >= positive number, which is impossible. So if D*X == 100 and X > Y, it's impossible.
        // If D*X - 100 < 0, then D*X < 100.
        // s * (negative number) >= positive number.
        // This implies s <= positive number / negative number, which means s <= negative number.
        // Since s must be non-negative, this is impossible.
        // So, if D*X <= 100 and X > Y, it's impossible.

        if (d * x <= 100) {
            // If D*X <= 100, the term (D*X - 100) is non-positive.
            // The inequality becomes s * (non-positive) >= 100 * (X - Y).
            // Since X > Y, 100 * (X - Y) is positive.
            // If D*X - 100 == 0, we have 0 >= positive, impossible.
            // If D*X - 100 < 0, we have s * (negative) >= positive. This requires s to be negative, which is impossible.
            // So, if D*X <= 100 and Y < X, it's impossible.
            std::cout << -1 << "\n";
            continue;
        }

        // Now we know D*X - 100 > 0.
        // s >= 100.0 * (x - y) / (d * x - 100.0)
        // We need to find the minimum integer s.
        // The number of trial sessions can be at most 100 because the maximum discount is 5% per session,
        // and the maximum X is 50. A 100% discount would mean X * (100-100)/100 = 0.
        // However, the problem states D*X > 100, so the discount percentage s*D will never reach 100%
        // if s is reasonably small.
        // Let's consider the maximum possible sessions needed.
        // If D=1, X=50, Y=1. We need s * (50 - 100) >= 100 * (50 - 1). This is impossible as 50-100 < 0.
        // If D=5, X=50, Y=1. We need s * (250 - 100) >= 100 * (50 - 1).
        // s * 150 >= 100 * 49
        // s >= (100 * 49) / 150 = 4900 / 150 = 490 / 15 = 98 / 3 = 32.66...
        // So s = 33.
        // Let's check s=33:
        // Cost of sessions = 33. Remaining budget = Y - 33 = 1 - 33 = -32. This is not how it works.
        // The budget Y is the initial budget. The cost of sessions is paid from this budget.
        // So, if Chef takes 's' sessions, he spends 's' coins. His remaining money is Y - s.
        // The membership cost is X * (100 - s * D) / 100.
        // We need Y - s >= X * (100 - s * D) / 100.
        // This is the correct formulation.

        // Let's iterate through possible number of sessions.
        // Since X, Y <= 50 and D <= 5, the maximum discount percentage is 5 * 5 = 25%.
        // The minimum price is X * (100 - 25) / 100 = X * 0.75.
        // If Y is less than this minimum price, and Y is also less than the cost of sessions
        // to achieve this discount, it might be impossible.
        // The cost of sessions to get 25% discount is 5 sessions.
        // If Y < X * 0.75 and Y < 5, it's impossible.
        // Example: D=5, X=40, Y=38.
        // s=0: Y=38, Price=40. Need 38 >= 40 (False)
        // s=1: Cost=1. Remaining budget = 38-1=37. Discount = 5%. Price = 40 * 0.95 = 38. Need 37 >= 38 (False)
        // s=2: Cost=2. Remaining budget = 38-2=36. Discount = 10%. Price = 40 * 0.90 = 36. Need 36 >= 36 (True). Min sessions = 2.

        // The maximum number of sessions we might need to consider.
        // If D=1, X=50, Y=1.
        // s=1: cost=1, budget=0. discount=1%. price=50*0.99=49.5. Need 0 >= 49.5 (False)
        // s=2: cost=2, budget=-1. This is not right. The budget Y is the total money Chef has.
        // The cost of sessions is paid from this budget.
        // So, if Chef takes 's' sessions, he spends 's' coins.
        // The total money he has available to pay for the membership is Y - s.
        // The membership cost is X * (100 - s * D) / 100.
        // We need Y - s >= X * (100 - s * D) / 100.
        // This implies Y - s must be non-negative. So s <= Y.
        // If s > Y, Chef cannot even afford the trial sessions.
        // So we only need to check s from 0 up to Y.
        // Since Y <= 50, we can iterate from s = 0 to 50.

        int min_sessions = -1;
        for (int s = 0; s <= 50; ++s) { // Iterate up to 50 sessions, as Y <= 50
            if (s > y) { // Chef cannot afford 's' trial sessions if s > Y
                break;
            }
            // Calculate the discounted price.
            // The discount percentage is s * D.
            // The price is X * (100 - s * D) / 100.
            // Using floating point for calculation might introduce precision issues.
            // Let's use integer arithmetic.
            // We need Y - s >= X * (100 - s * D) / 100
            // (Y - s) * 100 >= X * (100 - s * D)
            // (Y - s) * 100 >= 100 * X - s * D * X

            long long current_budget_after_sessions = (long long)y - s;
            long long membership_cost_numerator = (long long)x * (100 - s * d);

            // Check if current_budget_after_sessions * 100 >= membership_cost_numerator
            if (current_budget_after_sessions * 100 >= membership_cost_numerator) {
                min_sessions = s;
                break; // Found the minimum number of sessions
            }
        }
        std::cout << min_sessions << "\n";
    }
    return 0;
}