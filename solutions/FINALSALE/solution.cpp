#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        long long max_sales = 0;

        // Option 1: Don't double any day's sales.
        // This is equivalent to doubling the sales on a hypothetical day 0 with 0 sales.
        // The total sales would be the sum of all projected sales.
        long long current_sum = 0;
        for (long long sales : a) {
            current_sum += sales;
        }
        max_sales = current_sum;

        // Option 2: Double sales on day i and stop.
        // This means sales on day i become 2*A[i], and sales on days i+1 to N-1 are 0.
        // The total sales would be sum(A[0]...A[i-1]) + 2*A[i].
        // We can iterate through each day as the potential closing day.
        // To efficiently calculate sum(A[0]...A[i-1]), we can maintain a running sum.
        long long prefix_sum = 0;
        for (int i = 0; i < n; ++i) {
            // Sales if closing on day i: sum of sales from day 0 to i-1 + doubled sales on day i
            // The sum of sales from day 0 to i-1 is `prefix_sum`.
            // The doubled sales on day i is `2 * a[i]`.
            // Total sales = prefix_sum + 2 * a[i].
            max_sales = std::max(max_sales, prefix_sum + 2 * a[i]);
            prefix_sum += a[i];
        }

        std::cout << max_sales << "\n";
    }
    return 0;
}