class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        const int n=nums.size();
        vector<int> ans(n, -1);

        for (int i=0; i<n; i++) {
            unsigned p=nums[i];
            if (p==2) continue;
            ans[i]=p&~(((p+1)& -(p+1))>>1);
        }
        return ans;
    }
};