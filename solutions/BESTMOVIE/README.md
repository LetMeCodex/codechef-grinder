# [Best Movie (BESTMOVIE)](https://www.codechef.com/problems/BESTMOVIE)
- **Difficulty Rating**: 660
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the minimum cost of a movie that meets a specific rating criterion. We are given $N$ movies, and for each movie, we know its rating $A$ and its cost $B$. Our goal is to:
1. Identify all movies with a rating $A$ of at least 7.
2. Among these suitable movies, find the one with the minimum cost $B$.
3. If no movie satisfies the rating criterion ($A \ge 7$), we should output -1. Otherwise, we output the minimum cost found.

This process needs to be repeated for $T$ test cases.

## Intuition & Mathematical Observation

The core of the problem is to filter a list of items (movies) based on a condition (rating $\ge 7$) and then find the minimum value (cost) among the filtered items.

1.  **Initialization**: We need a variable to store the minimum cost found so far. It should be initialized to a very large value (e.g., `infinity` or `std::numeric_limits<int>::max()`) so that the cost of the first suitable movie encountered will always be smaller and correctly update this variable.
2.  **Tracking Suitability**: We also need a way to know if *any* movie met the rating criterion. A boolean flag, say `found_suitable_movie`, initialized to `false`, can serve this purpose. It will be set to `true` as soon as we find at least one movie with a rating of 7 or more.
3.  **Iteration and Filtering**: We will iterate through each of the $N$ movies. For each movie, we check its rating $A$.
    *   If $A \ge 7$: This movie is suitable. We update our `min_cost` variable by comparing its current value with the current movie's cost $B$. We also set `found_suitable_movie` to `true`.
    *   If $A < 7$: This movie is not suitable, so we simply ignore it and move to the next movie.
4.  **Final Output**: After checking all $N$ movies, we examine the `found_suitable_movie` flag.
    *   If `found_suitable_movie` is `true`, it means we found at least one suitable movie, and `min_cost` now holds the minimum cost among them. We print `min_cost`.
    *   If `found_suitable_movie` is `false`, it means no movie met the rating criterion. We print -1.

This approach ensures that we correctly handle both cases: when suitable movies exist and when they don't, and always find the absolute minimum cost among the suitable ones.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    *   For each test case, we iterate through $N$ movies. Inside the loop, we perform a constant number of operations (reading two integers, one comparison, one `std::min` operation, and one boolean assignment).
    *   Reading $T$ and $N$ also takes constant time relative to the loop.
    *   Therefore, the total time complexity for $T$ test cases is $O(T \cdot N)$. Given the constraints (typically $T$ up to $100$ and $N$ up to $1000$), this is efficient enough.

-   **Space Complexity**: $O(1)$
    *   We use a few variables (`T`, `N`, `A`, `B`, `min_cost`, `found_suitable_movie`) to store input and intermediate results. The number of these variables is constant and does not depend on the input size $N$.
    *   Thus, the memory usage remains constant regardless of the number of movies.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <algorithm> // Required for std::min
#include <limits>    // Required for std::numeric_limits<int>::max()

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    while (T--) { // Loop through each test case
        int N; // Variable to store the number of movies in the current test case
        std::cin >> N; // Read the number of movies

        // Initialize min_cost to the maximum possible integer value.
        // This ensures that any valid movie cost will be smaller and correctly update min_cost.
        int min_cost = std::numeric_limits<int>::max(); 
        
        // Flag to track if at least one movie with rating >= 7 was found.
        bool found_suitable_movie = false;

        // Loop through each of the N movies
        for (int i = 0; i < N; ++i) {
            int A, B; // Variables to store rating (A) and cost (B) of the current movie
            std::cin >> A >> B; // Read rating and cost

            // Check if the movie's rating is at least 7
            if (A >= 7) {
                found_suitable_movie = true; // Mark that a suitable movie has been found
                // Update min_cost if the current movie's cost is lower
                min_cost = std::min(min_cost, B);
            }
        }

        // After checking all movies, determine the output
        if (found_suitable_movie) {
            // If at least one suitable movie was found, print its minimum cost
            std::cout << min_cost << std::endl;
        } else {
            // If no suitable movie was found, print -1
            std::cout << -1 << std::endl;
        }
    }

    return 0; // Indicate successful execution
}

```