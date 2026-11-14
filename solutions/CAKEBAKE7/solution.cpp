#include <bits/stdc++.h> // Required by problem statement for common headers

// Required by problem statement to avoid std:: prefix
using namespace std;

int main() {
    // Enable fast I/O as required by problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // As per the problem-specific "Input Format":
    // "The first and only line of each test case contains 2 integers - N and M."
    // This implies a single test case, as no 'T' (number of test cases) is mentioned.
    // The general instruction about handling multiple test cases is a guideline for problems
    // that explicitly specify 'T' in their input format.

    int N, M;
    // Read the number of customers (N) and cakes (M)
    cin >> N >> M;

    // Logic to calculate maximum happy customers:
    // 1. To ensure no customer is unhappy, each of the N customers must receive at least 1 cake.
    //    This uses N cakes.
    // 2. The number of cakes remaining for additional distribution is M - N.
    // 3. Each of these remaining cakes can make one customer happy (by giving them an additional cake,
    //    bringing their total to 2). So, we can make at most (M - N) customers happy this way.
    // 4. However, we cannot make more customers happy than the total number of customers available, which is N.
    // 5. Therefore, the maximum number of happy customers is the minimum of (N) and (M - N).

    int happy_customers = min(N, M - N);

    // Output the result followed by a newline character
    cout << happy_customers << "\n";

    return 0;
}