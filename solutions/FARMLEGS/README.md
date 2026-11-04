# Legs on a Farm (FARMLEGS)
- **Difficulty Rating**: 709
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the minimum total number of animals (cows and chickens) on a farm, given the total number of legs, $N$. We are told that cows have 4 legs and chickens have 2 legs. The total number of legs $N$ is guaranteed to be even.

## Intuition & Mathematical Observation
We want to minimize the total number of animals. To do this, we should prioritize using animals with more legs. Cows have 4 legs, and chickens have 2 legs. Therefore, we should try to have as many cows as possible.

Let $C$ be the number of cows and $H$ be the number of chickens. The total number of legs is given by:
$4C + 2H = N$

We want to minimize $C + H$.

Since $N$ is even, we can divide the equation by 2:
$2C + H = N/2$

To minimize $C + H$, we should maximize $C$. The maximum possible number of cows we can have is when we use as many 4-legged animals as possible. This is achieved by taking the integer division of $N$ by 4.
Let $C_{max} = \lfloor N / 4 \rfloor$.

After accounting for the legs of these cows, the number of legs remaining is $N - 4 \times C_{max}$.
Since $N$ is even, and $4 \times C_{max}$ is also even, the remaining legs will always be even.
The remaining legs must be accounted for by chickens, each having 2 legs.
So, the number of chickens, $H$, will be $(N - 4 \times C_{max}) / 2$.

Let's analyze the remaining legs:
$N \pmod 4$ can be 0 or 2, since $N$ is even.

Case 1: $N \pmod 4 = 0$.
This means $N$ is a multiple of 4.
$C_{max} = N / 4$.
Remaining legs = $N - 4 \times (N/4) = N - N = 0$.
Number of chickens $H = 0 / 2 = 0$.
Total animals = $C_{max} + H = N/4 + 0 = N/4$.

Case 2: $N \pmod 4 = 2$.
This means $N$ can be written as $4k + 2$ for some integer $k$.
$C_{max} = \lfloor (4k+2) / 4 \rfloor = k$.
Remaining legs = $(4k+2) - 4 \times k = 4k + 2 - 4k = 2$.
Number of chickens $H = 2 / 2 = 1$.
Total animals = $C_{max} + H = k + 1$.
Since $N = 4k+2$, $N/4 = k$ (integer division).
So, $C_{max} = N/4$.
Total animals = $N/4 + 1$.

In both cases, the number of cows is $N/4$ (integer division), and the number of chickens is $(N \pmod 4) / 2$.
The total number of animals is $(N/4) + (N \pmod 4) / 2$.

This strategy indeed minimizes the total number of animals because we are maximizing the use of 4-legged animals. Any attempt to replace a cow with two chickens would increase the total number of animals (1 cow replaced by 2 chickens).

For example, if $N=10$:
$N/4 = 2$ (cows). Legs from cows = $2 \times 4 = 8$.
Remaining legs = $10 - 8 = 2$.
Chickens = $2 / 2 = 1$.
Total animals = $2 + 1 = 3$.

If we tried to use fewer cows, say 1 cow:
Legs from 1 cow = 4.
Remaining legs = $10 - 4 = 6$.
Chickens = $6 / 2 = 3$.
Total animals = $1 + 3 = 4$. This is more than 3.

The logic holds: maximize cows, then use chickens for remaining legs.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a few arithmetic operations (division, modulo, addition) and reading input. These operations take constant time, regardless of the input size $N$. The loop for test cases runs $T$ times, and each iteration takes $O(1)$ time. Thus, the total time complexity is $O(T)$. If we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
The solution uses a fixed number of variables to store input and intermediate results ($N$, $T$, `num_cows`, `num_chickens`, `remaining_legs`, `total_animals`). The memory usage does not grow with the input size $N$. Therefore, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Required by problem statement

// Required by problem statement
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the total number of legs

    // Calculate the maximum number of cows.
    // Each cow has 4 legs. Integer division N / 4 gives the maximum whole cows.
    int num_cows = N / 4;

    // Calculate the remaining legs after accounting for cows.
    // Since N is even, N % 4 will either be 0 or 2.
    // If N % 4 is 0, no legs remain, so 0 chickens.
    // If N % 4 is 2, 2 legs remain, which must come from 1 chicken.
    int remaining_legs = N % 4;
    
    // Each chicken has 2 legs.
    // remaining_legs / 2 will correctly give 0 chickens if remaining_legs is 0,
    // and 1 chicken if remaining_legs is 2.
    int num_chickens = remaining_legs / 2;

    // The total minimum number of animals is the sum of cows and chickens.
    int total_animals = num_cows + num_chickens;

    cout << total_animals << "\n"; // Output the result
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
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