# 3 Logicians Walk into a Bar (LOGICIAN)
- **Difficulty Rating**: 1269
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ logicians, and each logician $i$ has a preference $S_i$ for beer, where $S_i = 1$ if they want beer and $S_i = 0$ if they don't. The preferences are given as a binary string $S$. The logicians are asked a question: "Does everyone want a beer?". They answer in order from 1 to $N$.

Each logician $i$ knows their own preference $S_i$ and the preferences of all logicians $j < i$. They also know the answers given by logicians $1, 2, \ldots, i-1$. Based on this information, logician $i$ must answer "YES" if they are certain that everyone wants a beer, "NO" if they are certain that not everyone wants a beer, and "IDK" if they cannot be certain.

## Intuition & Mathematical Observation

The core of this problem lies in how each logician uses the information available to them to deduce the answer to "Does everyone want a beer?". Let's denote the preference of logician $i$ as $S_i$. The question is equivalent to asking if $S_1 = 1 \land S_2 = 1 \land \ldots \land S_N = 1$.

Consider logician $i$. They know:
1. Their own preference $S_i$.
2. The preferences $S_1, S_2, \ldots, S_{i-1}$.
3. The answers given by logicians $1, 2, \ldots, i-1$.

Let's analyze the possible answers and what they imply:

*   **If logician $i$ answers "NO"**: This means logician $i$ is certain that at least one person does *not* want beer. This can happen in two ways:
    *   Logician $i$ knows their own preference $S_i = 0$. In this case, they are directly certain that not everyone wants beer.
    *   Logician $i$ knows from the previous logicians' answers that it's impossible for everyone to want beer. For example, if a previous logician $j < i$ answered "NO", it implies that either $S_j=0$ or some other logician $k<j$ had $S_k=0$.

*   **If logician $i$ answers "YES"**: This means logician $i$ is certain that *everyone* wants beer. This can only happen if logician $i$ has deduced that $S_1=1, S_2=1, \ldots, S_N=1$. This implies that logician $i$ must know their own preference $S_i=1$, and they must also know that $S_1=1, \ldots, S_{i-1}=1$, and crucially, they must be the *last* logician ($i=N$). If they are not the last logician, they cannot be certain about the preferences of logicians $i+1, \ldots, N$.

*   **If logician $i$ answers "IDK"**: This means logician $i$ cannot be certain. This happens when:
    *   Logician $i$ knows their own preference $S_i=1$.
    *   All previous logicians $j < i$ who answered "IDK" must have had $S_j=1$.
    *   No previous logician $j < i$ has answered "NO".
    *   If these conditions hold, logician $i$ knows $S_1=1, \ldots, S_i=1$. However, if $i < N$, they don't know the preferences of logicians $i+1, \ldots, N$. It's still possible that all of them want beer (leading to "YES"), or at least one doesn't (leading to "NO"). Since both outcomes are possible, they must say "IDK".

**Key Observation:** The crucial piece of information that propagates is whether it's *still possible* for everyone to want beer. Let's maintain a boolean flag, say `can_still_be_all_yes`. Initially, before anyone speaks, it's possible that everyone wants beer, so `can_still_be_all_yes` is `true`.

When logician $i$ (with preference $S_i$) speaks:

1.  **If $S_i = 0$**: Logician $i$ knows they don't want beer. Therefore, they are certain that not everyone wants beer. They will say "NO". Once this happens, the state `can_still_be_all_yes` becomes `false` and remains `false` for all subsequent logicians.

2.  **If $S_i = 1$**: Logician $i$ knows they want beer.
    *   **If `can_still_be_all_yes` is `false`**: This means a previous logician has already established that not everyone wants beer. Logician $i$ will say "NO". The flag `can_still_be_all_yes` remains `false`.
    *   **If `can_still_be_all_yes` is `true`**: This means all previous logicians $j < i$ who spoke must have had $S_j=1$ (otherwise `can_still_be_all_yes` would be false). Combined with $S_i=1$, logician $i$ now knows that $S_1=1, S_2=1, \ldots, S_i=1$.
        *   **If $i = N$ (the last logician)**: Since logician $N$ knows $S_1=1, \ldots, S_N=1$, they are certain everyone wants beer. They will say "YES". The flag `can_still_be_all_yes` remains `true`.
        *   **If $i < N$**: Logician $i$ knows $S_1=1, \ldots, S_i=1$, but they don't know the preferences of logicians $i+1, \ldots, N$. It's still possible that all of them want beer, or at least one doesn't. Thus, they cannot be certain and will say "IDK". The flag `can_still_be_all_yes` remains `true`.

This logic perfectly matches the problem statement and the provided solution code. The `can_still_be_all_yes` flag effectively tracks whether the condition $S_1=1 \land S_2=1 \land \ldots \land S_i=1$ is still possible based on the information revealed up to logician $i$.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    The code iterates through the input string $S$ of length $N$ exactly once. Inside the loop, operations are constant time. The main function reads $T$ test cases and calls `solve()` for each. Thus, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(N)$ per test case.
    The input string $S$ takes $O(N)$ space. The other variables (`N`, `can_still_be_all_yes`, loop counter `i`) take constant space. Therefore, the space complexity is dominated by the input string, resulting in $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <string>   // Required for std::string

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of logicians
    std::string S;
    std::cin >> S; // Read the binary string representing logicians' preferences

    // This boolean flag tracks whether, based on all information revealed so far,
    // it is still possible that *all* N logicians want beer.
    // Initially, before any logician has spoken, it's possible.
    bool can_still_be_all_yes = true;

    // Iterate through each logician from 1 to N (using 0-indexed 'i' for string S)
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            // Logician (i+1) knows they themselves do not want beer.
            // If even one logician doesn't want beer, then it's impossible for "everyone" to want beer.
            // So, logician (i+1) is certain the answer to "Does everyone want a beer?" is "NO".
            std::cout << "NO\n";
            
            // Once a logician says "NO" because they don't want beer,
            // it's definitively established that not everyone wants beer.
            // This information is known to all subsequent logicians.
            can_still_be_all_yes = false;
        } else { // S[i] == '1' (Logician (i+1) wants beer)
            // Logician (i+1) knows they themselves want beer.
            // Now, they must consider the information gathered from previous logicians' replies.
            if (!can_still_be_all_yes) {
                // If 'can_still_be_all_yes' is false, it means some previous logician (j < i+1)
                // has already determined that not everyone wants beer (by saying "NO").
                // So, logician (i+1) is certain the answer is "NO".
                std::cout << "NO\n";
                // The state 'can_still_be_all_yes' remains false.
            } else {
                // If 'can_still_be_all_yes' is true, it means:
                // 1. All previous logicians (j < i+1) who replied "IDK" must have wanted beer (S_j = '1').
                // 2. No previous logician has replied "NO".
                // Combined with S[i] == '1', logician (i+1) has deduced that S_1='1', S_2='1', ..., S_{i+1}='1'.

                if (i == N - 1) {
                    // This is the last logician.
                    // They have deduced that S_1='1', ..., S_N='1'.
                    // They are now certain that *everyone* wants beer.
                    std::cout << "YES\n";
                    // The state 'can_still_be_all_yes' remains true (as the condition was met).
                } else {
                    // This is not the last logician.
                    // They know S_1='1', ..., S_{i+1}='1'.
                    // However, they do not know the preferences of logicians (i+2) through N.
                    // It's still possible that all remaining logicians want beer (leading to "YES").
                    // It's also still possible that at least one of the remaining logicians does not want beer (leading to "NO").
                    // Since both outcomes are possible, logician (i+1) cannot be certain.
                    std::cout << "IDK\n";
                    // The state 'can_still_be_all_yes' remains true, as it's still possible for everyone to want beer.
                }
            }
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```