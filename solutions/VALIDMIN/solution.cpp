#include <iostream> // Required for standard input/output operations (cin, cout)

void solve() {
    int x, y, z;
    // Read the three given minimum values
    std::cin >> x >> y >> z;

    // The logic checks if the set of given minimums {x, y, z} is of the form {K, K, L} where K <= L.
    // This is equivalent to checking if, after sorting the three values, the two smallest are equal.
    //
    // For example:
    // - If x=y=z (e.g., 5 5 5), then (5==5 && 5<=5) is true. A valid tuple is (5, 5, 5).
    // - If x=y < z (e.g., 2 2 4), then (2==2 && 2<=4) is true. A valid tuple is (4, 2, 4).
    // - If y=z < x (e.g., 5 3 3), then (3==3 && 3<=5) is true. A valid tuple is (5, 5, 3).
    // - If x=z < y (e.g., 3 5 3), then (3==3 && 3<=5) is true. A valid tuple is (5, 3, 5).
    //
    // If all three are distinct (e.g., 2 3 4), none of these conditions will be met, and it's impossible.
    // If two are equal but the third is smaller (e.g., x=3, y=5, z=5), this is also impossible
    // (as min(B,C)=5, min(C,A)=5 implies A,B,C >= 5, which means min(A,B) must be >= 5,
    // contradicting min(A,B)=3).
    //
    // The conditions correctly cover all valid scenarios and reject all impossible ones.
    if ((x == y && x <= z) || 
        (y == z && y <= x) || 
        (x == z && x <= y)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming and ensures I/O is not a bottleneck.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    // Read the number of test cases
    std::cin >> t;
    // Loop through each test case
    while (t--) {
        solve();
    }

    return 0;
}