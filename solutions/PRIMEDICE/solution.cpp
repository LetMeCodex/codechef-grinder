#include <iostream>
#include <vector>
#include <numeric>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int a, b;
        std::cin >> a >> b; // Read the dice rolls for Alice and Bob

        int sum = a + b; // Calculate the sum of the dice rolls

        // Check if the sum is a prime number
        if (isPrime(sum)) {
            std::cout << "Alice\n"; // Alice wins if the sum is prime
        } else {
            std::cout << "Bob\n"; // Bob wins otherwise
        }
    }

    return 0;
}