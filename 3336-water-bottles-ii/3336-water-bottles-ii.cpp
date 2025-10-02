class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles, numEmptyBottles = numBottles;
        numBottles = 0;
        while (numBottles || numEmptyBottles >= numExchange) {
            if (numEmptyBottles >= numExchange) {
                numEmptyBottles -= numExchange++;
                ++numBottles;
                continue;
            }
            numEmptyBottles += numBottles;
            ans += numBottles;
            numBottles = 0;
        }
        return ans;
    }
};