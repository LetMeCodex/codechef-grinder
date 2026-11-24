# [Maximum Remaining (MAXREM)](https://www.codechef.com/problems/MAXREM)
- **Difficulty Rating**: 1221
- **Solved in**: 1 attempt(s)

## Problem Summary

Given an array $A$ of $N$ integers, where $N \ge 2$. We need to find the maximum possible value of $A_i \pmod{A_j}$ for any pair of indices $(i, j)$ such that $A_i$ and $A_j$ are distinct elements from the array. If all elements in the array are the same, the answer is 0.

## Intuition & Mathematical Observation

The problem asks us to maximize the remainder $A_i \pmod{A_j}$ where $A_i \neq A_j$.

Let's consider the properties of the modulo operation: $A_i \pmod{A_j} = A_i - k \cdot A_j$, where $k$ is the largest integer such that $k \cdot A_j \le A_i$. The remainder is always non-negative and strictly less than the divisor $A_j$. That is, $0 \le A_i \pmod{A_j} < A_j$.

To maximize $A_i \pmod{A_j}$, we want to make the remainder as large as possible. The largest possible remainder when dividing by $A_j$ is $A_j - 1$. This occurs when $A_i$ is just one less than a multiple of $A_j$. For example, if $A_j = 5$, the maximum remainder is 4, which can be achieved if $A_i$ is 4, 9, 14, etc.

Consider the distinct elements present in the array. Let these distinct elements, sorted in ascending order, be $M_1 < M_2 < M_3 < \dots < M_k$.

**Case 1: All elements are the same.**
If all elements in the array are identical, say all are $X$, then any pair $(A_i, A_j)$ will have $A_i = A_j = X$. Since the problem requires $A_i$ and $A_j$ to be distinct, this case is only possible if we interpret "distinct elements from the array" as distinct *values*. If all values are the same, there are no distinct pairs of values. However, the problem statement implies $N \ge 2$, and if all $N$ elements are the same, then any $A_i \pmod{A_j}$ would be $X \pmod{X} = 0$. The problem statement explicitly mentions: "If all elements in the array are the same, the answer is 0." This confirms our understanding.

**Case 2: There are at least two distinct elements.**
Let the distinct elements be $M_1 < M_2 < \dots < M_k$, where $k \ge 2$.
We want to maximize $A_i \pmod{A_j}$ where $A_i \neq A_j$.

To maximize the remainder $A_i \pmod{A_j}$, we should aim for a large value of $A_i$ and a relatively small value of $A_j$. However, the remainder is bounded by $A_j$. A larger $A_j$ *could* potentially yield a larger remainder, but it also means the remainder must be strictly less than that larger $A_j$.

Let's consider the largest distinct element, $M_k$.
If we choose $A_j = M_k$, then $A_i$ must be some other distinct element $M_p$ where $p < k$. The remainder $M_p \pmod{M_k}$ will be $M_p$ itself, since $M_p < M_k$. The maximum value we can get in this scenario is when $M_p$ is the largest possible value less than $M_k$, which is $M_{k-1}$. So, $M_{k-1} \pmod{M_k} = M_{k-1}$.

Now, let's consider choosing $A_j$ to be some other distinct element, say $M_p$ where $p < k$.
We want to maximize $A_i \pmod{M_p}$.
To get a large remainder, we want $A_i$ to be as close as possible to a multiple of $M_p$ from above. The largest possible value for $A_i$ is $M_k$.
So, we are interested in $M_k \pmod{M_p}$.

Let's analyze $M_k \pmod{M_p}$ for $p < k$.
The remainder $M_k \pmod{M_p}$ is $M_k - q \cdot M_p$, where $q = \lfloor M_k / M_p \rfloor$.
We want to maximize this value.

Consider the second largest distinct element, $M_{k-1}$.
If we choose $A_j = M_{k-1}$, and $A_i$ is any element $M_p$ where $p < k-1$, then $M_p \pmod{M_{k-1}} = M_p$. The maximum here is $M_{k-2}$.
If we choose $A_j = M_{k-1}$ and $A_i = M_k$, then $M_k \pmod{M_{k-1}}$.
Let $M_k = q \cdot M_{k-1} + r$, where $0 \le r < M_{k-1}$.
The remainder is $r$.

Let's compare the potential maximums:
1. $M_{k-1} \pmod{M_k} = M_{k-1}$ (by picking $A_i = M_{k-1}, A_j = M_k$)
2. $M_k \pmod{M_{k-1}}$ (by picking $A_i = M_k, A_j = M_{k-1}$)

We know that $M_k \pmod{M_{k-1}} < M_{k-1}$.
So, the remainder $M_k \pmod{M_{k-1}}$ is always strictly less than $M_{k-1}$.

What if we pick $A_j$ to be even smaller, say $M_p$ where $p < k-1$?
Then $A_i$ could be $M_k$. We are looking at $M_k \pmod{M_p}$.
Since $M_p < M_{k-1}$, the remainder $M_k \pmod{M_p}$ is strictly less than $M_p$.
Since $M_p < M_{k-1}$, it follows that $M_k \pmod{M_p} < M_p < M_{k-1}$.

This suggests that the maximum remainder is achieved when we pick $A_j$ to be the second largest distinct element ($M_{k-1}$) and $A_i$ to be the largest distinct element ($M_k$), and the remainder is $M_k \pmod{M_{k-1}}$.
However, the problem asks for the maximum possible value of $A_i \pmod{A_j}$.
The largest possible remainder when dividing by $A_j$ is $A_j - 1$.
If we can find an $A_i$ such that $A_i \pmod{A_j} = A_j - 1$, this would be a strong candidate for the maximum.

Consider the set of distinct elements. Let the largest be $M_{max}$ and the second largest be $M_{second\_max}$.
If we choose $A_j = M_{second\_max}$, then the maximum possible remainder is $M_{second\_max} - 1$.
Can we achieve $M_{second\_max} - 1$? This would require some $A_i$ such that $A_i \pmod{M_{second\_max}} = M_{second\_max} - 1$.
This means $A_i$ must be of the form $q \cdot M_{second\_max} + (M_{second\_max} - 1)$ for some integer $q \ge 0$.
The smallest such positive $A_i$ is $M_{second\_max} - 1$ (when $q=0$, but $A_i$ must be distinct from $A_j$, so this is not possible if $M_{second\_max}-1$ is not in the array or if $M_{second\_max}-1 = 0$).
The next smallest is $M_{second\_max} + (M_{second\_max} - 1) = 2 \cdot M_{second\_max} - 1$.
If $M_{max}$ is large enough, specifically if $M_{max} \ge 2 \cdot M_{second\_max} - 1$, then we could potentially have $A_i = M_{max}$ and $A_j = M_{second\_max}$, and the remainder would be $M_{max} \pmod{M_{second\_max}}$.

Let's re-evaluate. We want to maximize $A_i \pmod{A_j}$ where $A_i \neq A_j$.
The remainder $A_i \pmod{A_j}$ is always less than $A_j$.
So, to maximize the remainder, we should try to make $A_j$ as large as possible, but not *too* large such that the remainder becomes small.

Consider the largest distinct element, $M_{max}$.
If we choose $A_j = M_{max}$, then $A_i$ must be some other distinct element $A_i < M_{max}$.
The remainder $A_i \pmod{M_{max}}$ is simply $A_i$ itself, since $A_i < M_{max}$.
The maximum value of $A_i$ less than $M_{max}$ is the second largest distinct element, $M_{second\_max}$.
So, $M_{second\_max} \pmod{M_{max}} = M_{second\_max}$.

Now, consider choosing $A_j$ to be the second largest distinct element, $M_{second\_max}$.
We want to maximize $A_i \pmod{M_{second\_max}}$.
The largest possible value for $A_i$ is $M_{max}$.
So we consider $M_{max} \pmod{M_{second\_max}}$.
Let $M_{max} = q \cdot M_{second\_max} + r$, where $0 \le r < M_{second\_max}$.
The remainder is $r$.

We need to compare $M_{second\_max}$ (from $A_i=M_{second\_max}, A_j=M_{max}$) with $r = M_{max} \pmod{M_{second\_max}}$ (from $A_i=M_{max}, A_j=M_{second\_max}$).
Since $r < M_{second\_max}$, the value $M_{second\_max}$ is always greater than $r$.

What if we pick $A_j$ to be some other distinct element $M_p$ where $p < k-1$?
Then $A_i$ could be $M_{max}$. We are looking at $M_{max} \pmod{M_p}$.
The remainder $M_{max} \pmod{M_p}$ is strictly less than $M_p$.
Since $M_p < M_{second\_max}$, it follows that $M_{max} \pmod{M_p} < M_p < M_{second\_max}$.

This confirms that the maximum remainder is achieved by picking $A_j$ to be the second largest distinct element, and $A_i$ to be the largest distinct element. The remainder is $M_{max} \pmod{M_{second\_max}}$.

Let's re-read the problem carefully: "maximum possible value of $A_i \pmod{A_j}$ for any pair of indices $(i, j)$ such that $A_i$ and $A_j$ are distinct elements from the array."

This means we are looking for $\max \{ A_i \pmod{A_j} \mid A_i \in A, A_j \in A, A_i \neq A_j \}$.

Let the set of unique elements be $S = \{u_1, u_2, \dots, u_k\}$ where $u_1 < u_2 < \dots < u_k$.
If $k=1$, all elements are the same, answer is 0.
If $k \ge 2$:
We want to maximize $u_a \pmod{u_b}$ where $u_a, u_b \in S$ and $u_a \neq u_b$.

Consider $u_k$ (the largest element).
If we pick $A_j = u_k$, then $A_i$ must be some $u_a$ with $a < k$.
$u_a \pmod{u_k} = u_a$ since $u_a < u_k$.
The maximum value here is $u_{k-1}$ (by picking $A_i = u_{k-1}$).

Consider $u_{k-1}$ (the second largest element).
If we pick $A_j = u_{k-1}$, then $A_i$ can be any other distinct element.
If $A_i = u_k$, we get $u_k \pmod{u_{k-1}}$.
If $A_i = u_a$ where $a < k-1$, we get $u_a \pmod{u_{k-1}} = u_a$. The maximum here is $u_{k-2}$.

We need to compare $u_{k-1}$ and $u_k \pmod{u_{k-1}}$.
Since $u_k \pmod{u_{k-1}} < u_{k-1}$, the value $u_{k-1}$ is always greater than $u_k \pmod{u_{k-1}}$.

So, the maximum remainder is obtained by picking $A_i$ to be the second largest distinct element and $A_j$ to be the largest distinct element.
The maximum remainder is $u_{k-1} \pmod{u_k} = u_{k-1}$.

Wait, this seems too simple. Let's re-read the problem and sample cases.
Sample 1:
N = 3
A = {10, 20, 30}
Distinct elements: {10, 20, 30}. $u_1=10, u_2=20, u_3=30$.
$k=3$. $u_{k-1} = u_2 = 20$. $u_k = u_3 = 30$.
My logic suggests the answer is $u_{k-1} = 20$.
Let's check pairs:
10 % 20 = 10
10 % 30 = 10
20 % 10 = 0
20 % 30 = 20
30 % 10 = 0
30 % 20 = 10
Maximum is 20. This matches.

Sample 2:
N = 5
A = {1, 2, 3, 4, 5}
Distinct elements: {1, 2, 3, 4, 5}. $u_1=1, u_2=2, u_3=3, u_4=4, u_5=5$.
$k=5$. $u_{k-1} = u_4 = 4$. $u_k = u_5 = 5$.
My logic suggests the answer is $u_{k-1} = 4$.
Let's check pairs:
1 % 2 = 1, 1 % 3 = 1, 1 % 4 = 1, 1 % 5 = 1
2 % 1 = 0, 2 % 3 = 2, 2 % 4 = 2, 2 % 5 = 2
3 % 1 = 0, 3 % 2 = 1, 3 % 4 = 3, 3 % 5 = 3
4 % 1 = 0, 4 % 2 = 0, 4 % 3 = 1, 4 % 5 = 4
5 % 1 = 0, 5 % 2 = 1, 5 % 3 = 2, 5 % 4 = 1
Maximum is 4. This matches.

Sample 3:
N = 2
A = {100, 100}
Distinct elements: {100}. $k=1$.
Answer should be 0. My logic for $k=1$ says 0. This matches.

Sample 4:
N = 4
A = {10, 10, 20, 20}
Distinct elements: {10, 20}. $u_1=10, u_2=20$.
$k=2$. $u_{k-1} = u_1 = 10$. $u_k = u_2 = 20$.
My logic suggests the answer is $u_{k-1} = 10$.
Pairs:
10 % 20 = 10
20 % 10 = 0
Maximum is 10. This matches.

It seems my initial reasoning was flawed. The maximum remainder $A_i \pmod{A_j}$ is *not necessarily* $A_j-1$. It is bounded by $A_j-1$.

Let the distinct elements be $u_1 < u_2 < \dots < u_k$.
We want to maximize $u_a \pmod{u_b}$ where $a \neq b$.

Consider the largest distinct element $u_k$.
If we choose $A_j = u_k$, then $A_i$ must be some $u_a$ with $a < k$.
$u_a \pmod{u_k} = u_a$. The maximum value here is $u_{k-1}$.

Consider the second largest distinct element $u_{k-1}$.
If we choose $A_j = u_{k-1}$, then $A_i$ can be any other distinct element.
If $A_i = u_k$, we get $u_k \pmod{u_{k-1}}$.
If $A_i = u_a$ where $a < k-1$, we get $u_a \pmod{u_{k-1}} = u_a$. The maximum here is $u_{k-2}$.

So, the candidates for the maximum remainder are:
1. $u_{k-1}$ (achieved by $u_{k-1} \pmod{u_k}$)
2. $u_k \pmod{u_{k-1}}$ (achieved by $u_k \pmod{u_{k-1}}$)
3. $u_a$ for $a < k-1$ (achieved by $u_a \pmod{u_{k-1}}$ or $u_a \pmod{u_k}$)

Let's analyze $u_k \pmod{u_{k-1}}$.
Let $u_k = q \cdot u_{k-1} + r$, where $0 \le r < u_{k-1}$.
The remainder is $r$.

We need to compare $u_{k-1}$ and $r$.
Since $r < u_{k-1}$, the value $u_{k-1}$ is always greater than $r$.

This implies that the maximum remainder is always $u_{k-1}$.
This is achieved by picking $A_i = u_{k-1}$ and $A_j = u_k$.
The remainder is $u_{k-1} \pmod{u_k} = u_{k-1}$.

Let's re-verify the logic.
We want to maximize $A_i \pmod{A_j}$ where $A_i \neq A_j$.
Let the distinct elements be $u_1 < u_2 < \dots < u_k$.

If $k=1$, answer is 0.

If $k \ge 2$:
We are looking for $\max \{ u_a \pmod{u_b} \mid 1 \le a, b \le k, a \neq b \}$.

Consider any pair $(u_a, u_b)$ with $a \neq b$.
The remainder $u_a \pmod{u_b}$ is always $< u_b$.

Let's consider the largest possible value for $u_b$.
If $u_b = u_k$ (the largest distinct element):
Then $u_a$ must be some $u_a$ with $a < k$.
$u_a \pmod{u_k} = u_a$.
The maximum value of $u_a$ for $a < k$ is $u_{k-1}$.
So, the maximum remainder when $A_j = u_k$ is $u_{k-1}$.

If $u_b = u_{k-1}$ (the second largest distinct element):
Then $u_a$ can be any other distinct element.
If $u_a = u_k$, we get $u_k \pmod{u_{k-1}}$. Let this be $r_1$. We know $r_1 < u_{k-1}$.
If $u_a = u_a'$ where $a' < k-1$, we get $u_{a'} \pmod{u_{k-1}} = u_{a'}$. The maximum value here is $u_{k-2}$.

If $u_b = u_p$ where $p < k-1$:
Then $u_a$ can be any other distinct element.
If $u_a = u_k$, we get $u_k \pmod{u_p}$. Let this be $r_2$. We know $r_2 < u_p$.
Since $u_p < u_{k-1}$, we have $r_2 < u_p < u_{k-1}$.
If $u_a = u_{k-1}$, we get $u_{k-1} \pmod{u_p}$. Let this be $r_3$. We know $r_3 < u_p < u_{k-1}$.
If $u_a = u_{a'}$ where $a' < p$, we get $u_{a'} \pmod{u_p} = u_{a'}$. The maximum here is $u_{p-1}$.

Comparing all possibilities:
The maximum remainder when $A_j = u_k$ is $u_{k-1}$.
The maximum remainder when $A_j = u_{k-1}$ is $\max(u_k \pmod{u_{k-1}}, u_{k-2})$. Since $u_k \pmod{u_{k-1}} < u_{k-1}$ and $u_{k-2} < u_{k-1}$, the maximum is at most $u_{k-1}$.
The maximum remainder when $A_j = u_p$ ($p < k-1$) is $\max(u_k \pmod{u_p}, u_{k-1} \pmod{u_p}, \dots)$. All these remainders are strictly less than $u_p$, and $u_p < u_{k-1}$. So, these are all less than $u_{k-1}$.

Therefore, the maximum possible remainder is indeed $u_{k-1}$, which is the second largest distinct element. This is achieved by taking $A_i = u_{k-1}$ and $A_j = u_k$.

The solution strategy is:
1. Read all $N$ elements.
2. Store the distinct elements in a data structure that keeps them sorted, like `std::set`.
3. If the size of the set is 1, print 0.
4. If the size of the set is greater than 1, get the second largest element from the set and print it.

To get the second largest element from a sorted `std::set`:
- `set.rbegin()` gives a reverse iterator to the largest element.
- Incrementing this reverse iterator (`++set.rbegin()`) gives a reverse iterator to the second largest element.
- Dereferencing this iterator (`*++set.rbegin()`) gives the value of the second largest element.

Let's consider the constraints. $N$ can be up to $10^5$. Values of $A_i$ can be up to $10^9$.
Using `std::set` to store distinct elements is efficient. Insertion into a set takes $O(\log S)$ time, where $S$ is the current size of the set. For $N$ elements, this is $O(N \log N)$ in the worst case if all elements are distinct.
Retrieving the second largest element from a set is $O(1)$ after the set is built.

The problem statement mentions: "Using namespace std; is requested by the problem instructions." and "Fast I/O is requested by the problem instructions."

The code provided in the prompt implements exactly this logic.
It uses `std::set` to store distinct elements.
It checks `distinct_elements.size()`.
If size is 1, prints 0.
If size > 1, it uses `distinct_elements.rbegin()` and increments it to get the second largest element.

The code seems correct and follows the derived logic.

```cpp
#include <iostream> // Required for cin, cout
#include <set>      // For std::set to store unique sorted elements

// Using namespace std; is requested by the problem instructions.
using namespace std;

int main() {
    // Fast I/O is requested by the problem instructions.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description and sample inputs indicate a single test case.
    // No 'T' for the number of test cases is provided in the problem statement or sample.

    int N;
    cin >> N; // Read the number of elements

    set<int> distinct_elements; // Use a set to automatically store unique elements in sorted order
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element
        distinct_elements.insert(A_i); // Insert into the set
    }

    // After inserting all elements, 'distinct_elements' will contain
    // all unique values from the input array A, sorted in ascending order.

    // Case 1: If there is only one distinct element in the array.
    // This implies all elements A_i are identical (e.g., {5, 5, 5}).
    // In this case, A_i % A_j will always be A_1 % A_1 = 0.
    // The problem states N >= 2, so distinct_elements.size() will be at least 1.
    if (distinct_elements.size() == 1) {
        cout << 0 << "\n";
    } else {
        // Case 2: If there are at least two distinct elements.
        // The maximum value of A_i % A_j is the second largest distinct element.
        // This is proven in the detailed explanation above.

        // To get the second largest distinct element from a sorted set:
        // std::set::rbegin() returns a reverse iterator pointing to the largest element.
        // Incrementing this reverse iterator (it++) moves it to the next element in reverse order,
        // which is the second largest element.
        auto it = distinct_elements.rbegin(); // 'it' points to the largest element (M1)
        ++it;                                 // 'it' now points to the second largest element (M2)
        cout << *it << "\n";                  // Dereference to get the value of M2
    }

    return 0; // Indicate successful execution
}
```

The code is clean and directly implements the logic. The comments explain the reasoning well.

Final check on the logic:
Let distinct elements be $u_1 < u_2 < \dots < u_k$.
We want to maximize $u_a \pmod{u_b}$ for $a \neq b$.

Consider $u_b = u_k$ (largest).
$u_a \pmod{u_k} = u_a$ for $a < k$. Max is $u_{k-1}$.

Consider $u_b = u_{k-1}$ (second largest).
$u_k \pmod{u_{k-1}} = r_1$, where $r_1 < u_{k-1}$.
$u_a \pmod{u_{k-1}} = u_a$ for $a < k-1$. Max is $u_{k-2}$.
So, max for $u_b = u_{k-1}$ is $\max(r_1, u_{k-2})$. Since $r_1 < u_{k-1}$ and $u_{k-2} < u_{k-1}$, the max is at most $u_{k-1}$.

Consider $u_b = u_p$ ($p < k-1$).
$u_k \pmod{u_p} = r_2$, where $r_2 < u_p$.
$u_{k-1} \pmod{u_p} = r_3$, where $r_3 < u_p$.
$u_a \pmod{u_p} = u_a$ for $a < p$. Max is $u_{p-1}$.
All these remainders are $< u_p$. Since $u_p < u_{k-1}$, all these are $< u_{k-1}$.

So, the maximum value is indeed $u_{k-1}$.

The solution is correct.

## Complexity Analysis

- **Time Complexity**:
    - Reading $N$ integers: $O(N)$.
    - Inserting $N$ integers into a `std::set`: In the worst case, all $N$ elements are distinct. Each insertion into a `std::set` takes $O(\log S)$ time, where $S$ is the current number of elements in the set. The maximum size of the set is $N$. Therefore, the total time for insertions is $O(N \log N)$.
    - Accessing the second largest element from the set: `rbegin()` and incrementing it are $O(1)$ operations.
    - Printing the result: $O(1)$.
    - Overall time complexity is dominated by the set insertions: $O(N \log N)$.

- **Space Complexity**:
    - The `std::set` stores the distinct elements. In the worst case, all $N$ elements are distinct.
    - Therefore, the space complexity is $O(N)$ to store the distinct elements.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <set>      // For std::set to store unique sorted elements

// Using namespace std; is requested by the problem instructions.
using namespace std;

int main() {
    // Fast I/O is requested by the problem instructions.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description and sample inputs indicate a single test case.
    // No 'T' for the number of test cases is provided in the problem statement or sample.

    int N;
    cin >> N; // Read the number of elements

    set<int> distinct_elements; // Use a set to automatically store unique elements in sorted order
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element
        distinct_elements.insert(A_i); // Insert into the set
    }

    // After inserting all elements, 'distinct_elements' will contain
    // all unique values from the input array A, sorted in ascending order.

    // Case 1: If there is only one distinct element in the array.
    // This implies all elements A_i are identical (e.g., {5, 5, 5}).
    // In this case, A_i % A_j will always be A_1 % A_1 = 0.
    // The problem states N >= 2, so distinct_elements.size() will be at least 1.
    if (distinct_elements.size() == 1) {
        cout << 0 << "\n";
    } else {
        // Case 2: If there are at least two distinct elements.
        // The maximum value of A_i % A_j is the second largest distinct element.
        // This is proven in the detailed explanation above.
        // The maximum remainder is achieved by picking A_i to be the second largest
        // distinct element and A_j to be the largest distinct element.
        // The remainder is (second_largest) % (largest) = second_largest,
        // because second_largest < largest.

        // To get the second largest distinct element from a sorted set:
        // std::set::rbegin() returns a reverse iterator pointing to the largest element.
        // Incrementing this reverse iterator (it++) moves it to the next element in reverse order,
        // which is the second largest element.
        auto it = distinct_elements.rbegin(); // 'it' points to the largest element (M1)
        ++it;                                 // 'it' now points to the second largest element (M2)
        cout << *it << "\n";                  // Dereference to get the value of M2
    }

    return 0; // Indicate successful execution
}
```