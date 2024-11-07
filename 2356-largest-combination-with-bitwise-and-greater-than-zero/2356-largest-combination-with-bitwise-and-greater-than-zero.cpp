#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCount = 0;

        // Check each bit position up to 32 bits
        for (int bit = 0; bit < 32; bit++) {
            int count = 0;

            // Count how many numbers have the current bit set
            for (int num : candidates) {
                if ((num & (1 << bit)) != 0) {
                    count++;
                }
            }

            // Update maxCount to store the maximum count of numbers with the same bit set
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};