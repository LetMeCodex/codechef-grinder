# [The Preparations (SUPCHEF)](https://www.codechef.com/problems/SUPCHEF)
- **Difficulty Rating**: 823
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to watch $N$ episodes of a TV series. Each episode has a duration of $K$ minutes. Chef has $M$ minutes until the exam. Chef can only watch one episode at a time. The question is whether Chef can finish watching all $N$ episodes before the exam.

## Intuition & Mathematical Observation
The core of this problem is to determine if the total time required to watch all episodes is less than the time Chef has available until the exam.

Let:
- $N$ be the number of episodes.
- $K$ be the duration of each episode in minutes.
- $M$ be the total time Chef has until the exam in minutes.

The total time Chef needs to spend watching all episodes is the number of episodes multiplied by the duration of each episode.
Total watch time = $N \times K$ minutes.

Chef can finish watching all episodes before the exam if and only if the total watch time is strictly less than the time available until the exam.
So, the condition is:
$N \times K < M$

If this condition holds true, Chef can finish watching all episodes, and the answer is "YES". Otherwise, Chef cannot finish watching all episodes, and the answer is "NO".

The constraints on $N$ and $K$ are up to $10^4$. Their product $N \times K$ can be up to $10^8$. The constraint on $M$ is up to $10^9$. To avoid potential integer overflow when calculating $N \times K$, it's important to use a data type that can hold values up to $10^8$ and $10^9$. `long long` in C++ is suitable for this purpose.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations (multiplication and comparison) and input/output operations per test case. The time taken does not depend on the magnitude of the input values $M, N, K$, only on the number of test cases $t$.

- **Space Complexity**: $O(1)$
The solution uses a constant amount of extra space to store variables like $t, M, N, K$, and `total_watch_time`. This space requirement does not grow with the input size.

## Solution Code
```cpp
#include <iostream>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        long long M, N, K;
        std::cin >> M >> N >> K; // Read M, N, and K for each test case

        // Calculate the total time required to watch all episodes
        // Use long long for total_watch_time to prevent potential overflow
        // since N and K can be up to 10^4, their product can be up to 10^8.
        // M can be up to 10^9.
        long long total_watch_time = N * K;

        // Check if the total watch time is strictly less than the time until the exam
        if (total_watch_time < M) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```