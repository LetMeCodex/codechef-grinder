#include <iostream>
#include <algorithm> // Required for std::min

void solve() {
    long long x, y, z, a, b, c;
    // Read the six integers for the current test case
    std::cin >> x >> y >> z >> a >> b >> c;

    long long happy_people = 0;

    // Strategy:
    // 1. Satisfy direct matches first.
    // 2. Then, use conversions from larger shirts to smaller ones.
    //    Prioritize using more flexible shirts (XL, then L) for remaining needs,
    //    and for conversions, prioritize larger target sizes (L before S).

    // Step 1: Satisfy people with shirts of their exact desired size.

    // Satisfy 'A' people (who want Small) with 'X' Small shirts.
    long long s_match = std::min(x, a);
    happy_people += s_match;
    x -= s_match; // Remaining Small shirts
    a -= s_match; // Remaining people who want Small

    // Satisfy 'B' people (who want Large) with 'Y' Large shirts.
    long long l_match = std::min(y, b);
    happy_people += l_match;
    y -= l_match; // Remaining Large shirts
    b -= l_match; // Remaining people who want Large

    // Satisfy 'C' people (who want Extra Large) with 'Z' Extra Large shirts.
    long long xl_match = std::min(z, c);
    happy_people += xl_match;
    z -= xl_match; // Remaining Extra Large shirts
    c -= xl_match; // Remaining people who want Extra Large (should be 0 here)

    // Step 2: Use conversions to satisfy remaining people.

    // Convert remaining XL shirts to L for remaining 'B' people.
    long long xl_to_l = std::min(z, b);
    happy_people += xl_to_l;
    z -= xl_to_l; // XL shirts used for L
    b -= xl_to_l; // Remaining people who want Large

    // Convert remaining XL shirts to S for remaining 'A' people.
    long long xl_to_s = std::min(z, a);
    happy_people += xl_to_s;
    z -= xl_to_s; // XL shirts used for S
    a -= xl_to_s; // Remaining people who want Small

    // Convert remaining L shirts to S for remaining 'A' people.
    long long l_to_s = std::min(y, a);
    happy_people += l_to_s;
    y -= l_to_s; // L shirts used for S
    a -= l_to_s; // Remaining people who want Small

    // Output the maximum number of happy people for this test case.
    std::cout << happy_people << "\n"; // Use '\n' for faster output than std::endl
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for problems with many test cases or large I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Process each test case
    }

    return 0;
}