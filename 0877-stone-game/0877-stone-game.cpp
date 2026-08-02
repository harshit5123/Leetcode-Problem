class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        return true;
        /*There are an equal number of even-indexed and odd-indexed piles.

Before the game starts, Alice computes:

Sum of stones at even indices.
Sum of stones at odd indices.

She chooses whichever sum is larger.

Now observe:

Initially, the two ends have opposite parity.
On every turn, Alice can always choose a pile of her desired parity.
Bob cannot stop this.

Thus Alice guarantees herself all piles of either the even positions or the odd
positions, whichever has the larger total.

Since the total number of stones is odd, these two sums cannot be equal.

Therefore Alice always gets more stones.
*/
    }
};