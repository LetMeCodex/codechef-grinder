# Naive Chef (NAICHEF)
- **Difficulty Rating**: 990
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to calculate the probability that if we roll a special die twice, the first roll results in a number $A$ and the second roll results in a number $B$. The die has $N$ faces, and the numbers on these faces are given. The numbers $A$ and $B$ are also provided.

## Intuition & Mathematical Observation
The core of this problem lies in understanding probability and independent events.

1.  **Probability of a Single Event**: The probability of an event occurring is the number of favorable outcomes divided by the total number of possible outcomes. In this case, for a single roll of the die:
    *   The probability of rolling the number $A$ is the count of faces with the number $A$ divided by the total number of faces ($N$).
    *   Similarly, the probability of rolling the number $B$ is the count of faces with the number $B$ divided by the total number of faces ($N$).

2.  **Independent Events**: The problem states that the die is rolled twice. Each roll is an independent event. This means the outcome of the first roll does not affect the outcome of the second roll. For independent events, the probability of both events occurring is the product of their individual probabilities.

    Therefore, the probability of rolling $A$ on the first toss AND rolling $B$ on the second toss is:
    $P(\text{Roll A first and Roll B second}) = P(\text{Roll A first}) \times P(\text{Roll B second})$

    Let $count(X)$ be the number of faces on the die that have the number $X$.
    Then, $P(\text{Roll A first}) = \frac{count(A)}{N}$ and $P(\text{Roll B second}) = \frac{count(B)}{N}$.

    So, the total probability is $\frac{count(A)}{N} \times \frac{count(B)}{N}$.

    It's important to note that $A$ and $B$ can be the same number. If $A = B$, we are looking for the probability of rolling $A$ on the first toss and $A$ on the second toss. The formula still holds: $P(\text{Roll A first and Roll A second}) = P(\text{Roll A first}) \times P(\text{Roll A second}) = \frac{count(A)}{N} \times \frac{count(A)}{N}$.

The strategy is to:
1.  Read the input values for $N$, $A$, and $B$.
2.  Iterate through the $N$ numbers on the die faces.
3.  Count how many times $A$ appears ($countA$) and how many times $B$ appears ($countB$).
4.  Calculate the probability: $(countA / N) \times (countB / N)$.
5.  Print the result with the required precision.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The solution iterates through the $N$ faces of the die once to count the occurrences of $A$ and $B$. The input reading and probability calculation take constant time per test case. Since there are $T$ test cases, the total time complexity is $O(T \times N)$. However, for a single test case, it's $O(N)$.

-   **Space Complexity**: $O(1)$
    The solution uses a few variables to store counts and probabilities. The amount of memory used does not depend on the input size $N$, making the space complexity constant.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <iomanip>

// Using namespace std; is common in competitive programming to avoid typing std:: repeatedly.
using namespace std;

void solve() {
    int N;
    long long A, B; // Using long long for A and B just in case, though constraints say N, A, B <= N
    cin >> N >> A >> B;

    int countA = 0; // Counter for occurrences of number A on die faces
    int countB = 0; // Counter for occurrences of number B on die faces

    // Loop N times to read each number written on the faces of the die.
    for (int i = 0; i < N; ++i) {
        int x; // x_i <= N, so int is fine.
        cin >> x; // Read the current face number
        
        // Check if the current face number matches A
        if (x == A) {
            countA++;
        }
        // Check if the current face number matches B
        // This is an independent check, as A and B can be the same number.
        if (x == B) {
            countB++;
        }
    }

    // Calculate the probability of getting A on the first toss.
    // static_cast<double> is used to ensure floating-point division.
    double probA = static_cast<double>(countA) / N;
    
    // Calculate the probability of getting B on the second toss.
    double probB = static_cast<double>(countB) / N;

    // Since the tosses are mutually independent, the total probability of winning
    // is the product of the individual probabilities.
    double total_probability = probA * probB;

    // Print the result.
    // std::fixed ensures that the number is printed in fixed-point notation (not scientific).
    // std::setprecision(10) sets the number of digits after the decimal point to 10,
    // which is sufficient for the required absolute error of 10^-6.
    cout << fixed << setprecision(10) << total_probability << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input,
    // further optimizing I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```