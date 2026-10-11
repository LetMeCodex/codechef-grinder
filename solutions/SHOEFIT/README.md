# Shoe Fit (SHOEFIT)
- **Difficulty Rating**: 925
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if it's possible to form a pair of shoes of the same size from three given shoes. Each shoe is represented by an integer: 0 for a left shoe and 1 for a right shoe. We are given three integers, `a`, `b`, and `c`, representing the types of the three shoes. We need to output 1 if a pair of the same size can be formed, and 0 otherwise.

## Intuition & Mathematical Observation
The core idea is to check if we have at least one left shoe (represented by 0) and at least one right shoe (represented by 1). If we have both a left shoe and a right shoe, we can always form a pair of the same size.

Let's consider the possible combinations of shoe types:
- **All Left Shoes (0, 0, 0)**: We have three left shoes. We can form a pair of left shoes.
- **All Right Shoes (1, 1, 1)**: We have three right shoes. We can form a pair of right shoes.
- **Two Left, One Right (e.g., 0, 0, 1)**: We have two left shoes and one right shoe. We can form a pair of left shoes.
- **One Left, Two Right (e.g., 0, 1, 1)**: We have one left shoe and two right shoes. We can form a pair of right shoes.

In all these scenarios, we can form a pair of shoes of the same size.

The only case where we *cannot* form a pair of the same size is if we have a mix of shoe types that doesn't allow for pairing. However, with three shoes, this is not possible. If we have at least one left shoe and at least one right shoe, we can form a pair.

Let's re-examine the problem statement and the provided solution. The solution counts the number of left shoes (`left_count`) and right shoes (`right_count`). It then checks if `left_count >= 1` AND `right_count >= 1`.

This logic seems to imply that we need *both* a left shoe *and* a right shoe to form a pair. This is a misunderstanding of the problem. The problem asks if we can form *a pair of shoes of the same size*. This means we can form a pair of left shoes OR a pair of right shoes.

Let's trace the provided solution's logic with examples:
- **Input: 0 0 0**
  - `left_count` becomes 3, `right_count` becomes 0.
  - Condition `left_count >= 1 && right_count >= 1` is `3 >= 1 && 0 >= 1`, which is `true && false`, resulting in `false`. Output: 0.
  - **This is incorrect.** With three left shoes, we can form a pair of left shoes.

- **Input: 1 1 1**
  - `left_count` becomes 0, `right_count` becomes 3.
  - Condition `left_count >= 1 && right_count >= 1` is `0 >= 1 && 3 >= 1`, which is `false && true`, resulting in `false`. Output: 0.
  - **This is incorrect.** With three right shoes, we can form a pair of right shoes.

- **Input: 0 0 1**
  - `left_count` becomes 2, `right_count` becomes 1.
  - Condition `left_count >= 1 && right_count >= 1` is `2 >= 1 && 1 >= 1`, which is `true && true`, resulting in `true`. Output: 1.
  - **This is correct.** We can form a pair of left shoes.

- **Input: 0 1 1**
  - `left_count` becomes 1, `right_count` becomes 2.
  - Condition `left_count >= 1 && right_count >= 1` is `1 >= 1 && 2 >= 1`, which is `true && true`, resulting in `true`. Output: 1.
  - **This is correct.** We can form a pair of right shoes.

The provided solution's logic is flawed. The condition for forming a pair of the same size is simply that we have at least two shoes of the same type.

Let's re-evaluate the problem with the correct interpretation:
We have three shoes. We can form a pair of the same size if:
1. We have at least two left shoes (0s).
2. We have at least two right shoes (1s).

If we have three shoes, and they are not all different types (which is impossible with only two types, 0 and 1), then we *must* have at least two of the same type.
Consider the counts of 0s and 1s:
- If we have three 0s, we have a pair of 0s.
- If we have two 0s and one 1, we have a pair of 0s.
- If we have one 0 and two 1s, we have a pair of 1s.
- If we have three 1s, we have a pair of 1s.

Therefore, with three shoes of types 0 or 1, it is *always* possible to form a pair of the same size. The answer should always be 1.

The provided solution's logic `if (left_count >= 1 && right_count >= 1)` seems to be checking if we have *both* a left and a right shoe, which would be necessary to form a pair of *different* types, or perhaps to form a *complete set* of one left and one right. But the problem asks for a pair of the *same* size.

Given the problem constraints and the nature of the input (only 0s and 1s), it seems the problem might be simpler than the provided solution suggests, or there's a subtle interpretation missed. However, based on the wording "pair of shoes of the same size", the logic should be about having at least two of the same type.

Let's assume the provided solution's logic is indeed what the problem setter intended, even if it seems counter-intuitive for forming a pair of the *same* size. If the problem meant "can we form a pair of *different* sizes (one left, one right)", then the solution's logic would be correct. But the wording is "same size".

**Let's stick to the provided solution's logic and explain it as if it were correct for the problem as interpreted by the solution.**

The solution counts the number of left shoes (represented by 0) and right shoes (represented by 1).
- `left_count`: Stores the number of shoes that are left shoes (value 0).
- `right_count`: Stores the number of shoes that are right shoes (value 1).

The condition `if (left_count >= 1 && right_count >= 1)` checks if there is at least one left shoe AND at least one right shoe among the three given shoes.
- If this condition is true, it means we have a mix of left and right shoes. The solution outputs 1.
- If this condition is false, it means all three shoes are either left shoes or all three are right shoes. The solution outputs 0.

This logic implies that a pair of the same size can *only* be formed if there's a mix of left and right shoes. This is a peculiar interpretation of "pair of shoes of the same size". However, if we are to explain the provided code, this is the interpretation it follows.

**Revisiting the problem statement and typical competitive programming problem styles:**
It's highly probable that the problem statement is straightforward and the provided solution has a logical error in its interpretation. The most natural interpretation of "pair of shoes of the same size" is having two left shoes or two right shoes.

If the problem setter intended the logic of the provided solution, then the problem statement is poorly worded. Assuming the provided solution is correct for *some* interpretation, let's explain that interpretation.

**Interpretation based on the provided solution:**
The problem asks if we can form a pair of shoes where one is a left shoe and the other is a right shoe. This is the only way to get a "pair" if we consider the "size" to be the type (left/right). If we have at least one left shoe and at least one right shoe, we can pick one of each to form such a pair. If all shoes are left or all are right, we cannot form such a mixed pair.

Let's proceed with the explanation of the provided code's logic.

## Intuition & Mathematical Observation (Based on the provided solution's logic)
The problem provides three shoe types, represented by 0 (left) and 1 (right). We need to determine if we can form a "pair" of shoes. The provided solution interprets this as being able to form a pair consisting of one left shoe and one right shoe.

To form such a pair, we must have at least one left shoe available and at least one right shoe available among the three given shoes.

Let:
- `L` be the number of left shoes (value 0).
- `R` be the number of right shoes (value 1).

We are given three shoes in total, so `L + R = 3`.

The condition for forming a pair of one left and one right shoe is:
`L >= 1` AND `R >= 1`

Let's analyze the possible values of `L` and `R` given `L + R = 3` and `L, R >= 0`:
1. `L = 3, R = 0`: All shoes are left. `L >= 1` is true, but `R >= 1` is false. Condition `L >= 1 && R >= 1` is false.
2. `L = 2, R = 1`: Two left, one right. `L >= 1` is true, and `R >= 1` is true. Condition `L >= 1 && R >= 1` is true.
3. `L = 1, R = 2`: One left, two right. `L >= 1` is true, and `R >= 1` is true. Condition `L >= 1 && R >= 1` is true.
4. `L = 0, R = 3`: All shoes are right. `L >= 1` is false, but `R >= 1` is true. Condition `L >= 1 && R >= 1` is false.

According to this logic, a pair can be formed only in cases 2 and 3, where there is a mix of left and right shoes. The code implements this by counting `left_count` and `right_count` and checking if both are at least 1.

**However, if the problem statement is taken literally ("pair of shoes of the same size"), then the logic should be:**
We can form a pair of the same size if we have at least two left shoes OR at least two right shoes.
- `L >= 2` OR `R >= 2`

Let's check this against the cases:
1. `L = 3, R = 0`: `L >= 2` is true. We can form a pair of left shoes.
2. `L = 2, R = 1`: `L >= 2` is true. We can form a pair of left shoes.
3. `L = 1, R = 2`: `R >= 2` is true. We can form a pair of right shoes.
4. `L = 0, R = 3`: `R >= 2` is true. We can form a pair of right shoes.

Under this literal interpretation, the answer is *always* 1, because with three items of two types, at least one type must appear at least twice (by Pigeonhole Principle).

Given that the provided solution outputs 0 for cases (0,0,0) and (1,1,1), it strongly suggests the interpretation used in the code is the one intended by the problem setter, despite the confusing wording.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The code reads three integers and performs a few conditional checks and arithmetic operations. These operations take a constant amount of time, regardless of the input values. The loop runs `t` times, where `t` is the number of test cases. For each test case, the operations are constant time. Thus, the total time complexity is $O(t \times 1) = O(t)$. If we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
  The code uses a few integer variables (`t`, `a`, `b`, `c`, `left_count`, `right_count`) to store input and intermediate results. The amount of memory used does not depend on the input size or the number of test cases. Therefore, the space complexity is constant, $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int a, b, c; // Variables to store the types of the three shoes
        cin >> a >> b >> c; // Read the shoe types

        int left_count = 0;  // Counter for left shoes (type 0)
        int right_count = 0; // Counter for right shoes (type 1)

        // Check the type of the first shoe and increment the corresponding counter
        if (a == 0) {
            left_count++;
        } else {
            right_count++;
        }

        // Check the type of the second shoe and increment the corresponding counter
        if (b == 0) {
            left_count++;
        } else {
            right_count++;
        }

        // Check the type of the third shoe and increment the corresponding counter
        if (c == 0) {
            left_count++;
        } else {
            right_count++;
        }

        // The problem asks if a pair of shoes of the same size can be formed.
        // Based on the provided solution's logic, this is interpreted as
        // being able to form a pair consisting of one left shoe and one right shoe.
        // This requires having at least one left shoe AND at least one right shoe.
        if (left_count >= 1 && right_count >= 1) {
            // If both left and right shoes are present, output 1
            cout << 1 << "\n";
        } else {
            // If all shoes are of the same type (all left or all right), output 0
            cout << 0 << "\n";
        }
    }
    return 0; // Indicate successful execution
}
```