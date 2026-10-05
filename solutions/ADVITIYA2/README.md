# [Judged (ADVITIYA2)](https://www.codechef.com/problems/ADVITIYA2)
- **Difficulty Rating**: 453
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a movie is "liked" based on the ratings it receives. We are given five ratings, where each rating can be either 1 (liked) or 0 (disliked). The movie is considered "liked" if at least 4 out of the 5 ratings are 1.

## Intuition & Mathematical Observation

The core of the problem is to count the number of "liked" ratings and compare it to a threshold. We are given five individual ratings, and each rating contributes to the overall "liked" status.

Let's represent the ratings as $r_1, r_2, r_3, r_4, r_5$. Each $r_i$ can be either 0 or 1.
The movie is liked if the sum of these ratings is greater than or equal to 4.

Mathematically, this can be expressed as:
$$ \sum_{i=1}^{5} r_i \ge 4 $$

Since each $r_i$ is either 0 or 1, the sum $\sum_{i=1}^{5} r_i$ directly represents the count of ratings that are 1 (i.e., the number of "liked" ratings).

Therefore, the problem simplifies to:
1. Read the five ratings.
2. Sum these five ratings.
3. If the sum is 4 or 5, output "YES".
4. Otherwise (if the sum is 0, 1, 2, or 3), output "NO".

The provided solution directly implements this logic by summing the five input integers and checking if the sum is greater than or equal to 4.

## Complexity Analysis

- **Time Complexity**: $O(1)$
The program reads a fixed number of inputs (5 integers per test case) and performs a constant number of operations (addition and comparison). The number of test cases is also handled within a loop, but the operations per test case are constant.

- **Space Complexity**: $O(1)$
The program uses a fixed amount of memory to store the input variables and a few temporary variables, regardless of the input size.