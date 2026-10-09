#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        // The parity of the final number depends on the parity of the initial number
        // and the total number of moves.
        // Each move changes the parity of the number.
        // If Y is even, the parity of the final number will be the same as the initial number.
        // If Y is odd, the parity of the final number will be different from the initial number.

        // Janmansh wins if the final number is even.
        // Jay wins if the final number is odd.

        // Let's analyze the parity of the final number.
        // Initial number X.
        // After 1 move: X+1 or X-1. Parity flips.
        // After 2 moves: Parity flips back to original.
        // After Y moves:
        // If Y is even, the parity of the final number is the same as X.
        // If Y is odd, the parity of the final number is different from X.

        // Case 1: X is even.
        // If Y is even, final number parity is even. Janmansh wins.
        // If Y is odd, final number parity is odd. Jay wins.

        // Case 2: X is odd.
        // If Y is even, final number parity is odd. Jay wins.
        // If Y is odd, final number parity is even. Janmansh wins.

        // This can be simplified:
        // The final number is even if (X is even AND Y is even) OR (X is odd AND Y is odd).
        // This is equivalent to saying X and Y have the same parity.
        // The final number is odd if (X is even AND Y is odd) OR (X is odd AND Y is even).
        // This is equivalent to saying X and Y have different parities.

        // However, the players play optimally.
        // The key observation is that each move flips the parity of X.
        // After Y moves, the parity of the final number will be:
        // initial_parity(X) XOR parity(Y)
        // where parity(Y) is 0 if Y is even, and 1 if Y is odd.

        // Let's re-evaluate the optimal play.
        // The players want to make the final number even (Janmansh) or odd (Jay).
        // The parity of the final number is determined by the parity of X and the parity of Y.
        // Specifically, final_parity = (X % 2 + Y % 2) % 2.
        // If Y is even, final_parity = X % 2.
        // If Y is odd, final_parity = (X % 2 + 1) % 2.

        // The players can always achieve the parity they want for the final number,
        // as long as they have moves left.
        // The crucial part is who makes the LAST move that determines the parity.

        // Let's consider the total number of moves Y.
        // Janmansh plays moves 1, 3, 5, ...
        // Jay plays moves 2, 4, 6, ...

        // If Y is even, the last move is made by Jay.
        // If Y is odd, the last move is made by Janmansh.

        // Consider the parity of X.
        // If X is even:
        // Janmansh wants the final number to be even.
        // Jay wants the final number to be odd.

        // If X is odd:
        // Janmansh wants the final number to be even.
        // Jay wants the final number to be odd.

        // Let's analyze the goal for each player based on the parity of X.
        // If X is even:
        //   Janmansh wants the final number to be even.
        //   Jay wants the final number to be odd.
        // If X is odd:
        //   Janmansh wants the final number to be even.
        //   Jay wants the final number to be odd.

        // The parity of the final number is determined by the parity of X and the parity of Y.
        // Final number parity = (X % 2 + Y % 2) % 2.
        // If Y is even, final parity = X % 2.
        // If Y is odd, final parity = (X % 2 + 1) % 2.

        // The players can always choose to increment or decrement.
        // This means they can always flip the parity of the current number.
        // The question is, can they force the final parity to be what they want?

        // Let's consider the parity of X.
        // If X is even:
        //   Janmansh wants the final number to be even.
        //   Jay wants the final number to be odd.
        //   If Y is even, the final parity will be even regardless of moves. Janmansh wins.
        //   If Y is odd, the final parity will be odd regardless of moves. Jay wins.

        // If X is odd:
        //   Janmansh wants the final number to be even.
        //   Jay wants the final number to be odd.
        //   If Y is even, the final parity will be odd regardless of moves. Jay wins.
        //   If Y is odd, the final parity will be even regardless of moves. Janmansh wins.

        // This implies that the optimal play doesn't matter for the final parity.
        // The final parity is solely determined by the initial parity of X and the parity of Y.

        // Let's verify this with the sample cases.
        // Sample 1: X=2 (even), Y=2 (even)
        // X is even, Y is even. Final parity should be even. Janmansh wins. Correct.

        // Sample 2: X=4 (even), Y=3 (odd)
        // X is even, Y is odd. Final parity should be odd. Jay wins. Correct.

        // Let's consider another case: X=3 (odd), Y=2 (even)
        // X is odd, Y is even. Final parity should be odd. Jay wins.
        // Let's trace: X=3.
        // Move 1 (Janmansh): can make it 2 (even) or 4 (even).
        // Move 2 (Jay):
        //   If current is 2: Jay can make it 1 (odd) or 3 (odd).
        //   If current is 4: Jay can make it 3 (odd) or 5 (odd).
        // In both scenarios, Jay can force an odd number.

        // Let's consider X=3 (odd), Y=3 (odd)
        // X is odd, Y is odd. Final parity should be even. Janmansh wins.
        // Let's trace: X=3.
        // Move 1 (Janmansh): can make it 2 (even) or 4 (even).
        // Move 2 (Jay):
        //   If current is 2: Jay can make it 1 (odd) or 3 (odd).
        //   If current is 4: Jay can make it 3 (odd) or 5 (odd).
        // Move 3 (Janmansh):
        //   If current is 1: Janmansh can make it 0 (even) or 2 (even).
        //   If current is 3: Janmansh can make it 2 (even) or 4 (even).
        //   If current is 5: Janmansh can make it 4 (even) or 6 (even).
        // In all scenarios, Janmansh can force an even number.

        // The logic seems to be:
        // The final parity is determined by the parity of X and the parity of Y.
        // If Y is even, the final parity is the same as X's parity.
        // If Y is odd, the final parity is the opposite of X's parity.

        // Janmansh wins if the final number is even.
        // Jay wins if the final number is odd.

        // Condition for Janmansh to win (final number is even):
        // (X is even AND Y is even) OR (X is odd AND Y is odd)
        // This is equivalent to (X % 2) == (Y % 2)

        // Condition for Jay to win (final number is odd):
        // (X is even AND Y is odd) OR (X is odd AND Y is even)
        // This is equivalent to (X % 2) != (Y % 2)

        if ((x % 2) == (y % 2)) {
            // X and Y have the same parity.
            // If X is even and Y is even, final is even. Janmansh wins.
            // If X is odd and Y is odd, final is odd. Jay wins.
            // Wait, this is wrong. The logic above was correct.

            // Let's re-state the final parity:
            // Final parity = (X % 2 + Y % 2) % 2
            // If Y is even, Y % 2 = 0. Final parity = X % 2.
            // If Y is odd, Y % 2 = 1. Final parity = (X % 2 + 1) % 2.

            // Janmansh wins if final parity is 0 (even).
            // Jay wins if final parity is 1 (odd).

            // If Y is even:
            //   Final parity = X % 2.
            //   If X is even (X % 2 == 0), final is even. Janmansh wins.
            //   If X is odd (X % 2 == 1), final is odd. Jay wins.
            //   So, if Y is even, Janmansh wins if X is even, Jay wins if X is odd.

            // If Y is odd:
            //   Final parity = (X % 2 + 1) % 2.
            //   If X is even (X % 2 == 0), final is (0 + 1) % 2 = 1 (odd). Jay wins.
            //   If X is odd (X % 2 == 1), final is (1 + 1) % 2 = 0 (even). Janmansh wins.
            //   So, if Y is odd, Jay wins if X is even, Janmansh wins if X is odd.

            // Combining these:
            // Janmansh wins if:
            //   (Y is even AND X is even) OR (Y is odd AND X is odd)
            // This is equivalent to: (Y % 2 == 0 && X % 2 == 0) || (Y % 2 == 1 && X % 2 == 1)
            // Which simplifies to: (X % 2) == (Y % 2)

            // Jay wins if:
            //   (Y is even AND X is odd) OR (Y is odd AND X is even)
            // This is equivalent to: (Y % 2 == 0 && X % 2 == 1) || (Y % 2 == 1 && X % 2 == 0)
            // Which simplifies to: (X % 2) != (Y % 2)

            // The logic that the final parity is determined by the parity of X and Y is correct.
            // The optimal play doesn't change this outcome because each player can always flip the parity.
            // The player who makes the last move (determined by Y) can ensure the final parity.
            // However, the problem states that the final number is determined by Y moves.
            // The parity of the final number is fixed by the initial parity and the number of moves.

            // Let's re-read the problem carefully.
            // "If the final number after performing Y moves is even, then Janmansh wins otherwise, Jay wins."
            // "both the players play optimally."

            // The key is that players can increment or decrement.
            // This means they can always change the parity.
            // The question is, can they *force* the final parity to be what they want?

            // Consider the parity of X.
            // If X is even:
            //   Janmansh wants the final number to be even.
            //   Jay wants the final number to be odd.
            // If X is odd:
            //   Janmansh wants the final number to be even.
            //   Jay wants the final number to be odd.

            // Let's consider the number of moves Y.
            // If Y is even, Janmansh makes moves 1, 3, ..., Y-1. Jay makes moves 2, 4, ..., Y. Jay makes the last move.
            // If Y is odd, Janmansh makes moves 1, 3, ..., Y. Jay makes moves 2, 4, ..., Y-1. Janmansh makes the last move.

            // If X is even:
            //   Janmansh wants final even. Jay wants final odd.
            //   If Y is even (Jay makes last move):
            //     Jay can always ensure the final number is odd.
            //     Example: X=2, Y=2.
            //     Move 1 (Janmansh): 2 -> 3 (odd).
            //     Move 2 (Jay): 3 -> 2 (even) or 3 -> 4 (even). Jay wants odd, but can only make even.
            //     This contradicts the sample explanation.
            //     Sample 1: X=2, Y=2. Janmansh wins.
            //     Explanation: Janmansh increases X to 3. Jay increases X to 4. Final is 4 (even). Janmansh wins.
            //     Here, Janmansh made X odd. Jay made X even.
            //     The explanation says "one of the optimal games".

            // Let's rethink the goal.
            // The goal is to make the final number even (Janmansh) or odd (Jay).
            // Each move flips the parity.
            // After Y moves, the parity of the final number is initial_parity XOR (Y % 2).
            // This is because each move flips the parity.
            // If Y is even, the parity flips an even number of times, so it returns to the original parity.
            // If Y is odd, the parity flips an odd number of times, so it ends up as the opposite parity.

            // So, the final parity is indeed determined by X and Y.
            // Final parity = (X % 2 + Y % 2) % 2.
            // If Y is even, final parity = X % 2.
            // If Y is odd, final parity = (X % 2 + 1) % 2.

            // Janmansh wins if final parity is 0.
            // Jay wins if final parity is 1.

            // Let's check the conditions for Janmansh to win (final parity is 0):
            // Case 1: Y is even.
            //   Final parity = X % 2.
            //   For final parity to be 0, X % 2 must be 0. So X must be even.
            //   Condition: Y is even AND X is even.

            // Case 2: Y is odd.
            //   Final parity = (X % 2 + 1) % 2.
            //   For final parity to be 0, (X % 2 + 1) % 2 must be 0.
            //   This means X % 2 + 1 must be odd.
            //   This means X % 2 must be even (0). So X must be even.
            //   Wait, if X is odd (X % 2 = 1), then (1 + 1) % 2 = 0. So X must be odd.
            //   Condition: Y is odd AND X is odd.

            // So, Janmansh wins if (Y is even AND X is even) OR (Y is odd AND X is odd).
            // This is equivalent to saying X and Y have the same parity.
            // (X % 2) == (Y % 2)

            // Let's re-check sample cases with this logic.
            // Sample 1: X=2 (even), Y=2 (even). X%2 == Y%2. Janmansh wins. Correct.
            // Sample 2: X=4 (even), Y=3 (odd). X%2 != Y%2. Jay wins. Correct.

            // Let's consider the optimal play aspect again.
            // If the final parity is fixed, why is optimal play mentioned?
            // Perhaps the players can choose to reach *any* number with the desired parity.
            // But the problem states "increment or decrement X by 1".
            // This means the change in X is always +/- 1.
            // The total change in X after Y moves is sum of Y terms, each +/- 1.
            // Let the changes be d1, d2, ..., dY, where di is +1 or -1.
            // Final X = Initial X + sum(di).
            // The parity of Final X = Parity(Initial X) + Parity(sum(di)).
            // Parity(sum(di)) = Parity(number of +1s - number of -1s).
            // Let p be the number of +1 moves and m be the number of -1 moves.
            // p + m = Y.
            // sum(di) = p - m.
            // Parity(sum(di)) = Parity(p - m).
            // p - m = p - (Y - p) = 2p - Y.
            // Parity(2p - Y) = Parity(-Y) = Parity(Y).
            // So, Parity(Final X) = Parity(Initial X) + Parity(Y).
            // This confirms the final parity is determined by X and Y.

            // The optimal play might be relevant if there were multiple ways to achieve a certain parity,
            // and one way was better for the player. But here, any move flips parity.
            // The players don't have a choice that affects the final parity outcome.
            // The outcome is predetermined by X and Y.

            // So, if X and Y have the same parity, Janmansh wins.
            // If X and Y have different parities, Jay wins.

            std::cout << "Janmansh\n";
        } else {
            // X and Y have different parities.
            // If X is even and Y is odd, final is odd. Jay wins.
            // If X is odd and Y is even, final is even. Janmansh wins.
            // Wait, this is wrong.
            // Let's re-derive the winning conditions for Janmansh.
            // Janmansh wins if final number is even.
            // Final parity = (X % 2 + Y % 2) % 2.
            // We want (X % 2 + Y % 2) % 2 == 0.

            // This happens when:
            // 1. X % 2 == 0 AND Y % 2 == 0 (both even)
            // 2. X % 2 == 1 AND Y % 2 == 1 (both odd)

            // So, Janmansh wins if X and Y have the same parity.
            // (X % 2) == (Y % 2)

            // If X and Y have different parities, then (X % 2 + Y % 2) % 2 == 1, which means the final number is odd.
            // In this case, Jay wins.

            // The logic seems solid.
            // If (X % 2) == (Y % 2), Janmansh wins.
            // Otherwise, Jay wins.

            std::cout << "Jay\n";
        }
    }
    return 0;
}