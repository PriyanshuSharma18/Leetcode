class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // Array to count the number of 1s at each bit position (31 bits for 32-bit integers)
        int bitCount[31] = {0}; 

        // Iterate over each number in the candidates vector
        for (int num : candidates) {
            // Check each bit position from 0 to 30
            for (int i = 0; i < 31; i++) {
                // If the ith bit is set (1) in the current number, increment the count
                if (num & (1 << i)) {
                    bitCount[i]++;
                }
            }
        }

        // Find the maximum count across all bit positions
        return *max_element(bitCount, bitCount + 31);
    }
};