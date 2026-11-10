#include <iostream>
#include <numeric>

// Function to compute GCD
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// Function to compute LCM
long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return std::abs(a * b) / gcd(a, b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, n;
        std::cin >> a >> b >> n;

        // We are looking for the smallest number X such that:
        // 1. X >= n
        // 2. X is divisible by a (X % a == 0)
        // 3. X is NOT divisible by b (X % b != 0)

        // First, find the smallest multiple of 'a' that is >= 'n'.
        // If n is already a multiple of a, then start_candidate = n.
        // Otherwise, start_candidate = n + (a - (n % a)) % a.
        // A simpler way is to calculate ceil(n/a) * a.
        // Using integer division: (n + a - 1) / a * a
        long long start_candidate;
        if (n % a == 0) {
            start_candidate = n;
        } else {
            start_candidate = (n / a + 1) * a;
        }

        // Now, we need to check multiples of 'a' starting from start_candidate.
        // The numbers we are interested in are of the form k * a, where k * a >= n.
        // We want k * a % b != 0.

        // Case 1: If 'a' is a multiple of 'b' (i.e., b divides a).
        // This means any multiple of 'a' is also a multiple of 'b'.
        // If a % b == 0, then any number divisible by 'a' is also divisible by 'b'.
        // In this case, no number can satisfy both conditions (divisible by 'a' AND not divisible by 'b').
        // So, if a % b == 0, the answer is -1.
        if (a % b == 0) {
            std::cout << -1 << "\n";
            continue;
        }

        // Case 2: If 'a' is not a multiple of 'b'.
        // We are looking for the smallest multiple of 'a', say `multiple_of_a`, such that `multiple_of_a >= n`
        // and `multiple_of_a % b != 0`.

        // We already found the smallest multiple of 'a' that is >= n, which is `start_candidate`.
        // Let's check if `start_candidate` satisfies the condition `start_candidate % b != 0`.
        if (start_candidate % b != 0) {
            std::cout << start_candidate << "\n";
        } else {
            // If `start_candidate` is divisible by 'b', we need to find the next multiple of 'a'
            // that is not divisible by 'b'.
            // The numbers we are checking are `start_candidate`, `start_candidate + a`, `start_candidate + 2*a`, ...
            // We know `start_candidate` is divisible by `a` and `b`.
            // This means `start_candidate` is a multiple of `lcm(a, b)`.
            // The next multiple of `a` is `start_candidate + a`.
            // The next multiple of `a` after that is `start_candidate + 2*a`, and so on.

            // We are looking for the smallest `k >= 0` such that `(start_candidate + k * a) % b != 0`.
            // Since `start_candidate % b == 0`, we are looking for the smallest `k >= 0` such that `(k * a) % b != 0`.
            // This is equivalent to finding the smallest `k >= 0` such that `k * a` is not a multiple of `b`.

            // Consider the sequence of multiples of 'a': a, 2a, 3a, ...
            // We are interested in their remainders when divided by 'b'.
            // The sequence of remainders is (a % b), (2a % b), (3a % b), ...
            // This sequence is periodic. The length of the period is related to b / gcd(a, b).
            // Specifically, the sequence `(k * a) % b` for `k = 0, 1, 2, ...` will eventually repeat.
            // The values `k * a` that are divisible by `b` are precisely the multiples of `lcm(a, b)`.
            // So, `k * a` is divisible by `b` if and only if `k * a` is a multiple of `lcm(a, b)`.
            // This means `k` must be a multiple of `lcm(a, b) / a`.
            // Let `L = lcm(a, b)`. Then `k * a` is divisible by `b` iff `k * a` is a multiple of `L`.
            // This implies `k` must be a multiple of `L / a`.
            // `L / a = (a * b / gcd(a, b)) / a = b / gcd(a, b)`.
            // So, `k * a` is divisible by `b` iff `k` is a multiple of `b / gcd(a, b)`.

            // We are in the case where `start_candidate` is divisible by `b`.
            // This means `start_candidate = m * a` for some `m`, and `m * a` is divisible by `b`.
            // This implies `m` is a multiple of `b / gcd(a, b)`.
            // The next multiple of `a` is `start_candidate + a`.
            // The next one is `start_candidate + 2*a`, and so on.
            // We are looking for the smallest `k >= 1` such that `(start_candidate + k * a) % b != 0`.
            // Since `start_candidate % b == 0`, this is equivalent to finding the smallest `k >= 1` such that `(k * a) % b != 0`.

            // The numbers `k * a` that are divisible by `b` occur when `k` is a multiple of `b / gcd(a, b)`.
            // Let `period_multiplier = b / gcd(a, b)`.
            // So, `k * a` is divisible by `b` if `k` is `0, period_multiplier, 2 * period_multiplier, ...`
            // We are looking for the smallest `k >= 1` such that `k` is NOT a multiple of `period_multiplier`.
            // The smallest such `k` is `1`, provided `period_multiplier > 1`.
            // If `period_multiplier == 1`, it means `b / gcd(a, b) == 1`, which implies `b == gcd(a, b)`.
            // This means `b` divides `a`. But we already handled this case (`a % b == 0` leads to -1).
            // So, if we reach here, `a % b != 0`, which implies `b` does not divide `a`.
            // Therefore, `gcd(a, b) < b`, so `b / gcd(a, b) > 1`.
            // This means `period_multiplier > 1`.
            // The smallest `k >= 1` that is NOT a multiple of `period_multiplier` is `k = 1`.
            // So, `1 * a` is not divisible by `b` if `1` is not a multiple of `period_multiplier`.
            // Since `period_multiplier > 1`, `1` is indeed not a multiple of `period_multiplier`.
            // Thus, `a` itself is not divisible by `b`.

            // Let's re-evaluate.
            // We have `start_candidate` which is a multiple of `a` and `start_candidate >= n`.
            // We found `start_candidate % b == 0`.
            // We need the smallest number `X >= n` such that `X % a == 0` and `X % b != 0`.
            // The candidates are `start_candidate`, `start_candidate + a`, `start_candidate + 2*a`, ...
            // We know `start_candidate` is bad.
            // Consider `start_candidate + a`.
            // If `(start_candidate + a) % b != 0`, then `start_candidate + a` is our answer.
            // If `(start_candidate + a) % b == 0`, then we need to check `start_candidate + 2*a`.
            // And so on.

            // The condition `(start_candidate + k * a) % b == 0` is equivalent to
            // `(k * a) % b == 0` (since `start_candidate % b == 0`).
            // This happens when `k * a` is a multiple of `lcm(a, b)`.
            // This means `k` must be a multiple of `lcm(a, b) / a = b / gcd(a, b)`.
            // Let `P = b / gcd(a, b)`.
            // So, `start_candidate + k * a` is divisible by `b` if and only if `k` is a multiple of `P`.
            // We are looking for the smallest `k >= 0` such that `start_candidate + k * a` is NOT divisible by `b`.
            // This means we need the smallest `k >= 0` such that `k` is NOT a multiple of `P`.
            // Since `start_candidate` is divisible by `b`, we need `k >= 1` to get a new candidate.
            // The smallest `k >= 1` that is NOT a multiple of `P` is `k = 1`, because `P = b / gcd(a, b)`.
            // Since `a % b != 0`, `b` does not divide `a`. Thus `gcd(a, b) < b`.
            // So `P = b / gcd(a, b) > 1`.
            // Therefore, `k = 1` is not a multiple of `P`.
            // This means `start_candidate + 1 * a` is NOT divisible by `b`.
            // So, `start_candidate + a` is the smallest number greater than `start_candidate` that is divisible by `a`.
            // And since `start_candidate % b == 0`, and `a % b != 0` (because `a % b == 0` case is handled),
            // `(start_candidate + a) % b` will be `(0 + a % b) % b = a % b`.
            // Since `a % b != 0`, `(start_candidate + a) % b != 0`.
            // So, `start_candidate + a` is the answer.

            std::cout << start_candidate + a << "\n";
        }
    }
    return 0;
}