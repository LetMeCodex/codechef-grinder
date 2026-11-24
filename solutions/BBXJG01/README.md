# [Chef Builds Stack (BBXJG01)](https://www.codechef.com/problems/BBXJG01)
- **Difficulty Rating**: 1050
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem requires us to implement a `StackUsingQueues` class that mimics the behavior of a Last-In, First-Out (LIFO) stack data structure. The constraint is that we can only use `std::queue` (which is a First-In, First-Out (FIFO) data structure) as the underlying storage. The class must support the following four standard stack operations:
1.  `push(x)`: Adds element `x` to the top of the stack.
2.  `pop()`: Removes and returns the top element of the stack.
3.  `top()`: Returns the top element of the stack without removing it.
4.  `empty()`: Returns `true` if the stack is empty, `false` otherwise.

The problem statement guarantees that `pop()` and `top()` operations will only be called on non-empty stacks, simplifying error handling.

## Intuition & Mathematical Observation
The core challenge is to achieve LIFO behavior using FIFO queues. There are two common strategies to implement a stack using two queues:

1.  **Making `push` operation costly (the approach used in the solution):**
    *   **Idea:** Ensure that the most recently pushed element is always at the front of one of the queues, so `pop()` and `top()` can be $O(1)$.
    *   **Mechanism:** We use two queues, `q1` and `q2`. `q2` will always store the elements in the correct LIFO order, with the top element at its front.
    *   When a new element `x` is `push`ed:
        1.  Add `x` to `q1`.
        2.  Move all existing elements from `q2` to `q1`. This effectively places `x` at the front of `q1`, followed by all previously existing stack elements in their original LIFO order.
        3.  Swap `q1` and `q2`. Now, `q2` contains `x` at its front (the new top of the stack), and `q1` becomes empty, ready for the next `push`.
    *   `pop()` and `top()` simply access `q2.front()` and `q2.pop()`, which are $O(1)$ operations because `q2` is always maintained in the correct LIFO order.

2.  **Making `pop`/`top` operations costly:**
    *   **Idea:** Simply push elements into one queue. When `pop` or `top` is called, move all elements except the last one to a temporary queue, then process the last element, and finally move elements back.
    *   **Mechanism:** Elements are simply pushed into one queue (say `q1`). When `pop` or `top` is called, all elements except the last one are moved from `q1` to `q2`. The last remaining element in `q1` is the actual top of the stack. This element is then returned/removed, and finally, all elements are moved back from `q2` to `q1` to restore the state. This makes `pop`/`top` $O(N)$ and `push` $O(1)$.

The provided solution code implements the **first strategy (costly `push`)**. This approach is often chosen when `pop` and `top` operations are expected to be more frequent or require faster access than `push`.

**Example Trace for `push` (Costly Push Strategy):**
Let's trace the `push` operation:
Initial state: `q1 = []`, `q2 = []` (Stack is empty)

1.  `push(10)`:
    *   `q1.push(10)` $\rightarrow$ `q1 = [10]`, `q2 = []`
    *   `q2` is empty, so no elements are moved from `q2` to `q1`.
    *   `std::swap(q1, q2)` $\rightarrow$ `q1 = []`, `q2 = [10]`
    *   Stack conceptually: `[10]` (top is 10)

2.  `push(20)`:
    *   `q1.push(20)` $\rightarrow$ `q1 = [20]`, `q2 = [10]`
    *   Move elements from `q2` to `q1`:
        *   `q1.push(q2.front())` (10) $\rightarrow$ `q1 = [20, 10]`, `q2 = []`
    *   `std::swap(q1, q2)` $\rightarrow$ `q1 = []`, `q2 = [20, 10]`
    *   Stack conceptually: `[20, 10]` (top is 20)

3.  `push(30)`:
    *   `q1.push(30)` $\rightarrow$ `q1 = [30]`, `q2 = [20, 10]`
    *   Move elements from `q2` to `q1`:
        *   `q1.push(20)` $\rightarrow$ `q1 = [30, 20]`, `q2 = [10]`
        *   `q1.push(10)` $\rightarrow$ `q1 = [30, 20, 10]`, `q2 = []`
    *   `std::swap(q1, q2)` $\rightarrow$ `q1 = []`, `q2 = [30, 20, 10]`
    *   Stack conceptually: `[30, 20, 10]` (top is 30)

Now, if we call `pop()`:
*   `q2.front()` returns `30`.
*   `q2.pop()` removes `30`.
*   `q2` becomes `[20, 10]`.
*   Returns `30`. Stack conceptually: `[20, 10]` (top is 20)

This trace clearly demonstrates how the LIFO behavior is maintained.

## Complexity Analysis
Let $N$ be the number of elements currently in the stack.

*   **Time Complexity**:
    *   `push(x)`: This operation involves pushing `x` to `q1` ($O(1)$), then moving all $N$ elements from `q2` to `q1` ($N$ `pop` operations from `q2` and $N$ `push` operations to `q1`, each $O(1)$), and finally a `std::swap` ($O(1)$). Therefore, the `push` operation takes $O(N)$ time in the worst case.
    *   `pop()`: This involves a single `front()` and a single `pop()` operation on `q2`, both of which are $O(1)$. So, `pop()` takes $O(1)$ time.
    *   `top()`: This involves a single `front()` operation on `q2`, which is $O(1)$. So, `top()` takes $O(1)$ time.
    *   `empty()`: This involves a single `empty()` check on `q2`, which is $O(1)$. So, `empty()` takes $O(1)$ time.

*   **Space Complexity**:
    *   The two queues, `q1` and `q2`, together store all $N$ elements of the stack. At any point, one queue might hold all $N$ elements while the other is empty (e.g., immediately after a `push` and `swap`). Therefore, the space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream> // For input/output operations (e.g., std::cout, std::cin)
#include <queue>    // For std::queue container
#include <string>   // For std::string (though not strictly used in the class itself)
#include <vector>   // Not strictly needed for the class itself, but often included.

// Define the StackUsingQueues class
class StackUsingQueues {
private:
    // q1 is used as a temporary queue during push operations.
    std::queue<int> q1;
    // q2 always holds the elements of the stack in LIFO order,
    // with the top element at its front.
    std::queue<int> q2;

public:
    // Pushes the element x onto the top of the stack.
    void push(int x) {
        // Step 1: Push the new element 'x' to q1.
        // q1 will temporarily hold the new element.
        q1.push(x);

        // Step 2: Move all existing elements from q2 to q1.
        // This ensures that 'x' (the newest element) is now at the front of q1,
        // followed by all previous stack elements in their original LIFO order.
        while (!q2.empty()) {
            q1.push(q2.front()); // Move element from q2 to q1
            q2.pop();            // Remove element from q2
        }

        // Step 3: Swap q1 and q2.
        // Now, q2 contains all elements with 'x' at its front (the new top).
        // q1 becomes empty, ready for the next push operation.
        std::swap(q1, q2);
    }

    // Removes and returns the top element of the stack.
    // Constraints guarantee pop() is valid, so q2 will not be empty.
    int pop() {
        // The top element is always at the front of q2.
        int top_element = q2.front();
        q2.pop(); // Remove the top element.
        return top_element;
    }

    // Returns the top element of the stack without removing it.
    // Constraints guarantee top() is valid, so q2 will not be empty.
    int top() {
        // The top element is always at the front of q2.
        return q2.front();
    }

    // Returns true if the stack is empty, otherwise returns false.
    bool empty() {
        // The stack is empty if q2 is empty.
        return q2.empty();
    }
};

// The main function provided in the problem description is for local testing.
// For submission to CodeChef, only the class definition is required,
// as the platform provides its own main function to test your class.
/*
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        StackUsingQueues stack;
        for (int i = 0; i < n; ++i) {
            std::string operation;
            std::cin >> operation;
            if (operation == "push") {
                int x;
                std::cin >> x;
                stack.push(x);
                std::cout << "None\n";
            } else if (operation == "pop") {
                std::cout << stack.pop() << "\n";
            } else if (operation == "top") {
                std::cout << stack.top() << "\n";
            } else if (operation == "empty") {
                std::cout << (stack.empty() ? "true" : "false") << "\n";
            }
        }
    }
    return 0;
}
*/
```