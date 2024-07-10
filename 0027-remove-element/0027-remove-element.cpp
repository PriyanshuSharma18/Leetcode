class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (int n : nums) {
            if (n != val) {
                nums[res++] = n;
            }
        }
        return res;
    }
};