#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        // Min-heap to store pairs of (value, index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Add all elements with their indices to the heap
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        // Perform k modifications
        while (k-- > 0) {
            auto [val, idx] = pq.top(); // Get the smallest value and its index
            pq.pop(); // Remove it from the heap

            nums[idx] = val * multiplier; // Update the value in the array
            pq.push({nums[idx], idx}); // Push the updated value back to the heap
        }

        return nums; // Return the modified array
    }
};