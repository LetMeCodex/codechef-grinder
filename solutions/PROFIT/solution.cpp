#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, x;
        std::cin >> n >> x;
        
        // The i-th customer is willing to pay Rs. i.
        // Chef's cost to make one lemonade is Rs. X.
        // Chef can only make a profit if the customer pays more than or equal to the cost.
        // So, Chef will only consider customers willing to pay at least X.
        // These are customers from index X to N (inclusive).
        // The i-th customer pays Rs. i.
        // If Chef accepts customer i, the profit from this customer is i - X.
        // To maximize profit, Chef should accept all customers from X to N,
        // as long as X <= N. If X > N, no customer is willing to pay at least X.
        
        long long max_profit = 0;
        
        // Iterate through customers who are willing to pay at least X.
        // These are customers with willingness to pay from X up to N.
        // The customer index is 1-based, and willingness to pay is equal to the index.
        // So, customers from index X to N are relevant.
        for (long long i = x; i <= n; ++i) {
            // If the customer is willing to pay at least X, Chef can make a profit.
            // The profit from this customer is i - X.
            // We sum up the profits from all such customers.
            max_profit += (i - x);
        }
        
        std::cout << max_profit << "\n";
    }
    return 0;
}