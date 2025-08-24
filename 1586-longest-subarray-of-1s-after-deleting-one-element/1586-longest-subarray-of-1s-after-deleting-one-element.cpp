class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        map<int, int> left, right;
        int cnt = 0, ones = 0;

        // Calculate left consecutive ones before each 0
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
                ones++;
            } else {
                left[i] = cnt;
                cnt = 0;
            }
        }

        // Edge cases
        if (ones == 0) return 0;                     // No 1s
        if (ones == nums.size()) return nums.size() - 1;  // All 1s

        cnt = 0;

        // Calculate right consecutive ones after each 0
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                right[i] = cnt;
                cnt = 0;
            }
        }

        // Calculate max combined length
        int maxi = cnt;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                maxi = max(maxi, left[i] + right[i]);
            }
        }

        return maxi;
    }
};